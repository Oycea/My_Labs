#ifndef STRAIGHT_PRISM_H
#define STRAIGHT_PRISM_H

#include<iostream>
#include"Isosceles_triangle.h"

class Straight_prism : public Isosceles_triangle{
private:
	double _height;

public:
	// Конструкторы
	Straight_prism();
	Straight_prism(double, double, double, double);
	Straight_prism(const Straight_prism&);

	// Деструктор
	~Straight_prism() {};

	// Геттеры
	double get_height() { return _height; }

	// Сеттеры
	void set_height(double new_height) { _height = new_height; }

	// Переопределение операторов.
	friend ostream& operator<<(ostream&, const Straight_prism&);
	friend istream& operator>>(istream&, const Straight_prism&);

	// Вычисление площади поверхности
	double find_surface_area() const;

	// Вычисление объёма
	double find_volume() const;

	// Находжение наибольшей диагонали призмы
	double find_max_diagonal();

	// Метод возвращает тип объекта
	string type() const override { return "Straight prism"; };

	// Вывод информации о фигуре
	void print() override;
};

#endif // STRAIGHT_PRISM_H