#pragma once
#include <iostream>
#include <cassert>
#include <sstream>

struct Node {
	int data;
	Node* next;

	Node(int data) : data(data), next(nullptr) {
	}
};

class LinkedList {
private:
	Node* head;
	Node* tail;
	int length;

public:
	LinkedList() : head(nullptr), tail(nullptr), length(0) {
	}

	~LinkedList() {
		Node* ptr = head;
		while (ptr != nullptr) {
			Node* temp = ptr->next;
			if (ptr != nullptr)
				delete ptr;
			ptr = temp;
		}
	}

	inline int Size() {
		return length;
	}

	void InsertEnd(int value) {
		Node* item = new Node(value);
		if (head == nullptr) {
			head = tail = item;
			head->next = tail->next = nullptr;
		}
		else {
			tail->next = item;
			tail = tail->next;
			tail->next = nullptr;
		}
		++length;
	}

	void Print() const {
		Node* start = head;
		for (; start != nullptr; start = start->next) {
			std::cout << start->data << "\n";
		}
	}

	void PrintRe(Node* head) {
		if (head == nullptr)
			return;

		std::cout << head->data << "\n";
		PrintRe(head->next);
	}

	Node* Find(int value) {
		Node* ptr = head;
		while (ptr != nullptr) {
			if (ptr->data == value) {
				return ptr;
			}
			ptr = ptr->next;
		}

		return nullptr;
	}

	Node* GetNodeAt(int index) {
		if (index < 1 || index > length)
			return nullptr;

		int counter = 1;

		for (Node* ptr = head; ptr; ptr = ptr->next, ++counter) {
			if (counter == index)
				return ptr;
		}

		return nullptr;
	}

	int IndexOf(int value) {
		int index = 1;

		for (Node* cur = head, *prev = nullptr; cur; prev = cur, cur = cur->next, ++index) {
			if (cur->data == value) {
				if (!prev) {
					int temp = cur->data;
					cur->data = prev->data;
					prev->data = temp;
				}
				return index;
			}
		}

		return -1;
	}

	void VerfiyLinkedListIntegirty() {
		if (length == 0) {
			assert(head == nullptr);
			assert(tail == nullptr);
		}
		else {
			if (length == 1) {
				assert(head == tail);
			}
			else {
				assert(head != tail);
			}
			assert(!tail->next);
		}
		int count = 0;
		for (Node* ptr = head; ptr != nullptr; ptr = ptr->next) {
			++count;
		}

		assert(count == length);
	}

	LinkedList(const LinkedList&) = delete;
	LinkedList& operator=(const LinkedList& another) = delete;

	std::string debug_to_string() {
		if (length == 0)
			return "";
		std::ostringstream oss;
		for (Node* cur = head; cur; cur = cur->next) {
			oss << cur->data;
			if (cur->next)
				oss << " ";
		}
		return oss.str();
	}
};