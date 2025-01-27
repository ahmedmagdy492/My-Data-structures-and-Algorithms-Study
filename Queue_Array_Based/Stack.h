#pragma once

#include "Queue.h"

class Stack {
private:
	Queue *q;
	int added_elements;

public:
	Stack(int size);

	void Push(int value);
	int Pop();
	int Peek();
	bool IsEmpty();
	bool IsFull();

	~Stack();
};