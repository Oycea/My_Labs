//Гущиной Маргариты ПМИ13-БО
//ЛАБОРАТОРНАЯ РАБОТА №9. ДИНАМИЧЕСКОЕ ПРОГРАММИРОВАНИЕ.
//
//Вариант 50.
//Даны две последовательности.
//Требуется найти и вывести их наибольшую общую подпоследовательность.

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//Запонение динамического массива
int* input_arr(int* arr, int size) {
	for (int i = 1; i <= size; i++)
		cin >> arr[i];
	return arr;
}

//Выделение памяти для матрицы строк
string** memory_allocation_string_matrix(int str, int col) {
	string** matrix = new string * [str];
	for (int i = 0; i < str; i++)
		matrix[i] = new string[col];
	return matrix;
}

//Выделение памяти для матрицы чисел
int** memory_allocation_int_matrix(int str, int col) {
	int** matrix = new int* [str];
	for (int i = 0; i < str; i++)
		matrix[i] = new int[col];
	return matrix;
}

//Создание нулевой матрицы
int** create_zero_matrix(int str, int col) {
	int** matrix = memory_allocation_int_matrix(str, col);
	for (int i = 0; i < str; i++)
		for (int j = 0; j < col; j++)
			matrix[i][j] = 0;
	return matrix;
}

//Вывод матрицы целых чисел
void output(int** matrix, int str, int col) {
	for (int i = 0; i < str; i++) {
		for (int j = 0; j < col; j++)
			cout << "     " << matrix[i][j];
		cout << endl;
	}
}

//Освобождение памяти матрицы целых чисел
void free(int** matrix, int size) {
	for (int i = 0; i < size; i++)
		delete[] matrix[i];
	delete[] matrix;
	matrix = 0;
}

int main() {
	int n, m;
	cin >> n;
	if (n == 0)
		cout << 0;
	else{
		int* first_sq = new int[n + 1];
		first_sq = input_arr(first_sq, n);
		cin >> m;
		if (m == 0)
			cout << 0;
		else {
			int* second_sq = new int[m + 1];
			second_sq = input_arr(second_sq, n);
			int** matr = create_zero_matrix(n + 1, m + 1);
			vector<int> answer;

			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (first_sq[i] == second_sq[j])
						matr[i][j] = 1 + matr[i - 1][j - 1];
					else
						matr[i][j] = max(matr[i - 1][j], matr[i][j - 1]);
				}
			}

			while (n && m) {
				if (first_sq[n] == second_sq[m]) {
					answer.push_back(first_sq[n]);
					n--;
					m--;
				}
				else
					if (matr[n - 1][m] == matr[n][m])
						n--;
					else
						m--;
			}

			if (answer.size() == 0)
				cout << 0;
			else
				for (int i = answer.size() - 1; i >= 0; i--)
					cout << answer[i] << ' ';

			free(matr, n + 1);
			delete[] first_sq;
			first_sq = 0;
			delete[] second_sq;
			second_sq = 0;
		}
		delete[] first_sq;
		first_sq = 0;
	}
	system("pause");
	return 0;
}
