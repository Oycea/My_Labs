#include"Straight_prism.h"

// Конструкторы
Straight_prism::Straight_prism() : Isosceles_triangle(), _height(0) {}

Straight_prism::Straight_prism(double side1, double side2, double side3, double height) :
	Isosceles_triangle(side1, side2, side3), _height(height) {}

Straight_prism::Straight_prism(const Straight_prism& object) :
	Isosceles_triangle(object), _height(object._height) {}


// Переопределение оператора вывода
ostream& operator<<(ostream& output, const Straight_prism& object) {
	output << "First side base: " << object._side1 << endl
		<< "Second side base: " << object._side2 << endl
		<< "Third side base: " << object._side3 << endl
		<< "Height: " << object._height;
	return output;
}

// Переопределение оператора вывода
istream& operator>>(istream& input, Straight_prism& object) {
	double num;
	cout << "Enter the paremetres of the isosceles triangle at the base:" << endl;
	cout << "Enter base: " << endl;
	input >> num;
	while ((input.fail()) || (num <= 0)) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Incorrect variable. Enter again" << endl;
		input >> num;
	}
	object.set_side3(num);
	cout << "Enter side: " << endl;
	input >> num;
	while ((input.fail()) || (num <= 0)) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Incorrect variable. Enter again" << endl;
		input >> num;
	}
	object.set_side1(num);
	object.set_side2(num);
	cout << "Enter prism height: " << endl;
	input >> num;
	while ((input.fail()) || (num <= 0)) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Incorrect variable. Enter again" << endl;
		input >> num;
	}
	object.set_height(num);
	return input;
}

// Вычисление площади поверхности
double Straight_prism::find_surface_area() const {
	return _height * find_perimeter() + 2 * find_square();
}

// Вычисление объёма
double Straight_prism::find_volume() const {
	return _height * find_square();
}

// Находжение наибольшей диагонали призмы
double Straight_prism::find_max_diagonal() {
	double max_len = 0, diagonal;
	max_len = find_max_side();
	diagonal = sqrt(pow(max_len, 2) + pow(_height, 2));
	return diagonal;
}

// Вывод информации о фигуре
void Straight_prism::print() {
	double* all_angle = new double[3];
	all_angle = find_all_angle();
	cout << "Type: " << endl << type() << endl;
	cout << "Prism square = " << find_surface_area() << endl;
	cout << "prism volume = " << find_volume() << endl;
	delete[] all_angle;
	all_angle = 0;
}