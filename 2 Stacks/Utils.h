#pragma once

#include <iostream>

namespace std {
	std::string trim_start(const std::string& str) {
		size_t len = str.length();
		bool encounteredChar = false;
		std::string newStr;

		for (int i = 0; i < len; ++i) {
			if (str[i] != ' ') {
				encounteredChar = true;
			}
			if(encounteredChar) {
				newStr += str[i];
			}
		}

		return newStr;
	}
}

bool is_opening_bracket(char c) {
	return c == '(' || c == '[' || c == '{';
}

bool is_closing_bracket(char c) {
	return c == ')' || c == ']' || c == '}';
}

bool does_brackets_match(char first, char other) {
	if (first == '(' && other == ')')
		return true;
	if (first == '[' && other == ']')
		return true;
	if (first == '{' && other == '}')
		return true;

	return false;
}