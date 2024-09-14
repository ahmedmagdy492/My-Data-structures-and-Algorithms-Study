#include <iostream>

#include "Utils.h"

#include "Stack.h"

int main() {
	Stack stk(10);
	stk.push(2, 5);
	stk.push(2, 6);
	stk.pop(2);
	stk.push(2, 7);
	stk.push(2, 9);

	stk.push(1, 4);
	std::cout << stk.peek(1) << "\n";
	std::cout << stk.peek(2) << "\n";
	stk.push(1, 6);
	stk.push(1, 8);
	stk.push(2, 3);
	stk.display();
}