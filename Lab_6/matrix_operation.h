#ifndef _MATRIX_OPERATION_H_
#define _MATRIX_OPERATION_H_

//��������� ������ ��� �������
double** memory_allocation_matrix(int size);

//���������� �������
double** input_matrix(int size);

//�������� ������� �������
double** create_zero_matrix(int size);

//��������� ���� ��������� �������
double** zero_matrix(double** matrix, int size);

//���������� ������ ������� �� ���������� ��������
double** create_minor(double** matr, int size, int row_idx, int column_idx);

//���������� ������������ �������
double calculating_determinant(double** matrix, int size);

//���������� ����������������� �������
double** create_transposed_matrix(double** matrix, int size);

//���������� �������� �������
double** create_inverse_matrix(double** matrix, int size);

//�������� ��������� ���������� �������
double** create_identity_matrix(int size);

//��������� ������� �� �������
double** matrix_multiplication_by_matrix(double** matrix_1, double** matrix_2, int size);

//��������� ������� �� �����
double** matrix_multiplication_by_number(double** matrix, int k, int size);

//�������� ���� ������
double** substraction_of_matrices(double** matrix_1, double** matrix_2, int size);

//����� ���� ������
double** sum_of_matrices(double** matrix_1, double** matrix_2, int size);

//����������� ��������� �� ����� ������� � ������
double** copy_elements(double** matrix_1, double** matrix_2, int size);

//�������� ������ �� ���������
bool is_identity_matrix(double** matrix_1, double** matrix_2, int size);

//����� �������
void output(double** matrix, int size);

//������� ���������� ��������� 5*� + �*� = � � ������������� �������
bool equation_solution(double** matrix_a, double** matrix_b, int size);

//������������ ������ �������
void free(double** matrix, int size);

#endif //_MATRIX_OPERATION_H_