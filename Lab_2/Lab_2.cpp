//������� ��������� ���13-��
//������������ ������ �2. ������������������.
//���� ����������� n, ����� ����� �1, �2, ... ,�n.
//�������� ������������ ������

#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int n;
	float a;
	int max = 0;
	cin >> n;

	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767,'/n');
		cout << "Incorrect variable. Enter again" << endl;
		cin >> n;
	}
	for (n; n > 0; n--) {
		cin >> a;
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '/n');
			cout << "Incorrect variable. Enter again" << endl;
			cin >> a;
		}
		if (max < abs(a))
			max = abs(a);
	}
	cout << max;

	system("pause");
	return 0;
}