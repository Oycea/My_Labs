#ifndef INF_CHECK_H
#define INF_CHECK_H

#include<string>
#include<iostream>
#include<fstream>
#include"marsh.h"
using namespace std;

// Проверка: корректно ли имя файла.
void check_file_name(string&);

// Проверка: является ли введённое число положительным.
void check_pos_int(int&);
// Проверка: является ли полученное из файла число положительным.
void fcheck_pos_int(int&, ifstream&);

// Проверка: является ли введённый маршрут корректным.
void check_marsh(marsh& object);
// Проверка: является ли полученный из файла маршрут корректным.
void fcheck_marsh(marsh&, ifstream&);

#endif // INF_CHECK_H