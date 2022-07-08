#include"marsh.h"
#include"inf_check.h"

marsh::marsh(const int route_number, const string& start_point, const string& end_point,
			 const string& departure_time) :
	_route_number(route_number),
	_start_point(start_point),
	_end_point(end_point),
	_departure_time(departure_time) {
	if (!check_time(departure_time)) throw string("ERROR: bad time!");
}

marsh::marsh(const marsh& object) :
	_route_number(object._route_number),
	_start_point(object._start_point),
	_end_point(object._end_point),
	_departure_time(object._departure_time) {}

ostream& operator<<(ostream& output, const marsh& object) {
	output << "Route number: " << object._route_number << " ";
	output << "Starting point of the route: " << object._start_point << " ";
	output << "End point of the route: " << object._end_point << " ";
	output << "Departure time: " << object._departure_time << endl;
	return output;
}

marsh& marsh::operator=(const marsh& object) {
	if (&object == this) return *this;
	_route_number = object._route_number;
	_start_point = object._start_point;
	_end_point = object._end_point;
	_departure_time = object._departure_time;
	return *this;
}

int marsh::operator<(const marsh& object) const {
	if (_route_number == object._route_number)
		return _departure_time < object._departure_time;
	return _route_number < object._route_number;
}

int marsh::operator>(const marsh& object) const {
	if (_route_number == object._route_number)
		return _departure_time > object._departure_time;
	return _route_number > object._route_number;
}

int marsh::operator==(const marsh& object) const {
	return  _route_number == object._route_number &&
		_start_point == object._start_point
		&& _end_point == object._end_point
		&& _departure_time == object._departure_time;
}
