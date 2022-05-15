#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<locale.h>
#include"encoding_func.h"
using namespace std;

//���� ������ (����������� ����� �������� ����� �� 3 �������)
char Caesars_cipher(char letter) {
	if (letter >= '�' && letter <= '�')
		letter = ((letter - '�' + 3) % 32) + '�';
	else if (letter >= '�' && letter <= '�')
		letter = ((letter - '�' + 3) % 32) + '�';
	return letter;
}

//���������� �� ����� ������
char Caesars_decipher(char letter) {
	if (letter >= '�' && letter <= '�')
		letter = ((letter - '�' - 3 + 32) % 32) + '�';
	else if (letter >= '�' && letter <= '�')
			letter = ((letter - '�' - 3 + 32) % 32) + '�';
	return letter;
}

//�������� �����
void crypt(FILE* original_text, FILE* encrypted_text) {
	char letter;
	letter = getc(original_text);
	while (!feof(original_text)) {
		letter = Caesars_cipher(letter);
		fputc(letter, encrypted_text);
		letter = getc(original_text);
	}
}

//���������� �����
void decrypt(FILE* encrypted_text, FILE* decrypted_text) {
	char letter;
	letter = getc(encrypted_text);
	while (!feof(encrypted_text)) {
		letter = Caesars_decipher(letter);
		fputc(letter, decrypted_text);
		letter = getc(encrypted_text);
	}
}

//�������� ������������ ������������� � �������������� ������
bool is_identity(FILE* original_text, FILE* decrypted_text) {
	char orig_text_character, decrypt_text_character;
	int num_of_differences = 0;
	while (!feof(original_text)) {
		orig_text_character = getc(original_text);
		decrypt_text_character = fgetc(decrypted_text);
		if (orig_text_character != decrypt_text_character)
			num_of_differences++;
	}
	if (num_of_differences == 0)
		return 1;
	return 0;
}