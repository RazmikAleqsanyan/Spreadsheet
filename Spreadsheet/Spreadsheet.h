#pragma once

#include <iostream>
#include <vector>
#include "Cell.h"

class Spreadsheet {
	friend std::ostream& operator<<(std::ostream&, const Spreadsheet&);
	friend std::istream& operator>>(std::istream&, Spreadsheet&);
public:
	Spreadsheet() {}

	Cell& operator()(int i, int j) {
		return *m_data[i][j];
	}
	const Cell& operator()(int i, int j) const {
		return *m_data[i][j];
	}
	void calculate();
	int convert(char, char) const;
private:
	std::vector<std::vector<Cell*>> m_data;
};