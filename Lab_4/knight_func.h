#ifndef _KNIGHT_FUNC_H_
#define _KNIGHT_FUNC_H_

//����� ������ ��������� ������ ������ (�� ������� �������������� ����������)
int last_idx(int rows);

//����� ������ ����, � ������� ��������� ������� (�� ������� ����� ����������� ���������)
int definition_row(int idx);

//����� ������� �� ������ ������ � ������ ��� ������� � ������
int defindion_idx(int row, int startpos);

//����� �������� ����� ���� ����
void movement_options(int idx, int lastrow, int arr[6]);

//�������� ������ �������� - ������������� (����������� ������ ���� �� �������������)
//� �������� "�������������� ����" (0)
int delet_unsuitable_idx(int arr[36]);

//����� ���� ������� ������, � ������� ���� �������� ����� ������� ����
void output(int arr[36]);

#endif //_KNIGHT_FUNC_H_