#ifndef ISOSCELES_TRIANGLE_H
#define ISOSCELES_TRIANGLE_H

#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include"Figure.h"

class Isosceles_triangle : public Figure {
protected:
	double _side1, _side2, _side3;

public:
	// Конструкторы
	Isosceles_triangle();
	Isosceles_triangle(double, double, double);
	Isosceles_triangle(const Isosceles_triangle&);

	// Деструктор
	~Isosceles_triangle() {};

	// Геттеры
	double get_side1() { return _side1; }
	double get_side2() { return _side2; }
	double get_side3() { return _side3; }

	// Сеттеры
	void set_side1(double new_side) { _side1 = new_side; }
	void set_side2(double new_side) { _side2 = new_side; }
	void set_side3(double new_side) { _side3 = new_side; }

	// Переопределение операторов.
	friend ostream& operator<<(ostream&, const Isosceles_triangle&);
	friend istream& operator>>(istream&, const Isosceles_triangle&);

	// Поиск максимальной строны
	double find_max_side() const;

	// Вычисление всех углов
	double* find_all_angle() const;

	// Вычисление периметра
	double find_perimeter() const;

	// Вычисление площади
	double find_square() const;

	// Метод возвращает тип объекта.
	string type() const override { return "Isosceles_triangle"; };

	// Вывод информации о фигуре
	void print() override;
	
};

#endif // ISOSCELES_TRIANGLE_H