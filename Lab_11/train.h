#ifndef TRAIN_H
#define TRAIN_H

#include<iostream>
#include<string>
using namespace std;

class train {
private:
	// ����� ������ (����� ������ ��������).
	int _number;
	// ����� ��������.
	string _departure_time;

public:

	// ������������.
	train() : _number(0), _departure_time("00:00:00") {}
	train(const int route_number) : _number(route_number), _departure_time("00:00:00") {}
	train(const int, const string&);

	// ����������.
	~train() {}

	// �������.
	int get_number() const { return _number; }
	string get_departure_time() const { return _departure_time; }

	// ��������������� ����������.

	friend ostream& operator<<(ostream&, const train&);

	//��������� ��� �� ������� ��������
	//���� ����� ����������, ���������� �� ������� ���������

	int operator<(const train&) const;
	int operator>(const train&) const;
	int operator==(const train&) const;
	
	train& operator=(const train&);

};

#endif // TRAIN_H