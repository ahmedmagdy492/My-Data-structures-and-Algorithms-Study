#include <iostream>

#include "MathExprParser.h"

int main() {
	MathExprParser mathParser;
	std::string result = mathParser.InfixToPostfix2("9-(2+3)");

	std::cout << result << std::endl;
}