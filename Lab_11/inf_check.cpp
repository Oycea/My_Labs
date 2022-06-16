#include"inf_check.h"

// Проверка: корректно ли имя файла.
void check_file_name(string& file_name) {
	cin >> file_name;
	ifstream finput(file_name);
	while (!finput.is_open()) {
		cout << "Error, try again: ";
		cin >> file_name;
		finput = ifstream(file_name);
	}
	finput.close();
}

// Проверка: является ли введённое число положительным.
void check_pos_int(int& num) {
	cin >> num;
	while (cin.fail() || num <= 0) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "ERROR! Is not a positive integer number!";
		cin >> num;
	}
}

// Проверка: является ли полученное из файла число положительным.
void fcheck_pos_int(int& value, ifstream& finput) {
	string number;
	finput >> number;
	try {
		value = stoi(number);
	}
	catch (...) {
		cout << "ERROR! Is not integer!\n";
	}
	if (value <= 0) {
		cout << "ERROR! Is not a positiv integer number!\n";
		value = 0;
	}
}

// Проверка: является ли введённый маршрут корректным.
void check_marsh(marsh& object) {
	string start_point, end_point, route_number;
	int value;
	while (true) {
		cin >> start_point >> end_point >> route_number;
		try {
			value = stoi(route_number);
		}
		catch (...) {
			cout << "Try again: ";
			continue;
		}
		break;
	}
	object = marsh(start_point, end_point, value);
}

// Проверка: является ли полученный из файла маршрут корректным.
void fcheck_marsh(marsh& object, ifstream& finput) {
	string start_point, end_point, route_number;
	int value;
	cin >> start_point >> end_point >> route_number;
	try {
		value = stoi(route_number);
	}
	catch (...) {
		std::cout << "Error: not number\n";
		return;
	}
	object = marsh(start_point, end_point, value);
}
