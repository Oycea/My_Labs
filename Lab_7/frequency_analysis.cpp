#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<locale.h>
#include"frequency_analysis.h"
using namespace std;

const char symbol_arr[] = { 'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж', 'З', 'И', 'Й', 'К',
								'Л', 'М', 'Н', 'О', 'П', 'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц',
								'Ч', 'Ш', 'Щ', 'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я', 'а', 'б', 'в',
								'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н',
								'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ',
								'ъ', 'ы', 'ь', 'э', 'ю', 'я', ' ', '.', ',', '?', ':', ';',
								'-', '(', ')', '!', '"' };

//Количество каждого из символов
double frequency_of_symbol(FILE* file, double count_symbol[77], double symbols_frequency[77]) {
	int idx = 0;
	double total_count_symbol = 0;
	char symbol;
	symbol = getc(file);
	while (!feof(file)) {
		total_count_symbol++;
		for (int k = 0; k < 77; k++)
			if (symbol == symbol_arr[k]) {
				count_symbol[k]++;
				break;
			}
		symbol = getc(file);
	}
	for (int i = 0; i < 77; i++) {
		symbols_frequency[idx] = count_symbol[i] / total_count_symbol;
		idx++;
	}
	return symbols_frequency[77];
}

//Общее количество знаков препинания
double count_punct_marks(double count_symbol[77]) {
	int total_count_mark = 0;
	for (int i = 67; i < 77; i++)
		total_count_mark += count_symbol[i];
	return total_count_mark;
}

//Средняя частота для каждого из знаков препинания
double frequency_of_punct_marks(double count_symbol[77], double punct_marks_frequency[10]) {
	double total_count_mark = count_punct_marks(count_symbol);
	int idx = 0;
	for (int i = 67; i < 77; i++) {
		punct_marks_frequency[idx] = count_symbol[i] / total_count_mark;
		idx++;
	}
	return punct_marks_frequency[10];
}

//Три самых часто встречаемых знака препинания
int three_common_punct_marks(double count_symbol[77], int i_most_common[3]) {
	int max = 0, imax = 0, idx = 0;
	double count_most_common[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		for (int j = 67; j < 77; j++) //Номера знаков препинания в алфавите
			if (count_symbol[j] > max) {
				max = count_symbol[j];
				imax = j;
			}
		i_most_common[idx] = imax;
		count_most_common[idx] = count_symbol[imax];
		max = 0;
		count_symbol[imax] = 0;
		imax = 0;
		idx++;
	}
	for (int i = 0; i < 3; i++)
		count_symbol[i_most_common[i]] = count_most_common[i];
	return i_most_common[3];
}

//Поиск сдвига алфавита
int search_for_shift(double count_symbol[77]) {
	int max = 0, imax = 0, idx = 0, i_most_common = 0, k = 0;
	for (int j = 0; j < 66; j++)
		if (count_symbol[j] > max) {
			max = count_symbol[j];
			imax = j;
		}
	i_most_common = imax;
	k = -48 + imax;
	return k;
}