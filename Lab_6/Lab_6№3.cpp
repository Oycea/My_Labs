//������� ��������� ���-13��
//������������ ������ �6. ������ � ���������
//
//������� 3. ��������� ���������
//������� 10. 

#include<iostream>
#include <iomanip>
#include<cmath>
#include"matrix_operation.h"
using namespace std;

//�������� ������������ ����� ������� �������
int natural_number_check() {
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

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "������� ���������� ��������� 5*� + �*� = �" << endl;
	int size;
	double det;
	cout << endl << "������� ������ ���������� ������: ";
	size = natural_number_check();
	cout << endl;
	double** matrix_a;
	double** matrix_b;
	double** matrix_x;

	//�������� ������ ��� ����������
	cout << "������� ������� �: " << endl;
	matrix_a = input_matrix(size);
	cout << "������� ������� �: " << endl;
	matrix_b = input_matrix(size);
	matrix_x = create_zero_matrix(size);

	//������� ���������� ��������� 5*� + �*� = � � ������������� �������
	equation_solution(matrix_a, matrix_b, size);

	//������� ������
	free(matrix_a, size);
	free(matrix_b, size);
	system("pause");
	return 0;
}