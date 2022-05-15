#ifndef _CALC_FUNC_H_
#define _CALC_FUNC_H_

typedef double(*function_ptr)(double, double);

long int fact(int n); //���������� ����������
double power(double x, int n);//���������� � ������������� �������
double mabs(double x); //���������� ������
double input_validation(); //�������� ������������ ������
double F1(double x, double eps); //������� � �������������� ��������������� �������
double F2(double x, double eps); //�������, ����������� �� ���������� ��������

void tabulator(function_ptr F, double a, double b, int n, double eps); //��������� �������, ���� �������

#endif //_CALC_FUNC_H_#pragma once
