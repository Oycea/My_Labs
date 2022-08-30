// Лабораторная работа №3
// Динамическое программирование
// Вариант 10
// Выполнила: Гущина Маргарита ПМИ-13БО

#include<iostream>
using namespace std;

// Проверка корректности ввода размера матрицы
void matrix_size_check(int& num) {
	cin >> num;
	while (cin.fail() || num <= 0) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Incorrect variable. Enter again" << endl;
		cin >> num;
	}
}

// Проверка корректности ввода элементов матрицы
void matrix_elements_check(double& num) {
	cin >> num;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Incorrect variable. Enter again" << endl;
		cin >> num;
	}
}

// Выделение памяти для матрицы размера N x M
double** memory_allocation_matrix(int n, int m) {
	double** matrix = new double* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new double[m];
	return matrix;
}

// Ввод матрицы размера N x M
double** input_matrix(int n, int m) {
	double** matrix = memory_allocation_matrix(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix_elements_check(matrix[i][j]);
	return matrix;
}

// Очистка памяти матрицы
void matrix_free(double** matrix, int n) {
	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;
	matrix = 0;
}

int main() {
	int n, m;
	cout << "Enter table size" << endl;
	matrix_size_check(n);
	matrix_size_check(m);
	cout << "Enter values into table" << endl;
	double** matr_money = input_matrix(n, m);
	double** matr_res = memory_allocation_matrix(n, m);

	matr_res[0][0] = matr_money[0][0];
	for (int j = 1; j < m; j++)
		matr_res[0][j] = matr_money[0][j] + matr_res[0][j - 1];
	for (int i = 1; i < n; i++)
		matr_res[i][0] = matr_money[i][0] + matr_res[i - 1][0];
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++) {
			if (matr_res[i - 1][j] >= matr_res[i][j - 1]) {
				matr_res[i][j] = matr_res[i - 1][j] + matr_money[i][j];
			}
			else matr_res[i][j] = matr_res[i][j - 1] + matr_money[i][j];
		}

	cout << "Maximum sum of elements: " << matr_res[n - 1][m - 1];

	matrix_free(matr_money, n);
	matrix_free(matr_res, n);

	return 0;
}