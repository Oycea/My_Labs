#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<locale.h>
#include"frequency_analysis.h"
#include"decrypt.h"
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
	int k = 0;
	double count_symbol[77] = { 0 };
	double symbols_frequency[77] = { 0 };

	FILE* encrypted_text, * decrypted_text;

	if (check_argument_input(num_of_arg) == 0)
		return 1;

	encrypted_text = fopen(argv[1], "r");//Исходный текст
	if (check_file_existence(encrypted_text) == 0)
		return 1;

	//Частотный анализ всех символов
	frequency_of_symbol(encrypted_text, count_symbol, symbols_frequency);
	fclose(encrypted_text);
	encrypted_text = fopen(argv[1], "r");
	k = search_for_shift(count_symbol);
	fclose(encrypted_text);

	encrypted_text = fopen(argv[1], "r");
	decrypted_text = fopen("GushchinaDecrypt1.txt", "w");
	decrypt_Caesars_decipher(encrypted_text, decrypted_text, k); //Дешифровка
	fclose(encrypted_text);
	fclose(decrypted_text);

	encrypted_text = fopen(argv[1], "r");
	decrypted_text = fopen("GushchinaDecrypt2.txt", "w");
	decrypt_keyboard_decipher(encrypted_text, decrypted_text); //Дешифровка
	fclose(encrypted_text);
	fclose(decrypted_text);

	system("pause");
	return 0;
}