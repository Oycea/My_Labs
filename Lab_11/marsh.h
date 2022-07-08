#ifndef MARSH_H
#define MARSH_H

#include<iostream>
#include<string>
using namespace std;

class marsh {
private:
	// Номер маршрута.
	int _route_number;
	// Начальный и конечный пункты маршрута.
	string _start_point, _end_point;
	// Время движения по маршруту.
	string _departure_time;

public:

	// КОНСТРУКТОРЫ.
	marsh() : _route_number(0), _start_point(""), _end_point(""), _departure_time("00:00:00") {}
	marsh(const int, const string&, const string&, const string&);
	marsh(const marsh&);

	// ДЕСТРУКТОР.
	~marsh() {}

	// ГЕТТЕРЫ.
	int get_route_number() const { return _route_number; }
	string get_start_point() const { return _start_point; }
	string get_end_point() const { return _end_point; }
	string get_departure_time() const { return _departure_time; }

	// ПЕРЕОПРЕДЕЛЕНИЕ ОПЕРАТОРОВ.

	friend ostream& operator<<(ostream&, const marsh&);

	marsh& operator=(const marsh&);

	// Сравнение идёт по номерам маршрутов
	// Если они равны - то по времени движения поезда.
	int operator<(const marsh&) const;
	int operator>(const marsh&) const;
	int operator==(const marsh&) const;

};

#endif // MARHS_H
