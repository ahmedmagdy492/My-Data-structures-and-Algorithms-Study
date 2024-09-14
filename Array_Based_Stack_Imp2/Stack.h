#pragma once

#include <iostream>

class Stack {
private:
	int added_elements;
	int* arr;
	size_t size;

	void array_shift_right();
	void array_shift_left();

public:
	Stack(size_t size);

	bool push(int value);
	bool pop(int& value);
	bool peek(int& value);
	bool is_empty();
	bool is_full();

	void display();

	~Stack();
};