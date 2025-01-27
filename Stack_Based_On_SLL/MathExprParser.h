#pragma once

#include <iostream>
#include "Stack.h"

class MathExprParser {
private:
	float PerformBinaryOperation(float op1, float op2, char operation);
	inline float ConvertStringDigitToInt(char c);

public:

	enum AssociativityType : unsigned char {
		LeftToRight = 0,
		RightToLeft
	};

	MathExprParser();
	~MathExprParser();

	bool IsOperator(char value);
	int Presedence(char op);
	std::string InfixToPostfix(const std::string& infix);
	std::string InfixToPostfix2(const std::string& infix);
	std::string ReversedInfixToPostfix(const std::string& infix);
	std::string InfixToPrefix(const std::string& infix);
	AssociativityType GetOperatorAssociativity(char op);

	float EvaluatePostfix(const std::string& postfix);
};