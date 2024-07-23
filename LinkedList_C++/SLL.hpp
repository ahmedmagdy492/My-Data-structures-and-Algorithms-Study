#pragma once

#include <iostream>
#include <cassert>
#include <climits>

#include <vector>		// for debug
#include <algorithm>
#include <sstream>
#include <unordered_map>

#include "Node.h"

using namespace std;

class LinkedList {
private:
	Node* head{ };
	Node* tail{ };
	int length = 0;	// let's maintain how many nodes

	vector<Node*> debug_data;	// add/remove nodes you use

	void debug_add_node(Node* node) {
		debug_data.push_back(node);
	}
	void debug_remove_node(Node* node) {
		auto it = std::find(debug_data.begin(), debug_data.end(), node);
		if (it == debug_data.end())
			cout << "Node does not exist\n";
		else
			debug_data.erase(it);
	}

public:

	LinkedList() {
	}

	~LinkedList() {
		Node* ptr = head;
		while (ptr) {
			Node* prev = ptr;
			ptr = ptr->next;
			delete prev;
		}

		head = tail = nullptr;
		length = 0;
	}

	const Node* get_head() {
		return head;
	}

	const Node* get_tail() {
		return tail;
	}

	// Below 2 deletes prevent copy and assign to avoid this mistake
	LinkedList(const LinkedList&) = delete;
	LinkedList& operator=(const LinkedList& another) = delete;

