#pragma once

#include <iostream>
#include <cassert>
#include <strstream>
#include <utility>

#include "DLinkedList.h"

struct ArrayEntry {
	int index;
	int value;

	bool operator >=(const ArrayEntry& other) const {
		return value >= other.value;
	}

	bool operator <=(const ArrayEntry& other) const {
		return value <= other.value;
	}

	bool operator <(const ArrayEntry& other) const {
		return value < other.value;
	}
};

bool compare_array_entries(ArrayEntry first, ArrayEntry other) {
	return first.index == other.index;
}

class SparseArray {
private:
	DLinkedList<ArrayEntry> list;
	size_t length;

public:
	SparseArray(size_t length) : length(length) {
	}

	size_t get_length() {
		return length;
	}

	Node<ArrayEntry>* get_list_head() {
		return list.get_head();
	}

	void set_value(int value, int index) {
		ArrayEntry new_entry;
		new_entry.value = value;
		new_entry.index = index;
		Node<ArrayEntry>* found_node = list.search_by_value(new_entry, compare_array_entries);

		if (!found_node) {
			if (value != 0) {
				list.insert_sorted(new_entry);
			}
		}
		else {
			if (value == 0) {
				list.link_and_delete(found_node);
			}
			else {
				found_node->data.value = value;
			}
		}
	}

	int get_value(int index) {
		assert(index > -1 && index < length);

		Node<ArrayEntry>* ptr = list.get_head();
		
		for (int i = 0; i < length; ++i) {
			if (ptr && ptr->data.index == index) {
				return ptr->data.value;
			}
			if(ptr)
				ptr = ptr->next;
		}

		return 0;
	}

	void add_array(SparseArray& arr) {
		Node<ArrayEntry>* ptr = arr.get_list_head();

		while (ptr) {
			if (ptr->data.index < length) {
				int value = get_value(ptr->data.index);
				set_value(ptr->data.value + value, ptr->data.index);
			}
			else {
				set_value(ptr->data.value, ptr->data.index);
			}
			ptr = ptr->next;
		}
	}

	void print_array() {
		for (int i = 0; i < length; ++i) {
			Node<ArrayEntry>* ptr = list.get_head();
			Node<ArrayEntry>* found = nullptr;

			while (ptr) {
				if (i == ptr->data.index) {
					found = ptr;
					break;
				}
				ptr = ptr->next;
			}

			if (found) {
				std::cout << found->data.value << " ";
			}
			else {
				std::cout << 0 << " ";
			}
		}
		
		std::cout << std::endl;
	}

	void print_array_non_zero() {
		for (Node<ArrayEntry>* cur = list.get_head(); cur; cur = cur->next) {
			std::cout << cur->data.value << " ";
		}
		std::cout << std::endl;
	}

	~SparseArray() {
		list.delete_all();
	}
};