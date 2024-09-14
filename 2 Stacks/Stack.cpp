#include "Stack.h"

Stack::Stack(size_t size) : size(size), top1(-1), top2(size) {
	arr = new int[size];
}

void Stack::push(int id, int value) {
	if(is_full())
		throw std::string("Stack is full");
	
	if (id == 1)
		arr[++top1] = value;
	else
		arr[--top2] = value;
}

int Stack::pop(int id) {
	if (is_empty(id))
		throw std::string("Stack is empty");

	if (id == 1)
		return arr[top1--];

	return arr[top2++];
}

int Stack::peek(int id) {
	if (is_empty(id))
		throw std::string("Stack is empty");

	if (id == 1)
		return arr[top1];

	return arr[top2];
}

bool Stack::is_empty(int id) {
	if (id == 1)
		return top1 == -1;
	return top2 == size;
}

bool Stack::is_full() {
	return top1 == top2;
}

void Stack::clear(int id) {
	if (id == 1)
		top1 = -1;
	else
		top2 = size;
}

int Stack::stack_size(int id) {
	if(id == 1)
		return top1 + 1;
	return size - top2;
}

void Stack::display() {
	for (int i = top1; i >= 0; --i)
		std::cout << arr[i] << " ";
	std::cout << "\n";

	for (int i = top2; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}

Stack::~Stack() {
	if (arr)
		delete arr;
	arr = nullptr;
}
