#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<locale.h>
#include"decrypt.h"
using namespace std;
const char symbol_arr[] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
							'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
							'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
							'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
							'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
							'�', '�', '�', '�', '�', '�', ' ', '.', ',', '?', ':', ';',
							'-', '(', ')', '!', '"' };
const char keyboard_symbol_arr[] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
									 '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
									 '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
									 '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
									 '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
									 '�', '�', '�', '�', '�' };

//���������� �� ����� ������
char Caesars_decipher(char letter, int k) {
	if (letter >= '�' && letter <= '�')
		letter = ((letter - '�' - k + 32) % 32) + '�';
	else if (letter >= '�' && letter <= '�')
		letter = ((letter - '�' - k + 32) % 32) + '�';
	return letter;
}

//���������� ����� �� ������� ���� �� ���������� (����� �����)
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

//���������� ����� � ������ ������
void decrypt_Caesars_decipher(FILE* encrypted_text, FILE* decrypted_text, int k) {
	char letter;
	letter = getc(encrypted_text);
	while (!feof(encrypted_text)) {
		letter = Caesars_decipher(letter, k);
		fputc(letter, decrypted_text);
		letter = getc(encrypted_text);
	}
}

//���������� ����� �� ������� ���� �� ����������
void decrypt_keyboard_decipher(FILE* encrypted_text, FILE* decrypted_text) {
	char letter;
	letter = getc(encrypted_text);
	while (!feof(encrypted_text)) {
		letter = keyboard_decipher(letter);
		fputc(letter, decrypted_text);
		letter = getc(encrypted_text);
	}
}