#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>

class Node {
public:
	int data;
	Node* next;
	Node* prev;

	Node(int data) : next(nullptr), prev(nullptr), data(data) {
	}
};

class DLinkedList {
public:
	Node* head{ };
	Node* tail{ };
	int length;

	std::vector<Node*> debug_data;

	DLinkedList(const DLinkedList&) = delete;
	DLinkedList& operator=(const DLinkedList& another) = delete;

	void debug_add_node(Node* node) {
		debug_data.push_back(node);
	}
	void debug_remove_node(Node* node) {
		auto it = std::find(debug_data.begin(), debug_data.end(), node);
		if (it == debug_data.end())
			std::cout << "Node does not exist\n";
		else
			debug_data.erase(it);
	}

	void debug_print_address() {
		for (Node* cur = head; cur; cur = cur->next)
			std::cout << cur << "," << cur->data << "\t";
		std::cout << "\n";
	}

	void debug_print_node(Node* node, bool is_seperate = false) {
		if (is_seperate)
			std::cout << "Sep: ";
		if (node == nullptr) {
			std::cout << "nullptr\n";
			return;
		}

		if (node->prev == nullptr)
			std::cout << "X\t";
		else
			std::cout << node->prev->data << "\t";

		std::cout << " <= [" << node->data << "]\t => \t";

		if (node->next == nullptr)
			std::cout << "X\t";
		else
			std::cout << node->next->data << "\t";

		if (node == head)
			std::cout << "head\n";
		else if (node == tail)
			std::cout << "tail\n";
		else
			std::cout << "\n";
	}
	void debug_print_list(std::string msg = "") {
		if (msg != "")
			std::cout << msg << "\n";
		for (int i = 0; i < (int)debug_data.size(); ++i)
			debug_print_node(debug_data[i]);
		std::cout << "************\n" << std::flush;
	}

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

	void debug_verify_data_integrity() {
		if (length == 0) {
			assert(head == nullptr);
			assert(tail == nullptr);
		}
		else {
			assert(head != nullptr);
			assert(tail != nullptr);
			if (length == 1)
				assert(head == tail);
			else
				assert(head != tail);
			assert(!head->prev);
			assert(!tail->next);
		}
		int len = 0;
		for (Node* cur = head; cur; cur = cur->next, len++) {
			if (len == length - 1)	// make sure we end at tail
				assert(cur == tail);
		}

		assert(length == len);
		assert(length == (int)debug_data.size());

		len = 0;
		for (Node* cur = tail; cur; cur = cur->prev, len++) {
			if (len == length - 1)	// make sure we end at head
				assert(cur == head);
		}
		std::cout << "\n";
	}
	////////////////////////////////////////////////////////////

	void print() {
		for (Node* cur = head; cur; cur = cur->next)
			std::cout << cur->data << " ";
		std::cout << "\n";
	}

	// These 2 simple functions just to not forget changing the vector and length
	void delete_node(Node* node) {
		debug_remove_node(node);
		--length;
		delete node;
	}

	void add_node(Node* node) {
		debug_add_node(node);
		++length;
	}

	DLinkedList() : head(nullptr), tail(nullptr), length(0) {
	}

	void link(Node* first, Node* second) {
		if(first)
			first->next = second;
		if(second)
			second->prev = first;
	}

	void insert_end(int data) {
		Node* new_node = new Node(data);
		if (!head) {
			head = tail = new_node;
		}
		else {
			link(tail, new_node);
			tail = new_node;
		}
		add_node(new_node);
	}

	void insert_front(int data) {
		Node* new_node = new Node(data);
		add_node(new_node);

		if (!head) {
			head = tail = new_node;
		}
		else {
			link(new_node, head);
			head = new_node;
		}
	}

	void insert_sorted(int data) {
		if (head == nullptr || head->data >= data) {
			insert_front(data);
		}
		else if (tail->data <= data) {
			insert_end(data);
		}
		else {
			Node* ptr = head;
			Node* new_node = new Node(data);

			while (ptr) {
				if (new_node->data < ptr->data) {
					Node* ptr2 = ptr;
					while (ptr2) {
						if (new_node->data >= ptr2->data) {
							link(new_node, ptr2->next);
							link(ptr2, new_node);
							add_node(new_node);
							return;
						}
						ptr2 = ptr2->prev;
					}
				}
				ptr = ptr->next;
			}
		}
	}

	void delete_front() {
		if (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete_node(temp);
			if (head) {
				head->prev = nullptr;
			}
			else {
				head = tail = nullptr;
			}
		}
	}

	void delete_end() {
		if (head != nullptr) {
			Node* temp = tail;
			tail = tail->prev;
			delete_node(temp);
			if (tail)
				tail->next = nullptr;
			else
				head = tail = nullptr;
		}
	}

	Node* link_and_delete(Node* node) {
		if (node) {
			Node* node_before = node->prev;
			Node* node_after = node->next;

			link(node_before, node_after);
			delete_node(node);
			return node_before;
		}

		return nullptr;
	}

	void delete_with_key(int key) {
		if (!head)
			return;

		if (head->data == key) {
			delete_front();
			return;
		}
		
		for (Node* ptr = head; ptr; ptr = ptr->next) {
			if (ptr->data == key) {
				Node* prev = link_and_delete(ptr);
				if (prev && !prev->next) {
					tail = prev;
				}
				break;
			}
		}
	}

	void delete_all_nodes_with_key(int key) {
		if (head == nullptr)
			return;

		insert_front(-key);

		for (Node* ptr = head; ptr; ) {
			if (ptr->data == key) {
				ptr = link_and_delete(ptr);
				if (!ptr->next) {
					tail = ptr;
				}
			}
			else { 
				ptr = ptr->next;
			}
		}

		delete_front();
	}

	void delete_even_positions() {
		if (head == nullptr || head == tail)
			return;

		Node* ptr = head;
		int pos = 1;

		while (ptr) {
			if ((pos % 2) == 0) {
				Node* nodeToBeDeleted = ptr;
				ptr = ptr->next;
				Node* prev = link_and_delete(nodeToBeDeleted);
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

	void delete_odd_positions() {
		if (head == nullptr)
			return;

		Node* ptr = head;
		int pos = 1;

		while (ptr) {
			if ((pos % 2) != 0) {
				Node* nodeToBeDeleted = ptr;
				if (nodeToBeDeleted == head) {
					head = head->next;
				}
				ptr = ptr->next;
				Node* prev = link_and_delete(nodeToBeDeleted);
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

	bool is_palindrome() {
		if (head == nullptr)
			return false;

		Node* ptr1 = head, * ptr2 = tail;

		while (ptr1 != ptr2) {
			if (ptr1->data != ptr2->data) {
				return false;
			}
			ptr1 = ptr1->next;
			ptr2 = ptr2->prev;
		}

		return true;
	}
};