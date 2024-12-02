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
	void shift_right(int arr[], int len);
	void insert_at_bottom(int x);
	void reverse();

	void display();

	~Stack();
};