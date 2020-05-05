#pragma once

#include <string>
#include <vector>

bool isoperation(char);
int converter(char, char);

int get_value(std::string&, int&, const int);
int operation(const char, int, int);
bool is_number(std::string&);
int string_to_int(std::string&);
std::string int_to_string(int);
std::vector<std::string> line_to_arr(std::string&);