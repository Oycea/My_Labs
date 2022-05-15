#include<iostream>
#include<cmath>
#include"knight_func.h"
using namespace std;

//Поиск номера последней клетки строки
//По формуле арифметической прогрессии
int last_idx(int rows) {
	return (2 + (rows - 1)) * rows / 2;
}

//Поиск номера ряда, в котором находится элемент
//По формуле корня квадратного уравнения
int definition_row(int idx) {
	return ceil(((-1) + sqrt(1 + 8 * idx)) / 2);
}

//Поиск индекса по номеру строки и номеру его позиции в строке
int defindion_idx(int row, int pos) {
	int lastidx = last_idx(row);
	return lastidx - row + pos;
}

//Поиск индексов после хода коня
void movement_options(int idx, int lastrow, int arr[6]) {
	int row = definition_row(idx);
	int lastidx = last_idx(row);
	if (idx == 0)
		return;
	else
		//Ход на 1 клетку вправо вниз => на 2 клетки по диагонали влево вниз
		if (lastrow - row >= 3)
			arr[0] = idx + 3 * row + 4;
		//Ход на 1 клетку вправо => на 2 клетки по диагонали вправо вниз
		if (lastrow - row >= 2 && idx != lastidx)
			arr[1] = idx + 2 * row + 4;
		//Ход на 1 клетку влево вниз => на 2 клетки влево
		if (lastrow - row >= 1 && idx > lastidx - row + 2)
			arr[2] = idx + row - 2;
		//Ход на 1 клетку влево => на 2 клетки по диагонали влево вверх
		if (row >= 4 && idx > lastidx - row + 3)
			arr[3] = idx - 2 * row;
		//Ход на 1 клетку влево вверх => на 2 клетки по диагонали вправо вверх
		if (row >= 4 && idx > lastidx - row + 1 && idx < lastidx - 1)
			arr[4] = idx - 3 * row + 5;
		//Ход на 1 клетку вправо вверх => на 2 клетки вправо
		if (row >= 4 && idx < lastidx - 2)
			arr[5] = idx - row + 3;

	return;
}

//Удаление лишних индексов - повторяющихся (сохраняется только один из повторяющихся)
// индексы "отсутствующего хода" (0)
int delet_unsuitable_idx(int arr[36]) {
	int n = 36;
	for (int i = 0; i < 35; i++)
		for (int j = i + 1; j < 36; j++) {
			if (arr[i] == arr[j])
				arr[j] = 0;
		}
	return arr[36];
}

//Вывод всех номеров клеток, в которые конь попадает после второго хода
void output(int arr[36]) {
	for (int i = 0; i < 36; i++)
		if (arr[i] != 0)
			cout << arr[i] << endl;
}