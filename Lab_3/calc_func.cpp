#include<iostream>
#include<time.h>
#include"calc_func.h"
using namespace std;

//Вычисление факториала
long int fact(int n){
	long int res = 1;
	for (int i = 1; i <= n; i++)
		res *= i;
	return res;
}

//Возведение в положительную степень
double power(double x, int n){
	double res = 1;
	for (int i = 1; i <= n; i++)
		res *= x;
	return res;
}

//Вычисление модуля
double mabs(double x){
	if (x > 0)
		return x;
	return (-1) * x;
}

//Проверка корректности данных
double input_validation(){
	double x;
	cin >> x;
	while (std::cin.fail()) {
		std::cin.clear();
		fflush(stdin);
		std::cin.ignore(32767, '\n');
		cout << "Incorrect variable. Enter again" << endl;
		cin >> x;
	}
	return x;
}

//Функция с использованием вспомогательных функций
double F1(double x, double eps){
	double slag = 1;
	double sum = 0;
	int i = 2;
	while (mabs(slag) > eps) {
		slag = power(-1, 2 * i + 1) * power(x, 2 * i) / fact(3 * i - 5);
		sum += slag;
		i++;
	}
	return sum;
}

//Функция, опирающаяся на предыдущее значение
double F2(double x, double eps){
	int i = 1;
	double prew, cur = -x * x * x * x / i;
	double sum = -x * x * x * x / i;
	while (fabs(cur) > eps) {
		prew = cur;
		cur = prew * (x * x / ((i + 1) * (i + 2) * (i + 3)));
		sum += cur;
		i += 3;
	}
	return sum;
}

//Табулятор (+ измерение времени)
typedef double(*function_ptr)(double, double);
void tabulator(function_ptr F, double a, double b, int n, double eps){
	double step = (b - a + 1) / n;
	double start1 = clock();
	for (double i = a; i <= b; i += step) {
		cout << i << " " << F(i, eps) << endl;
	}
	double end1 = clock();
	cout << "Function execution time: " << (double)(end1 - start1) / CLOCKS_PER_SEC << endl;
}
