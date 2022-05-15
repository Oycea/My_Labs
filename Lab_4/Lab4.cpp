//Гущиной Маргариты ПМИ13-БО
//ЛАБОРАТОРНАЯ РАБОТА №4. ДВИЖЕНИЕ ФИГУРЫ ПО ДОСКЕ
//
////Конь, поле 4, задание I

#include<iostream>
#include<cmath>
#include"knight_func.h"
using namespace std;

int input_validation() {
	int idx;
	cin >> idx;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Incorrect variable. Enter again" << endl;
		cin >> idx;
	}
	return idx;
}

int main() {
	int start_pos, last_row, row, start_idx;
	int idx_first_step[6] = { 0 }; //Массив, записывающий номера клеток после первого хода
	int idx_second_step[36] = { 0 }; //Массив, записывающий номера клеток после второго хода

	cout << "Enter the number of rows: ";
	last_row = input_validation();
	cout << endl << "Enter row number: ";
	row = input_validation();
	cout << endl << "Enter the position of the element in the row: ";
	start_pos = input_validation();
	cout << endl << "The numbers of the squares where the knight will get in two moves from a given point of the field: " << endl;

	start_idx = defindion_idx(row, start_pos);
	//Индексы первого хода
	movement_options(start_idx, last_row, idx_first_step);
	//Индексы второго хода
	for (int i = 0; i < 6; i++)
		movement_options(idx_first_step[i], last_row, idx_second_step+i*6);
	delet_unsuitable_idx(idx_second_step);
	output(idx_second_step);
	system("pause");
	return 0;
}
