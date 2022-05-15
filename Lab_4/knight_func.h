#ifndef _KNIGHT_FUNC_H_
#define _KNIGHT_FUNC_H_

//ѕоиск номера последней клетки строки (по формуле арифметической прогрессии)
int last_idx(int rows);

//ѕоиск номера р€да, в котором находитс€ элемент (по формуле корн€ квадратного уравнени€)
int definition_row(int idx);

//ѕоиск индекса по номеру строки и номеру его позиции в строке
int defindion_idx(int row, int startpos);

//ѕоиск индексов после хода кон€
void movement_options(int idx, int lastrow, int arr[6]);

//”даление лишних индексов - повтор€ющихс€ (сохран€етс€ только один из повтор€ющихс€)
//и индексов "отсутствующего хода" (0)
int delet_unsuitable_idx(int arr[36]);

//¬ывод всех номеров клеток, в которые конь попадает после второго хода
void output(int arr[36]);

#endif //_KNIGHT_FUNC_H_