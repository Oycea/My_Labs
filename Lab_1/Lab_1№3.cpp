//������� ��������� ���13-��
//������������ ������ �5. �����������, �������������, ��������� ������
//
//�������������� ����� �������
//����� ���������, ����������� �� ����� ����������� ������� �� ���������. ����� �������� ����� �������������
//������������.� ������ ������ - ������

#include<iostream>
using namespace std;

int main() {
	double x, y; //����������

	cout << "Enter x: " << endl;
	cin >> x;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Incorrect variable. Enter again" << endl;
		cin >> x;
	}

	cout << "Enter y: " << endl;
	cin >> y;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Incorrect variable. Enter again" << endl;
		cin >> y;
	}

	if (((x > 0) && (x < 2) && (y > 0)) || (x > 2) || (x < -5) || ((x < 0) && (y < 0)) 
		|| ((x < -5) && (y > 0)) || ((x > -5) && (y > 5)) || ((x < -2) && (x > -4) && (y > 2) && (y < 4)) || 
		((x > 0) && (y < 0) && (x * x + y * y > 4)))
		cout << "x doesn't belong to the area" << endl;
	else 
		cout << "x belong to the area" << endl;

	system("pause");
	return 0;
}