#include"marsh.h"

marsh::marsh(const string& start_point, const string& end_point, const int route_number) :
	_start_point(start_point), 
	_end_point(end_point), 
	_route_number(route_number){
	//if (!check_time(departure_time)) throw str("train_error:bad_time");
}

marsh::marsh(const marsh& object) :
	_start_point(object._start_point),
	_end_point(object._end_point),
	_route_number(object._route_number) {}

ostream& operator<<(ostream& output, const marsh& object) {
	output << "Starting point of the route: " << object._start_point << endl;
	output << "End point of the route: " << object._end_point << endl;
	output << "Route number: " << endl;
	return output;
}

int marsh::operator<(const marsh& object) const {
	return _route_number < object._route_number;
}

int marsh::operator>(const marsh& object) const {
	return _route_number > object._route_number;
}

int marsh::operator==(const marsh& object) const {
	return _start_point == object._start_point
		&& _end_point == object._end_point
		&& _route_number == object._route_number;
}

marsh& marsh::operator=(const marsh& object) {
	if (&object == this) return *this;
	_start_point = object._start_point;
	_end_point = object._end_point;
	_route_number = object._route_number;
	return *this;
}