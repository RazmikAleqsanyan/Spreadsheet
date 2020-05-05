#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "SomeFunctions.h"

class Cell {
public:
	virtual ~Cell() {}

	virtual void calculate() = 0;
	virtual void print() const = 0;
	virtual bool isempty() const = 0;
	virtual std::string get() const = 0;
	virtual int* get_ref() = 0;
};

class NullCell : public Cell {
public:
	NullCell() {}

	void calculate() {}
	void print() const {
		std::cout << "#Null";
	}
	bool isempty() const {
		return true;
	}
	std::string get() const {
		return "#Null";
	}
	int* get_ref() {
		return 0;
	}
};

class IntCell : public Cell {
public:
	IntCell(int n) : m_number(n) {}

	void calculate() {}
	void print() const {
		std::cout << m_number;
	}
	bool isempty() const {
		return false;
	}
	std::string get() const {
		return int_to_string(m_number);
	}
	int* get_ref() {
		return &m_number;
	}
private:
	int m_number;
};

class TextCell : public Cell {
public:
	TextCell(const std::string& s) : m_text(s) {}

	void calculate() {}
	void print() const {
		std::cout << m_text;
	}
	bool isempty() const {
		return false;
	}
	std::string get() const {
		return m_text;
	}
	int* get_ref() {
		return 0;
	}
private:
	std::string m_text;
};

class ExpCell : public Cell {
public:
	ExpCell(std::vector<int> numbers, const std::string& operations)
		: m_number(numbers)
		, m_operation(operations)
		, m_result(0)
	{}
	~ExpCell() {}

	void calculate() {
		int size = m_operation.size() + 1;
		m_result = m_number[0];
		for (int i = 1; i < size; ++i) {
			m_result = operation(m_operation[i - 1], m_result, m_number[i]);
		}
	}
	void print() const {
		std::cout << m_result;
	}
	bool isempty() const {
		return false;
	}
	std::string get() const {
		return int_to_string(m_result);
	}
	int* get_ref() {
		return &m_result;
	}
private:
	std::vector<int> m_number;
	std::string m_operation;
	int m_result;
};