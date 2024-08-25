#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>

template <class T>
class Node {
public:
	Node* next;
	Node* prev;
	T data;

	Node(T data) : next(nullptr), prev(nullptr), data(data) {
	}
};

template <class T>
class DLinkedList {
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	unsigned int length;

	void link(Node<T>* first, Node<T>* second) {
		if (first)
			first->next = second;
		if (second)
			second->prev = first;
	}

public:
	DLinkedList() : length(0) {
	}

	DLinkedList(const DLinkedList&) = delete;
	DLinkedList& operator=(const DLinkedList& another) = delete;

	inline Node<T>* get_head() {
		return head;
	}

	inline Node<T>* GetTail() {
		return tail;
	}

	void delete_node(Node<T>* node) {
		--length;
		delete node;
	}

	Node<T>* link_and_delete(Node<T>* node) {
		if (node) {
			bool isHead = node == head;
			Node<T>* node_before = node->prev;
			Node<T>* node_after = node->next;

			if (isHead) {
				head = node_after;
			}

			link(node_before, node_after);
			delete_node(node);
			return node_before;
		}

		return nullptr;
	}

	void insert_end(T data) {
		Node<T>* new_node = new Node<T>(data);
		if (!head) {
			head = tail = new_node;
		}
		else {
			link(tail, new_node);
			tail = new_node;
		}
		++length;
	}

	Node<T>* search_by_value(T value, bool (*cmp)(T first, T other)) {
		Node<T>* ptr = head;

		while (ptr) {
			if (cmp(value, ptr->data)) {
				return ptr;
			}
			ptr = ptr->next;
		}

		return nullptr;
	}

	void delete_odd_positions() {
		if (head == nullptr)
			return;

		Node<T>* ptr = head;
		int pos = 1;

		while (ptr) {
			if ((pos % 2) != 0) {
				Node<T>* nodeToBeDeleted = ptr;
				if (nodeToBeDeleted == head) {
					head = head->next;
				}
				ptr = ptr->next;
				Node<T>* prev = link_and_delete(nodeToBeDeleted);
				if (!ptr) {
					tail = prev;
				}
			}
			else {
				ptr = ptr->next;
			}
			++pos;
		}
	}

	void delete_all() {
		Node<T>* ptr = head;

		while (ptr) {
			Node<T>* temp = ptr;
			ptr = ptr->next;
			delete temp;
		}
	}

	void delete_even_positions() {
		if (head == nullptr || head == tail)
			return;

		Node<T>* ptr = head;
		int pos = 1;

		while (ptr) {
			if ((pos % 2) == 0) {
				Node<T>* nodeToBeDeleted = ptr;
				ptr = ptr->next;
				Node<T>* prev = link_and_delete(nodeToBeDeleted);
				if (!ptr) {
					tail = prev;
				}
			}
			else {
				ptr = ptr->next;
			}
			++pos;
		}
	}

	void insert_front(T data) {
		Node<T>* new_node = new Node<T>(data);
		length++;

		if (!head) {
			head = tail = new_node;
		}
		else {
			link(new_node, head);
			head = new_node;
		}
	}

	void insert_sorted(T data) {
		if (head == nullptr || head->data >= data) {
			insert_front(data);
		}
		else if (tail->data <= data) {
			insert_end(data);
		}
		else {
			Node<T>* ptr = head;
			Node<T>* new_node = new Node<T>(data);

			while (ptr) {
				if (new_node->data < ptr->data) {
					Node<T>* ptr2 = ptr;
					while (ptr2) {
						if (new_node->data >= ptr2->data) {
							link(new_node, ptr2->next);
							link(ptr2, new_node);
							length++;
							return;
						}
						ptr2 = ptr2->prev;
					}
				}
				ptr = ptr->next;
			}
		}
	}
};