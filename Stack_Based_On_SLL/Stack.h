#pragma once

#include <iostream>

class Stack {
private:
	struct Node {
		float data;
		Node* next;

		Node(float data) : data(data), next(nullptr) {}
	};

	Node* head;
	size_t size;

public:
	Stack();
	~Stack();

	void push(float value);
	float pop();
	float peek();
	size_t length();
	void display();

	bool empty();
};