#pragma once

#include "Node.h"

class SLinkedList {
private:
	Node* head{ };

public:
	void print() {
		Node* ptr = head;

		while (ptr != nullptr) {
			cout << ptr->data << "\n";
			ptr = ptr->next;
		}
	}

	void add_node(int value) {
		if (head == nullptr) {
			head = new Node(value);
			head->next = nullptr;
		}
		else {
			Node* newNode = new Node(value);
			newNode->next = head;
			head = newNode;
		}
	}

	Node* get_tail() {
		Node* ptr = head, *prev = nullptr;

		while (ptr) {
			prev = ptr;
			ptr = ptr->next;
		}

		return prev;
	}
};