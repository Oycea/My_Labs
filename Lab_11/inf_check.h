#ifndef INF_CHECK_H
#define INF_CHECK_H

#include<string>
#include<iostream>
#include<fstream>
#include"marsh.h"
using namespace std;

// ��������: ��������� �� ��� �����.
void check_file_name(string&);

// ��������: �������� �� �������� ����� �������������.
void check_pos_int(int&);
// ��������: �������� �� ���������� �� ����� ����� �������������.
void fcheck_pos_int(int&, ifstream&);

// ��������: �������� �� �������� ������� ����������.
void check_marsh(marsh& object);
// ��������: �������� �� ���������� �� ����� ������� ����������.
void fcheck_marsh(marsh&, ifstream&);

#endif // INF_CHECK_H