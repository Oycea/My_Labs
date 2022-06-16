#include"inf_check.h"

// ��������: ��������� �� ��� �����.
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

// ��������: �������� �� �������� ����� �������������.
void check_pos_int(int& num) {
	cin >> num;
	while (cin.fail() || num <= 0) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "ERROR! Is not a positive integer number!";
		cin >> num;
	}
}

// ��������: �������� �� ���������� �� ����� ����� �������������.
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

// ��������: �������� �� �������� ������� ����������.
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

// ��������: �������� �� ���������� �� ����� ������� ����������.
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