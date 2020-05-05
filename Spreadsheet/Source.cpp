#include <iostream>
#include "Cell.h"
#include <string>
#include <vector>
#include "Spreadsheet.h"

int main()
{
	Spreadsheet s;
	std::cin >> s;
	s.calculate();
	std::cout << s;
	/*std::vector<int> num = { 3, 2, 1 };
	std::string oper = "+*";
	std::string text = "Text";
	Cell* a = new TextCell(text);
	Cell* b = new IntCell(125);
	Cell* c = new ExpCell(num, oper);
	Cell* d = new NullCell();
	a->calculate();
	b->calculate();
	c->calculate();
	d->calculate();
	a->print();
	std::cout << std::endl;
	b->print();
	std::cout << std::endl;
	c->print();
	std::cout << std::endl;
	d->print();
	std::cout << std::endl;*/
	return 0;
}