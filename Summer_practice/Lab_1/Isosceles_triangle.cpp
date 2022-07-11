#include"Isosceles_triangle.h"

// ������������
Isosceles_triangle::Isosceles_triangle() : _side1(0), _side2(0), _side3(0) {}

Isosceles_triangle::Isosceles_triangle(double side1, double side2, double side3) :
	_side1(side1), _side2(side2), _side3(side3) {}

Isosceles_triangle::Isosceles_triangle(const Isosceles_triangle& object) {
	_side1 = object._side1;
	_side2 = object._side2;
	_side3 = object._side3;
}

// ��������������� ��������� ������
ostream& operator<<(ostream& output, const Isosceles_triangle& object) {
	output << "First side: " << object._side1 << endl
		<< "Second side: " << object._side2 << endl
		<< "Base: " << object._side3 << endl;
	return output;
}

// ��������������� ��������� ������
istream& operator>>(istream& input, Isosceles_triangle& object) {
	double num;
	cout << "Enter base: " << endl;
	input >> num;
	object.set_side3(num);
	cout << "Enter side: " << endl;
	input >> num;
	object.set_side1(num);
	object.set_side2(num);
	return input;
}

// ����� ������������ ������
double Isosceles_triangle::find_max_side() const {
	return max(_side1, max(_side2, _side3));
}

// ���������� ���� �����
double* Isosceles_triangle::find_all_angle() const {
	double* angle_arr = new double[3];
	// ���� ������ ������� side1
	angle_arr[0] = acos((pow(_side2, 2) + pow(_side3, 2) - pow(_side1, 2)) / (2 * _side2 * _side3));
	// ���� ������ ������� side2
	angle_arr[1] = acos((pow(_side1, 2) + pow(_side3, 2) - pow(_side2, 2)) / (2 * _side1 * _side3));
	// ���� ������ ������� side3
	angle_arr[2] = acos((pow(_side1, 2) + pow(_side2, 2) - pow(_side3, 2)) / (2 * _side1 * _side2));
	return angle_arr;
}

// ���������� ���������
double Isosceles_triangle::find_perimeter() const {
	return _side1 + _side2 + _side3;
}

// ���������� �������
double Isosceles_triangle::find_square() const {
	double square, semi_per;
	semi_per = find_perimeter() / 2;
	square = sqrt(semi_per * (semi_per - _side1) * (semi_per - _side2) * (semi_per - _side3));
	return square;
}

// ����� ���������� � ������
void Isosceles_triangle::print() {
	double* all_angle = new double[3];
	all_angle = find_all_angle();
	cout << "Type: " << endl << type();
	cout << "Side 1 = " << _side1 << endl;
	cout << "Side 2 = " << _side2 << endl;
	cout << "Side 3 = " << _side3 << endl;
	cout << "Square = " << find_square();
	cout << "Perimeter = " << find_perimeter();
	cout << "All angle: ";
	for (int i = 0; i < 3; i++)
		cout << all_angle[i] << " ";
	delete[] all_angle;
	all_angle = 0;
}
