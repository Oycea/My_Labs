#include"menu.h"

#include <iostream>
#include <fstream>

void read_enter() {
	string buff;
	getline(cin, buff);
}

// Функция считывает один элемент и добавляет его в древо.
void input_one_item(bin_tree<marsh>& my_tree) {
	marsh item;
	cout << "Enter: " << endl << "1) Starting point of the route" << endl
		<< "2) End point of the route" << endl
		<< "3) Route number" << endl << "Enter item: ";
	check_marsh(item);
	cin.get();
	my_tree.add_node(item);
}

// Функция ввода всего дерева клавиатуры.
void input_tree(bin_tree<marsh>& my_tree) {
	int num;
	cout << "Enter the number of routes: ";
	check_pos_int(num);
	cin.get();
	cout << "Enter: " << endl << "1) Starting point of the route" << endl
		<< "2) End point of the route" << endl
		<< "3) Route number" << endl;
	for (int i = 0; i < num; i++) {
		marsh item;
		cout << "Enter item: ";
		check_marsh(item);
		cin.get();
		my_tree.add_node(item);
	}
}

// Функция ввода всего дерева из файла.
void finput_tree(bin_tree<marsh>& my_tree) {
	string file_name;
	cout << "Enter file name: ";
	check_file_name(file_name);
	cin.get();
	ifstream finput(file_name);
	int num;
	fcheck_pos_int(num, finput);
	for (int i = 0; i < num; i++) {
		marsh item;
		fcheck_marsh(item, finput);
		my_tree.add_node(item);
	}
	finput.close();
}

// Функция удаляет введенный элемент из дерева.
void delete_item(bin_tree<marsh>& my_tree) {
	marsh item;
	cout << "Enter: " << endl << "1) Starting point of the route" << endl
		<< "2) End point of the route" << endl
		<< "3) Route number" << endl << "Enter item: ";
	check_marsh(item);
	cin.get();
	my_tree.balance_remove(item);
}

// Функция определяет, есть ли введенный элемент в дереве.
void find_item(bin_tree<marsh>& my_tree) {
	marsh item;
	cout << "Enter: " << endl << "1) Starting point of the route" << endl
		<< "2) End point of the route" << endl
		<< "3) Route number" << endl << "Enter item: ";
	check_marsh(item);
	bin_tree_node<marsh>* pos= my_tree.find(item);
	if (pos) {
		cout << "Item found" << endl;
		cin.get();
		return;
	}
	cout << "Item not found" << endl;
	cin.get();
}

// Функция редактирования запрошенного пользователем элемента.
void edit_item(bin_tree<marsh>& my_tree) {
	marsh item;
	cout << "Enter: " << endl << "1) Starting point of the route" << endl
		<< "2) End point of the route" << endl
		<< "3) Route number" << endl << "Enter item: ";
	check_marsh(item);
	bin_tree_node<marsh>* pos = my_tree.find(item);
	if (!pos) {
		cout << "Item not found" << endl;
		cin.get();
		return;
	}
	my_tree.balance_remove(item);
	cout << "Enter new item: ";
	check_marsh(item);
	cin.get();
	my_tree.add_node(item);
}

// Функция сравнивает пункты назначения двух поездов.
//bool cmp_destination_name(const marsh& first, const marsh& second) {
//	return first.destination_name() == second.destination_name();
//}

// Функция выводит все поезда с введенным пунктом назначения.
//void print_with_same_name(bin_tree<marsh>& my_tree) {
//	string name;
//	cout << "Enter destination name: ";
//	cin >> name;
//	cin.get();
//	int count_item = my_tree.print_lnr(cmp_destination_name, marsh(name, 0, "00:00:00"));
//	if (!count_item) cout << "No items\n";
//}

// Функция сравнивает время отправки поездов.
//bool cmp_departure_time(const marsh& first, const marsh& second) {
//	return first.departure_time() > second.departure_time();
//}

// Функция выводит все поезда, которые отправляются после введенного времени.
//void print_after_set_time(bin_tree<marsh>& my_tree) {
//	string departure_time;
//	cout << "Enter departure time{hh:mm:ss}: ";
//	input_time(departure_time);
//	// Убираем мусор из потока.
//	cin.get();
//	int count_item = my_tree.print_lnr(cmp_departure_time, marsh("", 0, departure_time));
//	if (!count_item) cout << "No items\n";
//}

// Вывод пунктов первого меню и выбор пункта.
int choise_build_menu() {
	int choice;
	system("clear");
	cout << "Build Tree Menu\n"
		<< "1 - Keyboard input\n"
		<< "2 - File input\n"
		<< "3 - Quit\n"
		<< "Please choose: ";
	check_pos_int(choice);
	cin.get();
	return choice;
}

// Вывод пунктов второго меню и выбор пункта.
int choise_main_menu() {
	int choice;
	system("clear");
	cout << "Main Menu\n"
		<< "1 - Add item\n"
		<< "2 - Delete item\n"
		<< "3 - Find item\n"
		<< "4 - Edit item\n"
		<< "5 - Print tree\n"
		<< "6 - Print with the same name\n"
		<< "7 - Print after a set time\n"
		<< "8 - Quit\n"
		<< "Please choose: ";
	check_pos_int(choice);
	cin.get();
	return choice;
}

// Цикл второго меню.
void main_menu(bin_tree<marsh>& my_tree) {
	int choice;
	while (true) {
		choice = choise_main_menu();
		switch (choice) {
		case 1:
			input_one_item(my_tree);
			break;
		case 2:
			delete_item(my_tree);
			break;
		case 3:
			find_item(my_tree);
			cout << "Press enter...";
			read_enter();
			break;
		case 4:
			edit_item(my_tree);
			cout << "Press enter...";
			read_enter();
			break;
		case 5:
			my_tree.print();
			cout << "Press enter...";
			read_enter();
			break;
		case 6:
			print_with_same_name(my_tree);
			cout << "Press enter...";
			read_enter();
			break;
		case 7:
			print_after_set_time(my_tree);
			cout << "Press enter...";
			read_enter();
			break;
		case 8:
			system("clear");
			return;
		default:
			cout << "No such item\nPress enter...";
			read_enter();
			continue;
		}
	}
}

// Цикл первого меню.
void build_menu(bin_tree<marsh>& my_tree) {
	int choice;
	while (true) {
		choice = choise_build_menu();
		switch (choice) {
		case 1:
			input_tree(my_tree);
			break;
		case 2:
			finput_tree(my_tree);
			cout << "Press enter...";
			read_enter();
			break;
		case 3:
			system("clear");
			return;
		default:
			cout << "No such item\nPress enter...";
			read_enter();
			continue;
		}
		break;
	}
	main_menu(my_tree);
}