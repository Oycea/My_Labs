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
	// ������������
	Isosceles_triangle();
	Isosceles_triangle(double, double, double);
	Isosceles_triangle(const Isosceles_triangle&);

	// ����������
	~Isosceles_triangle() {};

	// �������
	double get_side1() { return _side1; }
	double get_side2() { return _side2; }
	double get_side3() { return _side3; }

	// �������
	void set_side1(double new_side) { _side1 = new_side; }
	void set_side2(double new_side) { _side2 = new_side; }
	void set_side3(double new_side) { _side3 = new_side; }

	// ��������������� ����������.
	friend ostream& operator<<(ostream&, const Isosceles_triangle&);
	friend istream& operator>>(istream&, const Isosceles_triangle&);

	// ����� ������������ ������
	double find_max_side() const;

	// ���������� ���� �����
	double* find_all_angle() const;

	// ���������� ���������
	double find_perimeter() const;

	// ���������� �������
	double find_square() const;

	// ����� ���������� ��� �������.
	string type() const override { return "Isosceles_triangle"; };

	// ����� ���������� � ������
	void print() override;
	
};

#endif // ISOSCELES_TRIANGLE_H