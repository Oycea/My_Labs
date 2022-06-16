#ifndef TRAIN_H
#define TRAIN_H

#include<iostream>
#include<string>
using namespace std;

class train {
private:
	// Номер поезда (равен номеру маршрута).
	int _number;
	// Время отправки.
	string _departure_time;

public:

	// КОНСТРУКТОРЫ.
	train() : _number(0), _departure_time("00:00:00") {}
	train(const int route_number) : _number(route_number), _departure_time("00:00:00") {}
	train(const int, const string&);

	// ДЕСТРУКТОР.
	~train() {}

	// ГЕТТЕРЫ.
	int get_number() const { return _number; }
	string get_departure_time() const { return _departure_time; }

	// ПЕРЕОПРЕДЕЛЕНИЕ ОПЕРАТОРОВ.

	friend ostream& operator<<(ostream&, const train&);

	//Сравнение идёт по времени отправки
	//Если время одинаковое, сравниваем по номерам маршрутов

	int operator<(const train&) const;
	int operator>(const train&) const;
	int operator==(const train&) const;
	
	train& operator=(const train&);

};

#endif // TRAIN_H