#ifndef FIGURE_H
#define FIGURE_H

#include<string>
using namespace std;

class Figure {
public:
	virtual ~Figure() {};

	void virtual print() = 0;
	string virtual type() const = 0;
};

#endif // ISHAPE_H