#include <iostream>

#include "Stack.h"

int main() {
	Stack stack(3);
	stack.push(10);
	stack.push(20);
	stack.push(30);

	stack.display();

	int value = 0;
	stack.pop(value);

	stack.display();
}