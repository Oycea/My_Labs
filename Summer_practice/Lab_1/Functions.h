#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<fstream>
#include"Figure.h"
#include"Isosceles_triangle.h"
#include"Straight_prism.h"
#include"List.h"
#include"Inf_check.h"
using namespace std;

// ������� ���������, �������� �� ����������� ��������������
bool is_isosceles(double side_1, double side_2, double side_3);

// ������� ���������� ��� ������
int get_type(Figure* fig);

// ������� �������� ������ � ���������� ������
void function_1(List<Figure*>& figure_list);

// ������� ������� ���������� � ������� �� ������
void function_2(List<Figure*>& figure_list);

// ������� ������� ����������� � ������������ ��������
// � ������ � ������������ ����������
void function_3(List<Figure*>& list, Isosceles_triangle& triangle, Straight_prism& prism);

#endif // FUNCTIONS_H