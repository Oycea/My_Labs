#include<iostream>
#include <iomanip>
#include<cmath>
#include"matrix_operation.h"
using namespace std;

//��������� ������ ��� �������
double** memory_allocation_matrix(int size) {
	double** matrix = new double* [size];
	for (int i = 0; i < size; i++)
		matrix[i] = new double[size];
	return matrix;
}

//���������� �������
double** input_matrix(int size) {
	double** matrix = memory_allocation_matrix(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			cin >> matrix[i][j];
	return matrix;
}

//�������� ������� �������
double** create_zero_matrix(int size) {
	double** matrix = memory_allocation_matrix(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = 0;
	return matrix;
}

//��������� ���� ��������� �������
double** zero_matrix(double** matrix, int size) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = 0;
	return matrix;
}

//���������� ������ �������
double** create_minor(double** matr, int size, int row_idx, int column_idx) {
	double** minor;
	if (size == 1) {
		minor = memory_allocation_matrix(size);
		minor[0][0] = matr[0][0];
	}
	else {
		minor = memory_allocation_matrix(size - 1);
		int minor_i = 0;
		for (int i = 0; i < size; i++) {
			if (i != row_idx) {
				for (int j = 0, minor_j = 0; j < size; j++) {
					if (j != column_idx) {
						minor[minor_i][minor_j] = matr[i][j];
						minor_j++;
					}
				}
				minor_i++;
			}
		}
	}
	return minor;
}

//���������� ������������ �������
double calculating_determinant(double** matrix, int size) {
	if (size == 1)
		return matrix[0][0];
	else if (size == 2)
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	double det = 0;
	for (int k = 0; k < size; k++) {
		double** minor = memory_allocation_matrix(size - 1);
		for (int i = 1; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (j == k)
					continue;
				else if (j < k)
					minor[i - 1][j] = matrix[i][j];
				else
					minor[i - 1][j - 1] = matrix[i][j];
			}
		}
		det += pow(-1, k + 2) * matrix[0][k] * calculating_determinant(minor, size - 1);
	}
	return det;
}

//���������� ����������������� �������
double** create_transposed_matrix(double** matrix, int size) {
	double** transposed_matrix = create_zero_matrix(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			transposed_matrix[i][j] = matrix[j][i];
	return transposed_matrix;
}

//���������� �������� �������
double** create_inverse_matrix(double** matrix, int size) {
	double det_minor;
	double det_matrix = calculating_determinant(matrix, size);
	double** minor;
	double** inverse_matrix = create_zero_matrix(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			minor = create_minor(matrix, size, j, i);
			if (size == 1)
				det_minor = det_matrix;
			else
				det_minor = calculating_determinant(minor, size - 1);
			inverse_matrix[i][j] = 1 / det_matrix * pow(-1, i + j) * det_minor;
		}
	return inverse_matrix;
}

//�������� ��������� ���������� �������
double** create_identity_matrix(int size) {
	double** identity_matrix = create_zero_matrix(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (i == j)
				identity_matrix[i][j] = 1;
	return identity_matrix;
}

//��������� ������� �� �������
double** matrix_multiplication_by_matrix(double** matrix_1, double** matrix_2, int size) {
	double** matrix_res = create_zero_matrix(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				matrix_res[i][j] += matrix_2[i][k] * matrix_1[k][j];
			}
		}
	}
	return matrix_res;
}

//��������� ������� �� �����
double** matrix_multiplication_by_number(double** matrix, int k, int size) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = matrix[i][j] * k;
	return matrix;
}

//�������� ���� ������
double** substraction_of_matrices(double** matrix_1, double** matrix_2, int size) {
	double** matrix_res = create_zero_matrix(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix_res[i][j] = matrix_1[i][j] - matrix_2[i][j];
	return matrix_res;
}

//����� ���� ������
double** sum_of_matrices(double** matrix_1, double** matrix_2, int size) {
	double** matrix_res = create_zero_matrix(size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix_res[i][j] = matrix_1[i][j] + matrix_2[i][j];
	return matrix_res;
}


//����������� ��������� �� ����� ������� � ������
double** copy_elements(double** matrix_1, double** matrix_2, int size) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix_2[i][j] = matrix_1[i][j];
	return matrix_2;
}

//�������� ������ �� ���������
bool is_identity_matrix(double** matrix_1, double** matrix_2, int size) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (matrix_1[i][j] != matrix_2[i][j])
				return false;
	return true;
}

//����� �������
void output(double** matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << setw(15) << matrix[i][j];
		cout << endl;
	}
}

//������� ���������� ��������� 5*� + �*� = � � ������������� �������
bool equation_solution(double** matrix_a, double** matrix_b, int size) {
	double det;
	double** matrix_x = create_zero_matrix(size);
	if (size == 1) {
		cout << "����������� � ���� X * (1 + " << matrix_a[0][0] << ") = " << matrix_b[0][0] << endl;
		cout << "�������� X * " << matrix_a[0][0] + 5 << " = " << matrix_b[0][0] << endl;
		cout << "�����: " << matrix_b[0][0] / (matrix_a[0][0] + 5) << endl;
		return true;
	}
	else {
		//������� ��������� � ��������� �������
		cout << "����������� ��������� � ���� �(5� + �) = � " << endl;
		cout << "5� = " << endl;
		double** identity_matrix = create_identity_matrix(size);
		identity_matrix = matrix_multiplication_by_number(identity_matrix, 5, size);
		output(identity_matrix, size);

		cout << endl << "5� + � = " << endl;
		matrix_a = sum_of_matrices(matrix_a, identity_matrix, size);
		output(matrix_a, size);

		cout << endl << "��� ������� � �� ������������ ����� ����� �������� ������� � 5� + �" << endl;
		det = calculating_determinant(matrix_a, size);
		if (det == 0) {
			cout << "���������� ����������" << endl;
			return false;
		}
		matrix_a = create_inverse_matrix(matrix_a, size);
		output(matrix_a, size);

		cout << endl << endl << "������� �� �������� ������� ������� �" << endl;
		cout << "�����: " << endl;
		matrix_x = matrix_multiplication_by_matrix(matrix_a, matrix_b, size);
		//����� ������
		output(matrix_x, size);
		free(matrix_x, size);
		return true;
	}
}

//������������ ������ �������
void free(double** matrix, int size) {
	for (int i = 0; i < size; i++)
		delete[] matrix[i];
	delete[] matrix;
	matrix = 0;
}