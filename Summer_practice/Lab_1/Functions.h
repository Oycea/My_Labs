#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<fstream>
#include"Figure.h"
#include"Isosceles_triangle.h"
#include"Straight_prism.h"
#include"List.h"
#include"Inf_check.h"
using namespace std;

// Функция проверяет, является ли треугольник равнобедренным
bool is_isosceles(double side_1, double side_2, double side_3);

// Функция определяет тип фигуры
int get_type(Figure* fig);

// Функция помещает объект в двусвязный список
void function_1(List<Figure*>& figure_list);

// Функция выводит информацию о фигурах из списка
void function_2(List<Figure*>& figure_list);

// Функция находит треугольник с максимальной площадью
// И призму с максимальной диагональю
void function_3(List<Figure*>& list, Isosceles_triangle& triangle, Straight_prism& prism);

#endif // FUNCTIONS_H