#pragma once

#include <iostream>

class Queue {
private:
	size_t size;
	int *arr;
	int front = 0;
	int rear = 0;
	int added_elements = 0;

	int GetNextPosition(int x);
	int GetPreviousPosition(int x);

public:
	Queue(int size);

	void EnqeueRear(int value);
	void EnqeueFront(int value);
	int DeqeueRear();
	int DeqeueFront();
	bool IsFull() const;
	bool IsEmpty() const;

	inline int Front() const {
		if (IsEmpty())
			throw std::runtime_error("Queue is Empty");

		return arr[front];
	}

	inline int Rear() const {
		if (IsEmpty())
			throw std::runtime_error("Queue is Empty");

		return arr[rear];
	}

	inline int Length() const {
		return added_elements;
	}

	void Display();

	~Queue();
};