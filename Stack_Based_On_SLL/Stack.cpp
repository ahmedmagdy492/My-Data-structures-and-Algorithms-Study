#include "Stack.h"

Stack::Stack() : head(nullptr), size(0) {
}

Stack::~Stack() {
	Node* ptr = head;
	while (ptr) {
		Node* temp = ptr;
		ptr = ptr->next;
		delete temp;
	}

	size = 0;
}

void Stack::push(int value) {
	Node* newNode = new Node(value);
	newNode->next = head;
	head = newNode;
	size++;
}

int Stack::pop() {
	if (head) {
		Node* poppedNode = head;
		int value = poppedNode->data;
		head = head->next;
		delete poppedNode;
		size--;

		if (size == 0) {
			head = nullptr;
		}

		return value;
	}
	throw std::runtime_error("Stack is empty");
}

int Stack::peek() {
	if(empty())
		throw std::runtime_error("Stack is empty");

	return head->data;
}

size_t Stack::length() {
	return size;
}

bool Stack::empty() {
	return !head;
}

void Stack::display() {
	Node* ptr = head;

	while (ptr) {
		std::cout << ptr->data << std::endl;
		ptr = ptr->next;
	}
}