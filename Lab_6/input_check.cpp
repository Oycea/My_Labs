#include<iostream>
#include"input_check.h"
using namespace std;

//�������� ������������ ����� ������� �������
int matrix_size_check() {
	int size;
	cin >> size;
	while ((std::cin.fail()) || (size <= 0)) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Incorrect variable. Enter again" << endl;
		cin >> size;
	}
	return size;
}

//�������� ������������ ����� ��������� �������
double matrix_elements_check() {
	double num;
	cin >> num;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Incorrect variable. Enter again" << endl;
		cin >> num;
	}
	return num;
}