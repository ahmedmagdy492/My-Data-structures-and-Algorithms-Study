#pragma once

#include <iostream>

class Stack {
private:
	struct Node {
		int data;
		Node* next;

		Node(int data) : data(data), next(nullptr) {}
	};

	Node* head;
	size_t size;

public:
	Stack();
	~Stack();

	void push(int value);
	int pop();
	int peek();
	size_t length();
	void display();

	bool empty();
};