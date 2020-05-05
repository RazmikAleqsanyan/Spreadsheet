#include <iostream>
#include <string>
#include "Spreadsheet.h"
#include "SomeFunctions.h"
#include "Cell.h"

std::ostream& operator<<(std::ostream& ost, const Spreadsheet& s) {
	for (int i = 0; i < s.m_data.size(); ++i) {
		for (int j = 0; j < s.m_data[i].size(); ++j) {
			s.m_data[i][j]->print();
			std::cout << '\t';
		}
		std::cout << std::endl;
	}
	return ost;
}

std::istream& operator>>(std::istream& ist, Spreadsheet& s) {
	int length = 0;
	int hight = 0;
	ist >> hight >> length;
	for (int i = 0; i < s.m_data.size(); ++i) {
		s.m_data[i].clear();
	}
	s.m_data.clear();
	std::string line;
	getline(ist, line);
	for (int i = 0; i < hight; ++i) {
		getline(ist, line);
		std::vector<std::string> word = line_to_arr(line);
		std::vector<Cell*> data;
		for (int j = 0; j < length; ++j) {
			int size = word[j].size();
			if (is_number(word[j])) {
				Cell* NewCell = new IntCell(string_to_int(word[j]));
				data.push_back(NewCell);
				continue;
			}
			if (word[j][0] == '\"') {
				for (int i = 1; i <= size; ++i) {
					word[j][i - 1] = word[j][i];
				}
				word[j].resize(size - 1);
				Cell* NewCell = new TextCell(word[j]);
				data.push_back(NewCell);
				continue;
			}
			if (word[j][0] == '=') {
				int begin = 1;
				std::vector<int> number;
				std::string operation;
				if (isupper(word[j][begin])) {
					int ref_number = *s.m_data[word[j][begin] - 'A'][ word[j][begin + 1] - '0' - 1]->get_ref();
					number.push_back(ref_number);
					begin += 2;
				}
				else {
					number.push_back(get_value(word[j], begin, size));
				}
				for (; begin < size; ++begin) {
					if (isoperation(word[j][begin])) {
						operation.push_back(word[j][begin]);
						++begin;
					}
					if (isupper(word[j][begin])) {
						int ref_number = *s.m_data[word[j][begin] - 'A'][word[j][begin + 1] - '0' - 1]->get_ref();
						number.push_back(ref_number);
						begin += 2;
					}
					if (isoperation(word[j][begin])) {
						operation.push_back(word[j][begin]);
						++begin;
					}
					number.push_back(get_value(word[j], begin, size));
				}
				Cell* NewCell = new ExpCell(number, operation);
				data.push_back(NewCell);
				continue;
			}
			if (word[j][0] == ' ') {
				Cell* NewCell = new NullCell();
				data.push_back(NewCell);
				continue;
			}
			std::cout << "#error";
			continue;
		}
		s.m_data.push_back(data);
	}
	return ist;
}

void Spreadsheet::calculate() {
	for (int i = 0; i < m_data.size(); ++i) {
		for (int j = 0; j < m_data[i].size(); ++j) {
			m_data[i][j]->calculate();
		}
	}
}

int Spreadsheet::convert(char a, char b) const {
	return 0;
}