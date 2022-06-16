#include"train.h"
#include"inf_check.h"

train::train(const int number, const string& departure_time) :
	_number(number), _departure_time(departure_time) {
	//if (!check_time(departure_time)) throw str("train_error:bad_time");
}

train::train(const train& object) :
	_number(object._number),
	_departure_time(object._departure_time) {}

ostream& operator<<(ostream& output, const train& object) {
	output << "Route number: " << object._number << endl;
	output << "Departure time: " << object._departure_time << endl;
	return output;
}

int train::operator<(const train& object) const {
	// Если совпадает время отправки -> сравниваем номера маршрутов.
	if (_departure_time == object._departure_time)
		return _number < object._number;
	return _departure_time < object._departure_time;
}

int train::operator>(const train& object) const {
	// Если совпадает время отправки -> сравниваем номера маршрутов.
	if (_departure_time == object._departure_time)
		return _number > object._number;
	return _departure_time > object._departure_time;
}

int train::operator==(const train& object) const {
	return _number == object._number
		&& _departure_time == object._departure_time;
}

train& train::operator=(const train& object) {
	if (&object == this) return *this;
	_number = object._number;
	_departure_time = object._departure_time;
	return *this;
}