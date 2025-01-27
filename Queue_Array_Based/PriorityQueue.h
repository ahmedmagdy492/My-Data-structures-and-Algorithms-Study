#pragma once

#include "Queue.h"

class PriorityQueue {
private:
	Queue *q1, *q2, *q3;
	int size;

public:
	PriorityQueue(int size);

	void enqueue(int value, int priority);

	int dequeue();

	int peek();

	void display();

	~PriorityQueue();
};