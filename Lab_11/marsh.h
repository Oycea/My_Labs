#ifndef MARSH_H
#define MARSH_H

#include<iostream>
#include<string>
using namespace std;

class marsh{
private:
	// ��������� � �������� ������ ��������.
	string _start_point, _end_point;
	// ����� ��������.
	int _route_number;

public:

	// ������������.
	marsh() : _start_point(""), _end_point(""), _route_number(0) {}
	marsh(const string&, const string&, const int);
	marsh(const marsh&);

	// ����������.
	~marsh() {}

	// �������.
	string get_start_point() const { return _start_point; }
	string get_end_point() const { return _end_point; }
	int get_route_number() const { return _route_number; }

	// ��������������� ����������.

	friend ostream& operator<<(ostream&, const marsh&);

	//��������� ��� �� ������� ���������.
	int operator<(const marsh&) const;
	int operator>(const marsh&) const;
	int operator==(const marsh&) const;

	marsh& operator=(const marsh&);

};

#endif // MARHS_H