	void debug_print_address() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur << "," << cur->data << "\t";
		cout << "\n";
	}

	void debug_print_node(Node* node, bool is_seperate = false) {
		if (is_seperate)
			cout << "Sep: ";
		if (node == nullptr) {
			cout << "nullptr\n";
			return;
		}
		cout << node->data << " ";
		if (node->next == nullptr)
			cout << "X ";
		else
			cout << node->next->data << " ";

		if (node == head)
			cout << "head\n";
		else if (node == tail)
			cout << "tail\n";
		else
			cout << "\n";
	}
	void debug_print_list(string msg = "") {
		if (msg != "")
			cout << msg << "\n";
		for (int i = 0; i < (int)debug_data.size(); ++i)
			debug_print_node(debug_data[i]);
		cout << "************\n" << flush;
	}

	string debug_to_string() {
		if (length == 0)
			return "";
		ostringstream oss;
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
			assert(!tail->next);
		}
		int len = 0;
		for (Node* cur = head; cur; cur = cur->next, len++)
			assert(len < 10000);	// Consider infinite cycle?
		assert(length == len);
		assert(length == (int)debug_data.size());
	}

	void print() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
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

	void insert_end(int value) {
		Node* item = new Node(value);
		add_node(item);

		if (!head)
			head = tail = item;
		else
			tail->next = item, tail = item;
	}

	void insert_front(int value) {
		Node* newNode = new Node(value);
		if (head == nullptr) {
			head = tail = newNode;
			tail->next = nullptr;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
		add_node(newNode);
	}

	void delete_front() {
		assert(head != nullptr);

		if (head == tail) {
			delete_node(head);
			head = tail = nullptr;
		}
		else {
			Node* temp = head->next;
			delete_node(head);
			head = temp;
		}
	}

	int get_nth_back(int index) {
		assert(index >= 1 && index <= length);
		assert(head != nullptr);

		int forward_distance = length - index;
		Node* ptr = head;

		while (ptr && forward_distance > 0) {
			--forward_distance;
			ptr = ptr->next;
		}

		assert(ptr != nullptr);

		return ptr->data;
	}

	// time: o(len(list1)) or o(len(list2))
	bool is_same(LinkedList& list) {
		if (head == nullptr && list.head == 0)
			return true;

		Node* ptr1 = head, * ptr2 = list.head;

		while (ptr1 && ptr2) {
			if (ptr1->data != ptr2->data) {
				return false;
			}
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}

		if (!ptr1 && !ptr2)
			return true;

		return false;
	}

	int same_until(LinkedList& list) {
		if (head == nullptr && list.head == nullptr)
			return 0;

		int count = 0;
		Node* ptr1 = head, * ptr2 = list.head;

		while (ptr1 && ptr2) {
			if (ptr1->data != ptr2->data)
				return count;
			++count;
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}

		return count;
	}

	int delete_first() {
		assert(head != nullptr);

		Node* headNext = head->next;
		int data = head->data;
		delete_node(head);
		head = headNext;
		if (head == nullptr)
			tail = nullptr;
		return data;
	}

	int delete_last() {
		assert(head != nullptr);

		if (head == tail) {
			int data = tail->data;
			delete_node(tail);
			head = tail = nullptr;
			return data;
		}

		Node* ptr = head;

		while (ptr && ptr->next != tail) {
			ptr = ptr->next;
		}

		assert(ptr != nullptr);

		int data = tail->data;
		ptr->next = nullptr;
		delete_node(tail);
		tail = ptr;
		return data;
	}

	int delete_nth_node(int index) {
		assert(index >= 1 && index <= length);
		assert(head != nullptr);

		if (index == 1) {
			int data = head->data;
			delete_node(head);
			head = tail = nullptr;
			return data;
		}

		int counter = 1;
		Node* ptr = head;

		while (ptr && counter < (index - 1)) {
			++counter;
			ptr = ptr->next;
		}

		assert(ptr != nullptr && ptr->next != nullptr);
		Node* prev = ptr;
		ptr = ptr->next;
		int data = ptr->data;
		prev->next = ptr->next;

		if (ptr == tail)
			tail = prev;

		delete_node(ptr);
		return data;
	}

	void delete_with_key(int key) {
		assert(head != nullptr);

		if (head->data == key) {
			delete_first();
			return;
		}

		Node* ptr = head;
		Node* prev = nullptr;

		while (ptr) {
			if (ptr->data == key) {
				break;
			}
			prev = ptr;
			ptr = ptr->next;
		}

		assert(ptr != nullptr);
		assert(prev != nullptr);
		prev->next = ptr->next;
		delete_node(ptr);
	}

	void swap_pairs() { // T(n) = n/2 = O(n)
		if (head == nullptr || head == tail)
			return;

		Node* cur = head, * next = head->next;

		while (cur != nullptr && next != nullptr) {
			int temp = cur->data;
			cur->data = next->data;
			next->data = temp;
			cur = cur->next->next;
			if (next->next != nullptr) {
				next = next->next->next;
			}
			else {
				break;
			}
		}
	}

	/// <summary>
	/// gets the node at the given index or null
	/// </summary>
	/// <param name="index">0-based indexing</param>
	/// <returns>a pointer to the node at the given index</returns>
	Node* get_nth_node(int index) {
		assert(index >= 0 && index < length);
		Node* ptr = head;
		int counter = 0;

		while (ptr && counter < index) {
			++counter;
			ptr = ptr->next;
		}

		return ptr;
	}

	void reverse() { // O(n^2)
		int counter = length - 1;
		Node* first = head, * last = get_nth_node(counter);

		while (first != last) {
			int temp = first->data;
			first->data = last->data;
			last->data = temp;

			last = get_nth_node(--counter);
			if (last == first) {
				break;
			}
			first = first->next;
		}
	}

	void reverse_sl() {
		if (head == nullptr) return;

		Node* prev = nullptr, * cur = head, * next = cur->next;

		while (cur) {
			if (cur == head) {
				prev = cur;
				cur = cur->next;
				if (cur == nullptr)
					break;
				next = cur->next;
			}
			else {
				cur->next = head;
				head = cur;
				prev->next = next;
				cur = next;
				if (cur == nullptr)
					break;
				next = cur->next;
			}
		}

		tail = prev;
	}

	void delete_node_next_to(Node* node) {
		assert(node != nullptr);

		if (node->next != nullptr) {
			Node* node_to_delete = node->next;
			node->next = node->next->next;
			delete_node(node_to_delete);
			if (length == 1)
				tail = head;
			tail->next = nullptr;
		}
	}

	void delete_even_positions_internal(Node* ptr, int counter) {
		if (ptr != nullptr) {
			delete_even_positions_internal(ptr->next, counter + 1);
			if ((counter % 2) != 0) {
				delete_node_next_to(ptr);
			}
		}
	}

	void delete_even_positions() {
		delete_even_positions_internal(head, 1);
	}

	void insert_next_to(Node* node, int data) {
		assert(node != nullptr);

		Node* temp = node->next;
		node->next = new Node(data);
		node->next->next = temp;
		add_node(node->next);
	}

	void insert_sorted(int data) {
		if (head == nullptr) {
			insert_front(data);
			return;
		}

		Node* ptr = head;

		while (ptr) {
			if (data <= ptr->data) {
				Node* newNode = new Node(data);
				newNode->next = ptr;
				add_node(newNode);
				if (ptr == head)
					head = newNode;
				break;
			}
			else if (data > ptr->data && !ptr->next) {
				insert_end(data);
				break;
			}
			else if (data > ptr->data && ptr->next) {
				if (data < ptr->next->data) {
					insert_next_to(ptr, data);
					break;
				}
			}

			ptr = ptr->next;
		}
	}

	void swap_head_and_tail() {
		if (head == nullptr) return;
		if (head == tail) return;

		if (head->next == tail) {
			tail->next = head;
			head->next = nullptr;
			Node* temp = head;
			head = tail;
			tail = temp;
			return;
		}

		Node* ptr = head, * prev = nullptr;

		while (ptr && ptr->next) {
			prev = ptr;
			ptr = ptr->next;
		}

		tail->next = head->next;
		prev->next = head;
		head->next = nullptr;
		Node* temp = tail;
		tail = head;
		head = temp;
	}

	void left_rotate(int k) {

		int n = k > length ? k % length : k;

		if (head == nullptr)
			return;
		if (head == tail)
			return;

		for (int i = 1; i <= n; ++i) {
			Node* headNext = head->next;
			tail->next = head;
			head->next = nullptr;
			tail = head;
			head = headNext;
		}
	}

	void remove_duplicates() {
		unordered_map<int, int> hashtable;

		Node* ptr = head, * prev = nullptr;

		while (ptr) {
			if (hashtable.find(ptr->data) != hashtable.end()) {
				Node* ptrNext = ptr->next;
				delete_node_next_to(prev);
				ptr = ptrNext;
			}
			else {
				hashtable.insert({ ptr->data, 1 });
				prev = ptr;
				ptr = ptr->next;
			}
		}
	}

	void delete_given_node(Node* node) {

		if (head == nullptr) return;

		if (node == head) {
			delete_first();
			return;
		}

		Node* ptr = head, * prev = nullptr;

		while (ptr) {
			if (ptr == node) {
				delete_node_next_to(prev);
				break;
			}
			prev = ptr;
			ptr = ptr->next;
		}
	}

	void remove_last_occurance(int key) {
		Node* ptr = head, * prev = nullptr;
		Node* lastOccurancePtr = nullptr;
		bool is_found = false;

		while (ptr) {
			if (ptr->data == key) {
				lastOccurancePtr = prev;
				is_found = true;
			}
			prev = ptr;
			ptr = ptr->next;
		}

		if (is_found) {
			if (lastOccurancePtr != nullptr) {
				delete_node_next_to(lastOccurancePtr);
			}
			else {
				delete_first();
			}
		}
	}

	void move_key_to_back(int key) {
		if (head == nullptr) return;
		if (head->next == nullptr) return;

		int counter = 0;
		Node* ptr = head, * prev = nullptr, * temp = nullptr;

		while (counter < length) {
			if (ptr->data == key) {
				temp = ptr;
				ptr = ptr->next;
				tail->next = temp;
				temp->next = nullptr;
				if (temp == head) {
					head = ptr;
				}
				else {
					prev->next = ptr;
				}
				tail = temp;
			}
			else {
				prev = ptr;
				ptr = ptr->next;
			}
			++counter;
		}
	}

	int max() {
		return max_value(head, INT_MIN);
	}
private:
	int max_value(Node* ptr, int max) {
		if (!ptr)
			return max;

		if (ptr->data > max)
			max = ptr->data;

		return max_value(ptr->next, max);
	}

public:
	void arrange_odd_and_even_positions() {

		if (head == nullptr) return;
		if (head->next == nullptr) return;

		int index = 1;

		Node* ptr = head, * prev = nullptr, * last_inserted = nullptr;

		while (ptr) {

			if ((index % 2) != 0) {
				if (ptr == head) {
					last_inserted = head;
					prev = ptr;
					ptr = ptr->next;
				}
				else {
					Node* last_inserted_next = last_inserted->next;
					Node* temp = ptr;
					ptr = ptr->next;
					last_inserted->next = temp;
					prev->next = ptr;
					temp->next = last_inserted_next;
					last_inserted = temp;
					if (ptr == nullptr)
						tail = prev;
				}
			}
			else {
				prev = ptr;
				ptr = ptr->next;
			}

			++index;
		}
	}

	int calculate_len(Node* listHead) {
		Node* ptr = listHead;
		int counter = 0;

		while (ptr != nullptr) {
			++counter;
			ptr = ptr->next;
		}

		return counter;
	}

	void insert_alternate(LinkedList* list2) {
		Node* list1ptr = head, * list2ptr = (Node*)list2->head;

		if (list1ptr == nullptr && list2ptr == nullptr)
			return;

		if (list1ptr == nullptr && list2ptr != nullptr) {
			head = list2->head;
			tail = list2->tail;
			list2->head = list2->tail = nullptr;

			// for debuging only
			Node* ptr = head;
			while (ptr) {
				add_node(ptr);
				ptr = ptr->next;
			}
			return;
		}

		while (list1ptr && list2ptr) {
			Node* temp1 = list1ptr;
			list1ptr = list1ptr->next;
			Node* temp2 = list2ptr;
			list2ptr = list2ptr->next;
			temp1->next = temp2;
			temp2->next = list1ptr;
			add_node(temp2);
			if (temp1 == tail)
				tail = temp2;
		}

		if (list2ptr != nullptr) {
			// for debuging only
			Node* ptr = list2ptr;
			while (ptr) {
				add_node(ptr);
				ptr = ptr->next;
			}

			tail->next = list2ptr;
			tail = list2->tail;
		}

		list2->head = list2->tail = nullptr;
	}

	// let n = length of original list
	// let m = length of new list
	// Time:  O(min(n, m) + (m - n))
	// Space: O(m-n)
	void add_number(LinkedList* another) {
		assert(head != nullptr);
		assert(another->head != nullptr);

		int carry = 0, result = 0;
		Node* ptr = head, * ptr2 = another->head;
		bool isCarryFlagSet = false;

		while (ptr && ptr2) {
			result = ptr->data + ptr2->data;
			ptr->data = (result % 10) + carry;
			carry = 0;
			isCarryFlagSet = false;

			if (result >= 10) {
				carry = result / 10;
				isCarryFlagSet = true;
			}
			ptr = ptr->next;
			ptr2 = ptr2->next;
		}

		if (ptr != nullptr) {
			if (isCarryFlagSet) {
				isCarryFlagSet = false;
				ptr->data += carry;
			}
		}

		if (ptr2 != nullptr) {
			while (ptr2) {
				if (isCarryFlagSet) {
					isCarryFlagSet = false;
					ptr2->data += carry;
				}
				insert_end(ptr2->data);
				ptr2 = ptr2->next;
			}
		}

		if (isCarryFlagSet) {
			insert_end(carry);
		}
	}

	void remove_duplicate() {
		std::unordered_map<int, Node*> hashtable;

		Node* ptr = head;

		while (ptr) {
			auto it = hashtable.find(ptr->data);
			if (it != hashtable.end()) {
				Node* temp = ptr;
				ptr = ptr->next;
				delete_given_node(temp);
				delete_given_node(it->second);
			}
			else {
				hashtable.insert({ ptr->data, ptr });
				ptr = ptr->next;
			}
		}
	}

	void remove_duplicate_bf() {
		assert(head != nullptr);

		Node* ptr1 = head, * ptr2 = head->next;
		std::vector<Node*> nodes_to_delete;

		while (ptr1) {
			ptr2 = ptr1->next;
			while (ptr2) {
				if (ptr2->data == ptr1->data) {
					nodes_to_delete.push_back(ptr1);
					nodes_to_delete.push_back(ptr2);
				}
				ptr2 = ptr2->next;
			}
			ptr1 = ptr1->next;
		}

		for (auto& node : nodes_to_delete) {
			delete_given_node(node);
		}
	}

	Node* get_node_prev_to(Node* node) {
		Node* ptr = head;

		while (ptr) {
			if (ptr->next == node) {
				return ptr;
			}
			ptr = ptr->next;
		}

		return nullptr;
	}

	void reverse_from_to(Node* start, int to) {
		if (start == nullptr) return;

		Node* prev = nullptr, * cur = start, * next = cur->next;

		if (length == to) {
			reverse_sl();
			return;
		}

		int counter = 0;

		if (cur == head) {
			while (cur && counter < to) {
				if (cur == head) {
					prev = cur;
					cur = cur->next;
					if (cur == nullptr)
						break;
					next = cur->next;
				}
				else {
					cur->next = head;
					head = cur;
					prev->next = next;
					cur = next;
					if (cur == nullptr)
						break;
					next = cur->next;
				}
				++counter;
			}
			tail = prev;
		}
		else {
			Node* node = get_node_prev_to(cur);
			node->next = nullptr;

			while (cur && counter < to) {
				if (cur == start) {
					prev = cur;
					cur = cur->next;
					if (cur == nullptr)
						break;
					next = cur->next;
				}
				else {
					cur->next = start;
					start = cur;
					prev->next = next;
					cur = next;
					if (cur == nullptr)
						break;
					next = cur->next;
				}
				++counter;
			}
			tail = prev;
			node->next = start;
		}
	}

	void reverse_chains(int k) {
		assert(k != 0);
		int start = 0;

		while (start < length) {
			Node* node = get_nth_node(start);

			reverse_from_to(node, k);
			start += k;
		}
	}
};