
#include "MathExprParser.h"

MathExprParser::MathExprParser() {

}

MathExprParser::~MathExprParser() {

}


bool MathExprParser::IsOperator(char value) {
	switch (value) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
		return true;
	}

	return false;
}

int MathExprParser::Presedence(char op) {
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	if (op == '^')
		return 3;
	return 0;
}

MathExprParser::AssociativityType MathExprParser::GetOperatorAssociativity(char op) {
	switch (op) {
	case '+':
	case '-':
	case '*':
	case '/':
		return MathExprParser::AssociativityType::LeftToRight;
	}

	return MathExprParser::AssociativityType::RightToLeft;
}

std::string MathExprParser::InfixToPostfix(const std::string& infix) {
	Stack operators;
	std::string postfix;

	for (int i = 0; i < infix.length(); ++i) {
		char c = infix[i];
		if (std::isdigit(c)) {
			postfix += c;
		}
		else if (std::isalpha(c)) {
			postfix += c;
		}
		else if (IsOperator(c)) {
			if (operators.empty()) {
				operators.push(c);
			}
			else {
				while (!operators.empty() && Presedence(operators.peek()) >= Presedence(c)) {
					auto opAssoc = GetOperatorAssociativity(operators.peek());
					if (Presedence(operators.peek()) == Presedence(c) && opAssoc == MathExprParser::AssociativityType::RightToLeft) {
						break;
					}
					else {
						if (IsOperator(operators.peek())) {
							postfix += operators.pop();
						}
						else {
							operators.pop();
						}
					}
				}
				operators.push(c);
			}
		}
		else if (c == '(') {
			operators.push(c);
		}
		else if (c == ')') {
			while (!operators.empty() && operators.peek() != '(') {
				if (IsOperator(operators.peek())) {
					postfix += operators.pop();
				}
				else {
					operators.pop();
				}
			}

			if (!operators.empty() && operators.peek() == '(') {
				operators.pop();
			}
		}
	}

	while (!operators.empty()) {
		if (IsOperator(operators.peek())) {
			postfix += operators.pop();
		}
		else {
			operators.pop();
		}
	}

	return postfix;
}


std::string MathExprParser::InfixToPostfix2(const std::string& infix) {
	Stack operators;
	std::string postfix;
	bool isInDistMode = false;

	for (int i = 0; i < infix.length(); ++i) {
		char c = infix[i];
		if (std::isdigit(c)) {
			postfix += c;
		}
		else if (std::isalpha(c)) {
			postfix += c;
		}
		else if (IsOperator(c)) {
			if (operators.empty()) {
				operators.push(c);
			}
			else {
				while (!operators.empty() && Presedence(operators.peek()) >= Presedence(c)) {
					auto opAssoc = GetOperatorAssociativity(operators.peek());
					if (Presedence(operators.peek()) == Presedence(c) && opAssoc == MathExprParser::AssociativityType::RightToLeft) {
						break;
					}
					else {
						if (IsOperator(operators.peek())) {
							postfix += operators.pop();
						}
						else {
							operators.pop();
						}
					}
				}
				operators.push(c);
			}
		}
		else if (c == '(') {
			if (i != 0 && infix[i-1] == '-') {
				isInDistMode = true;
				std::cout << "Distrubitive Mode Enabled: i = " << i << std::endl;
			}
			operators.push(c);
		}
		else if (c == ')') {
			while (!operators.empty() && operators.peek() != '(') {
				if (IsOperator(operators.peek())) {
					postfix += operators.pop();
				}
				else {
					operators.pop();
				}
			}

			if (!operators.empty() && operators.peek() == '(') {
				operators.pop();
			}
			isInDistMode = false;
			std::cout << "Distrubitive Mode Disabled: i = " << i << std::endl;
		}
	}

	while (!operators.empty()) {
		if (IsOperator(operators.peek())) {
			postfix += operators.pop();
		}
		else {
			operators.pop();
		}
	}

	return postfix;
}

std::string MathExprParser::ReversedInfixToPostfix(const std::string& infix) {
	Stack operators;
	std::string postfix;

	for (int i = 0; i < infix.length(); ++i) {
		char c = infix[i];
		if (std::isdigit(c)) {
			postfix += c;
		}
		else if (std::isalpha(c)) {
			postfix += c;
		}
		else if (IsOperator(c)) {
			if (operators.empty()) {
				operators.push(c);
			}
			else {
				while (!operators.empty() && Presedence(operators.peek()) >= Presedence(c)) {
					auto opAssoc = GetOperatorAssociativity(operators.peek());
					if (Presedence(operators.peek()) == Presedence(c) && opAssoc == MathExprParser::AssociativityType::RightToLeft) {
						if (IsOperator(operators.peek())) {
							postfix += operators.pop();
						}
						else {
							operators.pop();
						}
					}
					else {
						break;
					}
				}
				operators.push(c);
			}
		}
		else if (c == '(') {
			operators.push(c);
		}
		else if (c == ')') {
			while (!operators.empty() && operators.peek() != '(') {
				if (IsOperator(operators.peek())) {
					postfix += operators.pop();
				}
				else {
					operators.pop();
				}
			}

			if (!operators.empty() && operators.peek() == '(') {
				operators.pop();
			}
		}
	}

	while (!operators.empty()) {
		if (IsOperator(operators.peek())) {
			postfix += operators.pop();
		}
		else {
			operators.pop();
		}
	}

	return postfix;
}

std::string MathExprParser::InfixToPrefix(const std::string& infix) {
	return infix;
}

float MathExprParser::PerformBinaryOperation(float op1, float op2, char operation) {
	float result = 0.0f;

	switch (operation) {
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		if (op2 == 0)
			throw std::runtime_error("dividing by 0");
		return op1 / op2;
	case '^':
		return std::pow(op1, op2);
	}

	return result;
}

inline float MathExprParser::ConvertStringDigitToInt(char c) {
	return c - 48;
}

float MathExprParser::EvaluatePostfix(const std::string& postfix) {
	float result = 0.0f;

	if (postfix == "")
		return result;

	Stack values;

	for (int i = 0; i < postfix.length(); ++i) {
		char c = postfix[i];
		if (std::isdigit(c)) {
			values.push(ConvertStringDigitToInt(c));
		}
		else if (IsOperator(c)) {
			float num2 = values.pop();
			float num1 = values.pop();
			values.push(PerformBinaryOperation(num1, num2, c));
		}
	}

	result = values.pop();

	return result;
}