#include <iostream>

#include "Utils.h"

#include "Stack.h"

#include <stack>
#include <queue>
#include <vector>

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


bool areGoingToCollide(int left, int right) {
	return left > 0 && right < 0;
}

std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
	std::stack<int> stack;

	for (int i = 0; i < asteroids.size(); ++i) {
		if (stack.empty()) {
			stack.push(asteroids[i]);
		}
		else {
			int stackTop = stack.top();
			if (areGoingToCollide(stackTop, asteroids[i])) {
				if (abs(stackTop) < abs(asteroids[i])) {
					stack.pop();

					if (stack.empty()) {
						stack.push(asteroids[i]);
					}
					else {
						while (!stack.empty()) {
							stackTop = stack.top();
							if (areGoingToCollide(stackTop, asteroids[i])) {
								if (abs(stackTop) < abs(asteroids[i])) {
									stack.pop();
									if (stack.empty()) {
										stack.push(asteroids[i]);
										break;
									}
								}
								else if (abs(stackTop) == abs(asteroids[i])) {
									stack.pop();
									break;
								}
								else {
									break;
								}
							}
							else {
								stack.push(asteroids[i]);
								break;
							}
						}
					}
				}
				else if(abs(stackTop) == abs(asteroids[i])) {
					stack.pop();
				}
			}
			else {
				stack.push(asteroids[i]);
			}
		}
	}

	std::vector<int> out(stack.size());
	int counter = stack.size() - 1;

	while (!stack.empty()) {
		out[counter--] = stack.top();
		stack.pop();
	}

	return out;
}

int parenthises_score(std::string& str) {
	if (str == "")
		return 0;

	Stack stack(str.length());

	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '(') {
			stack.push(0);
		}
		else {
			int popped_value = stack.pop();

			if (popped_value == 0)
				popped_value = 1;
			else
				popped_value *= 2;

			if (!stack.is_empty()) {
				int parent_score = stack.pop() + popped_value;
				stack.push(parent_score);
			}
			else {
				stack.push(popped_value);
			}
		}
	}

	return stack.pop();
}

std::vector<int> nextGreaterElements(std::vector<int>& nums) {
	std::stack<std::pair<int, int>> stack;

	for (int i = 0; i < nums.size(); ++i) {
		if (stack.empty()) {
			stack.push(std::pair<int, int>(i, nums[i]));
		}
		else {
			if (nums[i] > stack.top().second) {
				while (!stack.empty() && stack.top().second < nums[i]) {
					int index = stack.top().first;
					stack.pop();
					nums[index] = nums[i];
				}
				stack.push(std::pair<int, int>(i, nums[i]));
			}
			else {
				stack.push(std::pair<int, int>(i, nums[i]));
			}
		}
	}

	while (!stack.empty()) {
		int index = stack.top().first;
		stack.pop();
		nums[index] = -1;
	}

	return nums;
}

void next_higher_value_test1() {
	std::vector<int> arr = { 10, 5, 7, 15, 11 };
	std::vector<int> list = nextGreaterElements(arr);

	for (int num : list) {
		std::cout << num << std::endl;
	}
}

void next_higher_value_test2() {
	std::vector<int> arr = { 8, 73, 74, 75, 71, 69, 72, 76, 73 };
	std::vector<int> list = nextGreaterElements(arr);

	for (int num : list) {
		std::cout << num << std::endl;
	}
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

	/*std::string input = "abbaca";
	std::string output = remove_adj_substrings(input);
	std::cout << output << "\n";

	std::string input2 = "abbaccaa";
	std::string output2 = remove_adj_substrings(input2);
	std::cout << output2 << "\n";*/

	/*std::vector<int> astroids;
	astroids.push_back(-2);
	astroids.push_back(-1);
	astroids.push_back(1);
	astroids.push_back(2);
	std::vector<int> result = asteroidCollision(astroids);*/

	/*Stack stack(10);

	stack.push(12);
	stack.push(44);
	stack.push(55);
	stack.push(99);

	std::cout << "Before Reverse\n";
	stack.display();
	std::cout << "==============\n";

	stack.reverse();

	std::cout << "After Reverse\n\n";

	stack.display();*/

	/*std::string input1 = "()";
	std::cout << parenthises_score(input1) << "\n";

	std::string input2 = "(())";
	std::cout << parenthises_score(input2) << "\n";

	std::string input3 = "()()";
	std::cout << parenthises_score(input3) << "\n";

	std::string input4 = "(()())";
	std::cout << parenthises_score(input4) << "\n";

	std::string input5 = "(()(()))";
	std::cout << parenthises_score(input5) << "\n";*/

	/*std::string input6 = "()((())())";
	std::cout << parenthises_score(input6) << "\n";*/

	next_higher_value_test2();
}