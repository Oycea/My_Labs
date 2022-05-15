//Гущиной Маргариты ПМИ13-БО
//ЛАБОРАТОРНАЯ РАБОТА №5. КОДИРОВАНИЕ, ДЕКОДИРОВАНИЕ, ЧАСТОТНЫЙ АНАЛИЗ
//
//Задание 1. Шифровка и дешифровка
//Вариант 1. Шифр Цезаря.Циклический сдвиг алфавита влево на 3 позиции.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<locale.h>
#include"encoding_func.h"
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
	FILE* original_text, * encrypted_text, * decrypted_text;

	if(check_argument_input(num_of_arg)==0)
		return 1;

	original_text = fopen(argv[1], "r");//Исходный текст
	if(check_file_existence(original_text)==0)
		return 1;

	encrypted_text = fopen("GushchinaCrypt.txt", "w"); //Зашифрованный текст

	crypt(original_text, encrypted_text); //Шифровка
	fclose(original_text);
	fclose(encrypted_text);
		
	encrypted_text = fopen("GushchinaCrypt.txt", "r");
	decrypted_text = fopen("GushchinaDecrypt.txt", "w");
	decrypt(encrypted_text, decrypted_text); //Дешифровка
	fclose(encrypted_text);
	fclose(decrypted_text);

	original_text = fopen(argv[1], "r");
	decrypted_text = fopen("GushchinaDecrypt.txt", "r");
	if (is_identity(original_text, decrypted_text) == 1)
		cout << "Encoding successful" << endl;
	else
		cout << "Error in coding" << endl; //Проверка правильности дешифровки
	fclose(original_text);
	fclose(decrypted_text);

	system("pause");
	return 0;
}
