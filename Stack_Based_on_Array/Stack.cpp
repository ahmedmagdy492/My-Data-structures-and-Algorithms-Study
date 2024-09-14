#include "Stack.h"

Stack::Stack(size_t size) : size(size) {
	arr = new int[size];
}

void Stack::push(int value) {
	if(is_full())
		throw std::string("Stack is full");
	
	arr[++top] = value;
}

int Stack::pop() {
	if (is_empty())
		throw std::string("Stack is empty");

	return arr[top--];
}

int Stack::peek() {
	if (is_empty())
		throw std::string("Stack is empty");

	return arr[top];
}

bool Stack::is_empty() {
	return top == -1;
}

bool Stack::is_full() {
	return (top+1) == size;
}

void Stack::clear() {
	top = -1;
}

int Stack::stack_size() {
	return top+1;
}

void Stack::display() {
	for (int i = top; i >= 0; --i)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}

Stack::~Stack() {
	if (arr)
		delete arr;
	arr = nullptr;
}