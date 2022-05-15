//Гущиной Маргариты ПМИ13-БО
//ЛАБОРАТОРНАЯ РАБОТА №3. ФУНКЦИИ.
//
//По заданным вещественным числам x, ε произвести вычисление суммы ряда до тех пор,
//пока абсолютная величина очередного члена ряда не станет меньше ε.Вычисления должны быть
//произведены максимально экономно, так, чтобы значение каждого последующего слагаемого
//вычислялось исходя из значения предыдущего(без библиотечной функции возведения в степень).
//Программа должна вывести на печать значения x, ε, вычисленной суммы ряда, точного значения
//функции, разности суммы и точного значения функции, а также абсолютной величины последнего
//вычисленного члена ряда.

#include<iostream>
#include<cmath>
using namespace std;

long int fact(int n) {
	long int res = 1;
	for (int i = 1; i <= n; i++)
		res *= i;
	return res;
}

double mabs(double x) {
	if (x > 0)
		return x;
	return -1 * x;
}

//Возведение в положительную степень
double power(double x, int n) {
	double res = 1;
	if (n == 0)
		return 1;
	for (int i = 1; i <= n; i++)
		res *= x;
	return res;
}

double input_validation() {
	double x;
	cin >> x;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Incorrect variable. Enter again" << endl;
		cin >> x;
	}
	return x;
}

int main() {
	double x, eps, last_x, csh;
	double sum = 1;
	double cur = 1, prew;
	int n = 0;
	cout << "Find cosh" << endl << "Enter x: ";
	x = input_validation();
	cout << "Enter epsilon: ";
	eps = input_validation();
	csh = cosh(x);

	while (mabs(cur) > eps) {
		prew = cur;
		last_x = cur;
		cur = prew * (power(x, 2) / ((n + 1)*(n + 2)));
		sum += cur;
		n += 2;
	}
	cout << "x = " << x << endl;
	cout << "epsilon = " << eps << endl;
	cout << "Sum of series = " << sum << endl;
	cout << "Exact value = " << csh << endl;
	cout << "Difference = " << sum - csh << endl;
	cout << "Absolute value of the last term in the series = " << last_x << endl;

	system("pause");
	return 0;
}