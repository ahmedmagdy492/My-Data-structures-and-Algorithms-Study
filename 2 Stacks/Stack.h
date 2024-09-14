#pragma once

#include <cassert>
#include <iostream>

class Stack {
private:
	int top1, top2;
	int* arr = nullptr;
	size_t size;

public:
	Stack(size_t size);

	void push(int id, int value);
	int pop(int id);
	int peek(int id);
	bool is_empty(int id);
	bool is_full();
	void clear(int id);
	int stack_size(int id);

	void display();

	~Stack();
};