//������� ��������� ���-13��
//������������ ������ �6. ������ � ���������
//
//������� 2. ������������
//������� 8. �������� ��������������� �������.

#include<iostream>
#include<cmath>
#include"input_check.h"
#include"matrix_operation.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int size;
	double det;
	double** matrix;
	double** inverse_matrix;
	double** transposed_matrix;

	cout << "�������� ��������������� �������" << endl;
	cout << endl << "������� ������ �������: ";
	size = matrix_size_check();
	cout << endl << "������ �������� �������: " << endl;

	matrix = input_matrix(size); //���������� ����������� �������

	det = calculating_determinant(matrix, size); //���������� ������������
	//���� ������������ ����� 0, �� �������� ������� ��������� ������ ->
	// -> �������� ������� �� �������� �������������
	if (det == 0)
		cout << endl << "������� �� �������� �������������" << endl;
	else {
		inverse_matrix = create_inverse_matrix(matrix, size); //�������� �������� �������
		output(inverse_matrix, size);
		transposed_matrix = create_transposed_matrix(matrix, size); //�������� ����������������� �������
		if (is_identity_matrix(inverse_matrix, transposed_matrix, size) == false)
			cout << endl << "������� �� �������� �������������" << endl;
		else
			cout << endl << "������� �������� �������������" << endl;

		//������� ������
		free(inverse_matrix, size);
		free(transposed_matrix, size);
	}

	//������� ������
	free(matrix, size);

	system("pause");
	return 0;
}