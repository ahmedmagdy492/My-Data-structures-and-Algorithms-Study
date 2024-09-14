#pragma once

#include <cassert>
#include <iostream>

class Stack {
private:
	int top = -1;
	int* arr = nullptr;
	size_t size;

public:
	Stack(size_t size);

	void push(int value);
	int pop();
	int peek();
	bool is_empty();
	bool is_full();
	void clear();
	int stack_size();

	void display();

	~Stack();
};