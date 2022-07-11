#include"Functions.h"

// Функция проверяет, является ли треугольник равнобедренным
bool is_isosceles(double side1, double side2, double side3) {
	if (side1 == side2 || side1 == side3 || side2 == side3)
		return true;
	return false;
}

// Функция определяет тип фигуры
int get_type(Figure* fig) {
	if (typeid(*fig) == typeid(Isosceles_triangle)) return 1;
	else if (typeid(*fig) == typeid(Straight_prism)) return 2;
	else return 3;
}

// Функция помещает объект в двусвязный список
void function_1(List<Figure*>& figure_list) {
	int figure_type;
	double side1, side2, side3, height;
	Isosceles_triangle* triangle;
	Straight_prism* prism;
	ifstream finput("input.txt");

	while (!finput.eof()) {
		finput >> figure_type;
		if (figure_type == 1) {
			finput >> side1 >> side2 >> side3;
			try {
				if (is_isosceles(side1, side2, side3)) {
					triangle = new Isosceles_triangle(side1, side2, side3);
					figure_list.push_back(triangle);
				}
				else
					throw 1;
			}
			catch (int a) {
				cout << "Exception number:  " << a << endl;
				cout << "Not issosceles triangle!" << endl;
			}
		}
		else if (figure_type == 2) {
			finput >> side1 >> side2 >> side3 >> height;
			try {
				if (is_isosceles(side1, side2, side3)) {
					prism = new Straight_prism(side1, side2, side3, height);
					figure_list.push_back(prism);
				}
				else
					throw 2;
			}
			catch (int a) {
				cout << "Exception number:  " << a << endl;
				cout << "Not straight prism!" << endl;
			}
		}
		else cout << "Unknown figure" << endl;
	}

	finput.close();
}

// Функция выводит информацию о фигурах из списка
void function_2(List<Figure*>& figure_list) {
	Node<Figure*>* curr = figure_list.front();
	while(curr){
		curr->value()->print();
		curr = curr->next();
	}
}

// Функция находит треугольник с максимальной площадью
// И призму с максимальной диагональю
void function_3(List<Figure*>& list, Isosceles_triangle& triangle, Straight_prism& prism) {
	Node<Figure*>* curr = list.front();
	double max_square = 0, square, max_diagonal = 0, diagonal;
	while (curr) {
		auto& value = *(curr->value());
		if (typeid(value) == typeid(triangle)) {
			Isosceles_triangle* object = dynamic_cast<Isosceles_triangle*>(curr->value());
			square = triangle.find_square();
			if (max_square < square) {
				max_square = square;
				triangle = *object;
			}
		}
		if (typeid(value) == typeid(prism)) {
			Straight_prism* object = dynamic_cast<Straight_prism*>(curr->value());
			diagonal = prism.find_max_diagonal();
			if (max_diagonal < diagonal) {
				max_diagonal = diagonal;
				prism = *object;

			}
		}
		curr = curr->next();
	}
}