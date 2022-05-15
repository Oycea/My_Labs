#ifndef _CALC_FUNC_H_
#define _CALC_FUNC_H_

typedef double(*function_ptr)(double, double);

//Вычисление факториала
long int fact(int n);

//Возведение в положительную степень
double power(double x, int n);

//Вычисление модуля
double mabs(double x);

//Проверка корректности данных
double input_validation();

//Функция с использованием вспомогательных функций
double F1(double x, double eps);

//Функция, опирающаяся на предыдущее значение
double F2(double x, double eps);

//Табуляция функций, счет времени
void tabulator(function_ptr F, double a, double b, int n, double eps);

#endif //_CALC_FUNC_H_
