#include <iostream>

#include "Stack.h"

int main() {
	Stack stack;

	stack.push(12);
	stack.push(44);
	stack.push(39);

	stack.display();

	int lastValue = stack.pop();
	std::cout << "last: " << lastValue << std::endl;

	std::cout << "peeked value: " << stack.peek() << std::endl;
}