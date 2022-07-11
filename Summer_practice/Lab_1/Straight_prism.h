#ifndef STRAIGHT_PRISM_H
#define STRAIGHT_PRISM_H

#include<iostream>
#include"Isosceles_triangle.h"

class Straight_prism : public Isosceles_triangle{
private:
	double _height;

public:
	// ������������
	Straight_prism();
	Straight_prism(double, double, double, double);
	Straight_prism(const Straight_prism&);

	// ����������
	~Straight_prism() {};

	// �������
	double get_height() { return _height; }

	// �������
	void set_height(double new_height) { _height = new_height; }

	// ��������������� ����������.
	friend ostream& operator<<(ostream&, const Straight_prism&);
	friend istream& operator>>(istream&, const Straight_prism&);

	// ���������� ������� �����������
	double find_surface_area() const;

	// ���������� ������
	double find_volume() const;

	// ���������� ���������� ��������� ������
	double find_max_diagonal();

	// ����� ���������� ��� �������
	string type() const override { return "Straight prism"; };

	// ����� ���������� � ������
	void print() override;
};

#endif // STRAIGHT_PRISM_H