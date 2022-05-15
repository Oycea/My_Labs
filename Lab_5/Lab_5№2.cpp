// ������� ��������� ���13 - ��
//������������ ������ �5. �����������, �������������, ��������� ������
//
//������� 2. ��������� ������
//������� 16. �������� ��������� ������ ��������, �.�.��������, ������� ��� ����������� ������ ������ � ������.
//���������� ��������� ������, ����� ����������, ��������� � �������� ����� �������� ��������.��� ������� ������� 
//����� ������� ������� ��� ��������� � ������. ���������� ��� �������� ����� ������������� ����� ����������.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<locale.h>
#include"frequency_analysis.h"
using namespace std;

//�������� �������� ������ �����
bool check_argument_input(int num_of_arg) {
	if (num_of_arg <= 1) {
		cout << "No file to read.Try again";
		return 0;
	}
	return 1;
}

//�������� ������������� �����
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
	const char symbol_arr[] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
								'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
								'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
								'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
								'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
								'�', '�', '�', '�', '�', '�', ' ', '.', ',', '?', ':', ';',
								'-', '(', ')', '!', '"' };
	FILE* text;

	if (check_argument_input(num_of_arg) == 0)
		return 1;

	text = fopen(argv[1], "r");//�������� �����
	if (check_file_existence(text) == 0)
		return 1;
	
	//��������� ������ ���� ��������
	frequency_of_symbol(text, count_symbol, symbols_frequency);
	fclose(text);
	cout << endl << "Frequency analysis of all symbol" << endl << endl;
	for (int i = 0; i < 77; i++) {
		cout << "Symbol " << symbol_arr[i] << " occurs " << count_symbol[i] << " ";
		cout << "with a frequency " << symbols_frequency[i] << endl << endl;
	}

	cout << endl << "The three most common punctuation marks" << endl << endl;

	//���������� ��� �������� ����� ������������� ����� ����������, �� ���������� �
	//������� �������
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