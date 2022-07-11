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

// Проверка: правильно ли записано время.
bool check_time(const string& data) {
	for (int i = 2; i < 8; i += 3)
		if (data[i] != ':') return false;
	int temp = (data[0] - '0') * 10 + data[1] - '0';
	if (temp >= 24 or temp < 0) return false;
	temp = (data[3] - '0') * 10 + data[4] - '0';
	if (temp >= 60 or temp < 0) return false;
	temp = (data[6] - '0') * 10 + data[7] - '0';
	if (temp >= 60 or temp < 0) return false;
	return true;
}

// Проверка: правильно ли введено время.
void check_input_time(string& time) {
	cin >> time;
	while (!check_time(time)) {
		cout << "Try again: ";
		cin >> time;
	}
}


// Проверка: является ли введённое число положительным.
void check_positiv_int(int& value) {
	string number;
	while (true) {
		cin >> number;
		try {
			value = stoi(number);
		}
		catch (...) {
			cout << "Try again: ";
			continue;
		}
		if (value <= 0) continue;
		break;
	}
}

// Проверка: является ли полученное из файла число положительным.
void fcheck_positiv_int(int& value, ifstream& finput) {
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
	string route_number, start_point, end_point, departure_time;
	int value;
	while (true) {
		cin >> route_number >> start_point >> end_point >> departure_time;
		try {
			value = stoi(route_number);
		}
		catch (...) {
			cout << "Try again: ";
			continue;
		}
		if (!check_time(departure_time) || value <= 0) {
			cout << "Try again: ";
			continue;
		}
		break;
	}
	object = marsh(value, start_point, end_point, departure_time);
}

// Проверка: является ли полученный из файла маршрут корректным.
void fcheck_marsh(marsh& object, ifstream& finput) {
	string route_number, start_point, end_point, departure_time;
	int value;
	finput >> route_number >> start_point >> end_point >> departure_time;
	try {
		value = stoi(route_number);
	}
	catch (...) {
		cout << "Error: not number\n";
		return;
	}
	if (!check_time(departure_time)) {
		cout << "Error: not time\n";
		return;
	}
	object = marsh(value, start_point, end_point, departure_time);
}
