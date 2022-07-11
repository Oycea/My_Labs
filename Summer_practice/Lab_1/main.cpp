#include<iostream>
#include<fstream>
#include"Figure.h"
#include"Functions.h"
#include"Isosceles_triangle.h"
#include"List.h"
#include"Straight_prism.h"
using namespace std;

int main() {
	List<Figure*> figure_list;
	Isosceles_triangle triangle;
	Straight_prism prism;

	ifstream finput("input.txt");

	function_1(figure_list);
	function_2(figure_list);
	cout << endl;
	function_3(figure_list, triangle, prism);
	triangle.print();
	prism.print();

	finput.close();

	system("pause");
	return 0;
}