//Гущиной Маргариты ПМИ13-БО
//ЛАБОРАТОРНАЯ РАБОТА №1. ТИПЫ ДАННЫХ. ВЫЧИСЛЕНИЯ.
// 
//Решение уравнений
//Напишите программу, которая решает уравнение a | x − b | = c относительно x для
//любых чисел a, b, c введенных с клавиатуры. Все числа считаются действительными.

#include<iostream>
using namespace std;

int main() {
	double a, b, c;

	cout << "Enter a: ";
	cin >> a;
	while (std::cin.fail()) { //Чистка памяти, защита от некорректно введённых данных
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Incorrect variable. Enter again" << endl;
		cin >> a;
	}

	cout << "Enter b: ";
	cin >> b;
	while (std::cin.fail()) { 
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Incorrect variable. Enter again" << endl;
		cin >> a;
	}

	cout << "Enter c: ";
	cin >> c;
	while (std::cin.fail()) { 
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Incorrect variable. Enter again" << endl;
		cin >> a;
	}

	if(a == 0) {
		if (c != 0) cout << "No roots"<< endl;
		else cout << "x - any number"<<endl;
	}
	if (a != 0) {
		if (c == 0) cout << "x=" << b << endl;
		else {
			if (c / a < 0) cout << "No roots";
			else {
				cout << "x1 = " << -c / a + b <<" ";
				cout << "x2 = " << c / a + b;
			}
		}
	}
	system("pause");
	return 0;
}