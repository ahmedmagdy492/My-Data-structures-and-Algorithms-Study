#include <iostream>

#include "Utils.h"

#include "Stack.h"

#include <stack>

std::string reverse_subwords(std::string line) {
	Stack stack(line.length());
	std::string outString;

	for (char c : line) {
		if (c != ' ') {
			stack.push(c);
		}
		else {
			while (!stack.is_empty()) {
				outString += stack.pop();
			}
			outString += ' ';
		}
	}

	while (!stack.is_empty()) {
		outString += stack.pop();
	}

	return outString;
}

void test_reverse_subwords_normal_line() {
	std::string input = "abc d efg xy";
	std::string actual = reverse_subwords(input);
	std::string expected = "cba d gfe yx";

	std::cout << "Testing test_reverse_subwords_normal_line\n";
	assert(actual == expected);
}

bool is_brackets_valid(const std::string& str) {
	if(std::trim_start(str).length() == 0)
		return true;

	Stack stack(str.length());

	size_t str_len = str.length();
	for (int i = 0; i < str_len; ++i) {
		if (is_opening_bracket(str[i])) {
			stack.push(str[i]);
		}
		else if (is_closing_bracket(str[i])) {
			if (stack.is_empty())
				return false;

			int popped_bracket = stack.pop();
			if (!does_brackets_match(popped_bracket, str[i]))
				return false;
		}
	}

	return true;
}

void test_is_brackets_valid_2_parenth() {
	std::string input = "()";
	bool actual = is_brackets_valid(input);
	bool expected = true;

	std::cout << "test test_is_brackets_valid_2_parenth result:" << std::endl;
	std::cout << "actual: " << actual << ", expected: " << expected << "\n";
	assert(actual == expected);
}

void test_is_brackets_valid_4_parenth() {
	std::string input = "()()";
	bool actual = is_brackets_valid(input);
	bool expected = true;

	std::cout << "test test_is_brackets_valid_4_parenth result:" << std::endl;
	std::cout << "actual: " << actual << ", expected: " << expected << "\n";
	assert(actual == expected);
}

void test_is_brackets_valid_inner_4_parenth() {
	std::string input = "(()())";
	bool actual = is_brackets_valid(input);
	bool expected = true;

	std::cout << "test test_is_brackets_valid_4_parenth result:" << std::endl;
	std::cout << "actual: " << actual << ", expected: " << expected << "\n";
	assert(actual == expected);
}

void test_is_brackets_valid_inner_6_parenth() {
	std::string input = "(((())))";
	bool actual = is_brackets_valid(input);
	bool expected = true;

	std::cout << "test test_is_brackets_valid_4_parenth result:" << std::endl;
	std::cout << "actual: " << actual << ", expected: " << expected << "\n";
	assert(actual == expected);
}

void test_is_brackets_valid_3_different_brackets() {
	std::string input = "()[]{}";
	bool actual = is_brackets_valid(input);
	bool expected = true;

	std::cout << "test test_is_brackets_valid_4_parenth result:" << std::endl;
	std::cout << "actual: " << actual << ", expected: " << expected << "\n";
	assert(actual == expected);
}

void test_is_brackets_invalid_paranth() {
	std::string input = "(]";
	bool actual = is_brackets_valid(input);
	bool expected = false;

	std::cout << "test test_is_brackets_valid_4_parenth result:" << std::endl;
	std::cout << "actual: " << actual << ", expected: " << expected << "\n";
	assert(actual == expected);
}

void test_is_brackets_extra_bracket() {
	std::string input = "())";
	bool actual = is_brackets_valid(input);
	bool expected = false;

	std::cout << "test test_is_brackets_valid_4_parenth result:" << std::endl;
	std::cout << "actual: " << actual << ", expected: " << expected << "\n";
	assert(actual == expected);
}

void test_is_too_many_extra_brackets() {
	std::string input = "{}]]]]]]";
	bool actual = is_brackets_valid(input);
	bool expected = false;

	std::cout << "test test_is_brackets_valid_4_parenth result:" << std::endl;
	std::cout << "actual: " << actual << ", expected: " << expected << "\n";
	assert(actual == expected);
}

bool contains_adj_equal_chars(const std::string& str) {
	Stack stack(str.length());

	for (char c : str) {
		if (stack.is_empty()) {
			stack.push(c);
		}
		else {
			if (stack.peek() != c) {
				stack.clear();
				stack.push(c);
			}
			else {
				return true;
			}
		}
	}

	return false;
}

std::string remove_adj_substrings(const std::string& str) {
	if (str == "" || str.length() == 1) {
		return str;
	}

	Stack pocket(str.length());

	for (char c : str) {
		if (pocket.is_empty()) {
			pocket.push(c);
		}
		else {
			int lastChar = pocket.peek();
			if (c == lastChar) {
				pocket.pop();
			}
			else {
				pocket.push(c);
			}
		}
	}

	std::string out;
	while (!pocket.is_empty()) {
		int el = pocket.pop();
		out += el;
	}

	std::reverse(out.begin(), out.end());
	return out;
}

int main() {
	//// valid test cases
	//test_is_brackets_valid_2_parenth();
	//test_is_brackets_valid_4_parenth();
	//test_is_brackets_valid_inner_4_parenth();
	//test_is_brackets_valid_inner_6_parenth();
	//test_is_brackets_valid_3_different_brackets();

	//// invalid test cases
	//test_is_brackets_invalid_paranth();
	//test_is_brackets_extra_bracket();
	//test_is_too_many_extra_brackets();

	std::string input = "abbaca";
	std::string output = remove_adj_substrings(input);
	std::cout << output << "\n";

	std::string input2 = "abbaccaa";
	std::string output2 = remove_adj_substrings(input2);
	std::cout << output2 << "\n";
}