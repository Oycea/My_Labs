// Гущиной Маргариты ПМИ13 - БО
//ЛАБОРАТОРНАЯ РАБОТА №5. КОДИРОВАНИЕ, ДЕКОДИРОВАНИЕ, ЧАСТОТНЫЙ АНАЛИЗ
//
//Задание 2. Частотный анализ
//Вариант 16. Провести частотный анализ символов, т.е.выяснить, сколько раз встречается каждый символ в тексте.
//Необходимо учитывать пробел, знаки препинания, прописные и строчные буквы русского алфавита.Для каждого символа 
//нужно вывести частоту его появления в тексте. Определить три наиболее часто встречающихся знака препинания.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<locale.h>
#include"frequency_analysis.h"
using namespace std;

//Проверка передачи адреса файла
bool check_argument_input(int num_of_arg) {
	if (num_of_arg <= 1) {
		cout << "No file to read.Try again";
		return 0;
	}
	return 1;
}

//Проверка существования файла
bool check_file_existence(FILE* file) {
	if (file == NULL) {
		cout << "File not found";
		return 0;
	}
	return 1;
}

int main(int argc, char* argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int num_of_arg = argc;
	int i_most_common[3] = { 0 };
	double count_symbol[77] = { 0 };
	double symbols_frequency[77] = { 0 };
	double punct_marks_frequency[10] = { 0 };
	const char symbol_arr[] = { 'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж', 'З', 'И', 'Й', 'К',
								'Л', 'М', 'Н', 'О', 'П', 'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц',
								'Ч', 'Ш', 'Щ', 'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я', 'а', 'б', 'в',
								'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н',
								'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ',
								'ъ', 'ы', 'ь', 'э', 'ю', 'я', ' ', '.', ',', '?', ':', ';',
								'-', '(', ')', '!', '"' };
	FILE* text;

	if (check_argument_input(num_of_arg) == 0)
		return 1;

	text = fopen(argv[1], "r");//Исходный текст
	if (check_file_existence(text) == 0)
		return 1;
	
	//Частотный анализ всех символов
	frequency_of_symbol(text, count_symbol, symbols_frequency);
	fclose(text);
	cout << endl << "Frequency analysis of all symbol" << endl << endl;
	for (int i = 0; i < 77; i++) {
		cout << "Symbol " << symbol_arr[i] << " occurs " << count_symbol[i] << " ";
		cout << "with a frequency " << symbols_frequency[i] << endl << endl;
	}

	cout << endl << "The three most common punctuation marks" << endl << endl;

	//Определить три наиболее часто встречающихся знака препинания, их количества и
	//средней частоты
	three_common_punct_marks(count_symbol, i_most_common);
	frequency_of_punct_marks(count_symbol, punct_marks_frequency);
	for (int i = 0; i < 3; i++) {
		int j = i_most_common[i];
		cout << i << ". Punctuation mark " << symbol_arr[j] << " occurs " << count_symbol[j];
		cout << " with a frequency " << punct_marks_frequency[j - 67] << endl << endl;
	}
	fclose(text);
	system("pause");
	return 0;
}
