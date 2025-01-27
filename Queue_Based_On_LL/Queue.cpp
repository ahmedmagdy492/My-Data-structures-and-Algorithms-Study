
#include "Queue.h"

#include <iostream>

Queue::Queue() {

}

void Queue::Enqueue(int value) {
	if (IsEmpty()) {
		head = new Node(value);
		tail = head;
	}
	else {
		tail->next = new Node(value);
		tail = tail->next;
	}
	length++;
}

int Queue::Dequeue() {
	if (IsEmpty()) {
		throw std::runtime_error("Queue is empty");
	}

	int valueToReturn = head->value;
	Node* temp = head;
	head = head->next;
	delete temp;
	return valueToReturn;
}

void Queue::Display() const {
	Node* ptr = head;

	while (ptr) {
		std::cout << ptr->value << std::endl;
		ptr = ptr->next;
	}
}

bool Queue::IsEmpty() const {
	return head == nullptr;
}

Queue::~Queue() {
	Node* ptr = head;

	while (ptr) {
		Node* temp = ptr;
		ptr = ptr->next;
		delete temp;
	}
}