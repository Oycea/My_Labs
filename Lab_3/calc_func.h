#ifndef _CALC_FUNC_H_
#define _CALC_FUNC_H_

typedef double(*function_ptr)(double, double);

long int fact(int n); //Вычисление факториала
double power(double x, int n);//Возведение в положительную степень
double mabs(double x); //Вычисление модуля
double input_validation(); //Проверка корректности данных
double F1(double x, double eps); //Функция с использованием вспомогательных функций
double F2(double x, double eps); //Функция, опирающаяся на предыдущее значение

void tabulator(function_ptr F, double a, double b, int n, double eps); //Табуляция функций, счет времени

#endif //_CALC_FUNC_H_#pragma once
