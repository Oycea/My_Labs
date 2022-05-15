//������� ��������� ���13-��
//������������ ������ �5. �����������, �������������, ��������� ������
//
//������� 1. �������� � ����������
//������� 1. ���� ������.����������� ����� �������� ����� �� 3 �������.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<locale.h>
#include"encoding_func.h"
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
	FILE* original_text, * encrypted_text, * decrypted_text;

	if(check_argument_input(num_of_arg)==0)
		return 1;

	original_text = fopen(argv[1], "r");//�������� �����
	if(check_file_existence(original_text)==0)
		return 1;

	encrypted_text = fopen("GushchinaCrypt.txt", "w"); //������������� �����

	crypt(original_text, encrypted_text); //��������
	fclose(original_text);
	fclose(encrypted_text);
		
	encrypted_text = fopen("GushchinaCrypt.txt", "r");
	decrypted_text = fopen("GushchinaDecrypt.txt", "w");
	decrypt(encrypted_text, decrypted_text); //����������
	fclose(encrypted_text);
	fclose(decrypted_text);

	original_text = fopen(argv[1], "r");
	decrypted_text = fopen("GushchinaDecrypt.txt", "r");
	if (is_identity(original_text, decrypted_text) == 1)
		cout << "Encoding successful" << endl;
	else
		cout << "Error in coding" << endl; //�������� ������������ ����������
	fclose(original_text);
	fclose(decrypted_text);

	system("pause");
	return 0;
}