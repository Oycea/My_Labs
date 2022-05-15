#ifndef _FREQUENCY_ANALYSIS_H_
#define _FREQUENCY_ANALYSIS_H_

//���������� ������� �� ��������
double frequency_of_symbol(FILE* file, double count_symbol[77], double symbols_frequency[77]);

//����� ���������� ������ ����������
double count_punct_marks(double count_symbol[77]);

//������� ������� ��� ������� �� ������ ����������
double frequency_of_punct_marks(double count_symbol[77], double punct_marks_frequency[10]);

//��� ����� ����� ����������� ����� ����������
int three_common_punct_marks(double count_symbol[77], int i_most_common[3]);

//����� ������ ��������
int search_for_shift(double count_symbol[77]);

#endif //_FREQUENCY_ANALYSIS_H_