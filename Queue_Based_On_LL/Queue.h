#pragma once

struct Node {
	int value;
	Node* next;

	Node(int value) : value(value), next(nullptr) {
	}
};

class Queue {
private:
	Node* head = {};
	Node* tail = {};

	int length = 0;

public:
	Queue();

	void Enqueue(int value);

	int Dequeue();

	bool IsEmpty() const;

	void Display() const;

	~Queue();
};