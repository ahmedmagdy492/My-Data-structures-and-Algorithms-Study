#pragma once

#include <stack>


class Queue {
private:
	int addedElements;
	int size;
	std::stack<int> enqueueStack;
	std::stack<int> dequeueStack;

public:
	Queue(int size);

	void Enqueue(int value);
	int Dequeue();
	bool IsEmpty() const;
	bool IsFull() const;

	~Queue();
};