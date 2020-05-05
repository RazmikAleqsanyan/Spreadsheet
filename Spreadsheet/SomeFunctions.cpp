#include "SomeFunctions.h"
#include <cctype>

bool isoperation(char x) {
	if (x == '+' || x == '-' || x == '*' || x == '/') {
		return true;
	}
	return false;
}

int converter(char, char) {
	return 0;
}

int get_value(std::string& exp, int& begin, const int size) {
	int value = 0;
	/*if (isupper(exp[begin])) {
		value = converter(exp[begin], exp[begin + 1]);
		begin += 2;
	}*/
	for (; begin <= size; ++begin) {
		if (isdigit(exp[begin])) {
			value *= 10;
			value += exp[begin] - '0';
		}
		else {
			break;
		}
	}
	return value;
}

int operation(const char a, int x, int y) {
	if (a == '+') {
		return x + y;
	}
	if (a == '-') {
		return x - y;
	}
	if (a == '/') {
		return x / y;
	}
	if (a == '*') {
		return x * y;
	}
	return 0;
}

bool is_number(std::string& s) {
	for (int i = 0; i < s.size(); ++i) {
		if (!isdigit(s[i])) {
			return false;
		}
	}
	return true;
}

int string_to_int(std::string& s) {
	int number = 0;
	if (is_number(s)) {
		for (int i = 0; i < s.size(); ++i) {
			number *= 10;
			number += s[i] - '0';
		}
	}
	return number;
}

std::string int_to_string(int n) {
	std::string s;
	while (n != 0) {
		s.push_back(n % 10 + '0');
		n /= 10;
	}
	std::string reverse;
	for (int i = s.size() - 1; i >= 0; --i) {
		reverse.push_back(s[i]);
	}
	return reverse;
}

std::vector<std::string> line_to_arr(std::string& s) {
	std::vector<std::string> line;
	std::string word;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '\t') {
			line.push_back(word);
			word.clear();
			++i;
		}
		word.push_back(s[i]);
	}
	line.push_back(word);
	return line;
}