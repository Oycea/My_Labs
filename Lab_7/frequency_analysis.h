#ifndef _FREQUENCY_ANALYSIS_H_
#define _FREQUENCY_ANALYSIS_H_

//Количество каждого из символов
double frequency_of_symbol(FILE* file, double count_symbol[77], double symbols_frequency[77]);

//Общее количество знаков препинания
double count_punct_marks(double count_symbol[77]);

//Средняя частота для каждого из знаков препинания
double frequency_of_punct_marks(double count_symbol[77], double punct_marks_frequency[10]);

//Три самых часто встречаемых знака препинания
int three_common_punct_marks(double count_symbol[77], int i_most_common[3]);

//Поиск сдвига алфавита
int search_for_shift(double count_symbol[77]);

#endif //_FREQUENCY_ANALYSIS_H_