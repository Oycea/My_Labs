//Гущиной Маргариты ПМИ13-БО
//ЛАБОРАТОРНАЯ РАБОТА №1. ТИПЫ ДАННЫХ. ВЫЧИСЛЕНИЯ.
//
//В этом задании необходимо вычислить два выражения A и B, зависящих от переменных (вводит пользователь). 
//И вывести значения обоих выражений и разности C между ними в формате с фиксированной точкой с точностью 0, 000001. 
//Выражения могут содержать дроби и корни, поэтому важно помнить об ОДЗ.
//Пользователь вводит значения, которые необходимы для вычисления по заданной формуле(например x, y, z или α).
//В случае, если пользователь вводит не корректное значение, нужно выводить на экран соответствующее сообщение.

#include<math.h>
#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	const float pi = 3.141592;
	float exA, exB, exC;
	float a1, b1, b2; //Тангенсы выражений А и В
	float a;
	cout << "Enter a in radians" << endl;
	cin >> a;

	while (std::cin.fail()) { //Чистка памяти, защита от некорректно введённых данных
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Incorrect variable. Enter again" << endl;
		cin >> a;
	}

	if ((cos(a * 3 / 4 - pi / 2) != 0) && (cos(pi * 3 / 2 - a / 4) != 0) && (cos(a * 3 / 4 - pi * 7 / 2) != 0) && (a!=0)) {
		a1 = tan(a * 3 / 4 - pi / 2);
		exA = 8 * sin(5 * pi / 2 + a / 2) * (1 + a1 * a1);
		cout << fixed << setprecision(6) << "A = " << exA << endl;

		b1 = tan(pi * 3 / 2 - a / 4);
		b2 = tan(a * 3 / 4 - pi * 7 / 2);
		exB = 1 / (cos(a / 4) * cos(a / 4)) * (b1 * b1 - b2 * b2);
		cout << fixed << setprecision(6) << "B = " << exB << endl;

		exC = exA - exB;
		cout << "C = " << exC;
	}

	else cout << "Incorrect value";
	system("pause");
	return 0;
}