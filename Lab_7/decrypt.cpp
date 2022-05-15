#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<locale.h>
#include"decrypt.h"
using namespace std;
const char symbol_arr[] = { 'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж', 'З', 'И', 'Й', 'К',
							'Л', 'М', 'Н', 'О', 'П', 'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц',
							'Ч', 'Ш', 'Щ', 'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я', 'а', 'б', 'в',
							'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н',
							'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ',
							'ъ', 'ы', 'ь', 'э', 'ю', 'я', ' ', '.', ',', '?', ':', ';',
							'-', '(', ')', '!', '"' };
const char keyboard_symbol_arr[] = { 'Й', 'Ц', 'У', 'К', 'Е', 'Н', 'Г', 'Ш', 'Щ', 'З', 'Х', 'Ъ',
									 'Ф', 'Ы', 'В', 'А', 'П', 'Р', 'О', 'Л', 'Д', 'Ж', 'Э', 'Я',
									 'Ч', 'С', 'М', 'И', 'Т', 'Ь', 'Ь', 'Б', 'Ю', 'й', 'ц', 'у',
									 'к', 'е', 'н', 'г', 'ш', 'щ', 'з', 'х', 'ъ', 'ф', 'ы', 'в',
									 'а', 'п', 'р', 'о', 'л', 'д', 'ж', 'э', 'я', 'ч', 'с', 'м',
									 'и', 'т', 'ь', 'б', 'ю' };

//Дешифровка по шифру Цезаря
char Caesars_decipher(char letter, int k) {
	if (letter >= 'А' && letter <= 'Я')
		letter = ((letter - 'А' - k + 32) % 32) + 'А';
	else if (letter >= 'а' && letter <= 'я')
		letter = ((letter - 'а' - k + 32) % 32) + 'а';
	return letter;
}

//Дешифровка шифра по порядку букв на клавиатуре (сдвиг влево)
char keyboard_decipher(char letter) {
	if (letter == keyboard_symbol_arr[32])
		letter = keyboard_symbol_arr[0];
	else if (letter == keyboard_symbol_arr[64])
		letter = keyboard_symbol_arr[33];
	else
		for (int i = 0; i < 65; i++)
			if (letter == keyboard_symbol_arr[i]) {
				letter = keyboard_symbol_arr[i + 1];
				break;
			}
	return letter;
}

//Дешифровка файла с шифром Цезаря
void decrypt_Caesars_decipher(FILE* encrypted_text, FILE* decrypted_text, int k) {
	char letter;
	letter = getc(encrypted_text);
	while (!feof(encrypted_text)) {
		letter = Caesars_decipher(letter, k);
		fputc(letter, decrypted_text);
		letter = getc(encrypted_text);
	}
}

//Дешифровка файла со сдвигом букв на клавиатуре
void decrypt_keyboard_decipher(FILE* encrypted_text, FILE* decrypted_text) {
	char letter;
	letter = getc(encrypted_text);
	while (!feof(encrypted_text)) {
		letter = keyboard_decipher(letter);
		fputc(letter, decrypted_text);
		letter = getc(encrypted_text);
	}
}
