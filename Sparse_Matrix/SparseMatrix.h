#pragma once

#include "SparseArray.h"

struct SparseMatrixEntry {
	int index;
	SparseArray* array = nullptr;

	bool operator >=(const SparseMatrixEntry& other) const {
		return index >= other.index;
	}

	bool operator <=(const SparseMatrixEntry& other) const {
		return index <= other.index;
	}

	bool operator <(const SparseMatrixEntry& other) const {
		return index < other.index;
	}
};

bool compare_sparse_arrays(SparseMatrixEntry first, SparseMatrixEntry second) {
	return first.index == second.index;
}

class SparseMatrix {
private:
	DLinkedList<SparseMatrixEntry> list;
	size_t rows_count, cols_count;

public:
	SparseMatrix(size_t no_of_rows, size_t no_of_cols) : rows_count(no_of_rows), cols_count(no_of_cols) {
	}

	std::pair<size_t, size_t> get_length() {
		return std::make_pair(rows_count, cols_count);
	}

	DLinkedList<SparseMatrixEntry>* get_list() {
		return &list;
	}

	void set_value(int value, int r, int c) {
		assert(r < rows_count && r >= 0);
		assert(c < cols_count && c >= 0);

		SparseMatrixEntry entry;
		entry.index = r;
		Node<SparseMatrixEntry> *found_entry = list.search_by_value(entry, compare_sparse_arrays);

		if (found_entry) {
			found_entry->data.array->set_value(value, c);
		}
		else {
			SparseMatrixEntry new_entry;
			new_entry.index = r;
			new_entry.array = new SparseArray(cols_count);
			new_entry.array->set_value(value, c);
			list.insert_sorted(new_entry);
		}
	}

	int get_value(int r, int c) {
		assert(r < rows_count && r >= 0);
		assert(c < cols_count && c >= 0);

		SparseMatrixEntry entry;
		entry.index = r;
		Node<SparseMatrixEntry>* found_entry = list.search_by_value(entry, compare_sparse_arrays);

		if (found_entry) {
			return found_entry->data.array->get_value(c);
		}

		return 0;
	}

	void add_matrix(SparseMatrix* other) {
	 	DLinkedList<SparseMatrixEntry>* other_list = other->get_list();
		std::pair<size_t, size_t> other_length = other->get_length();

		assert(rows_count == other_length.first);
		assert(cols_count == other_length.second);

		Node<SparseMatrixEntry>* first = list.get_head();
		Node<SparseMatrixEntry>* second = other->get_list()->get_head();
		
		for (; second; second = second->next) {
			if (first) {
				if (first->data.index == second->data.index) {
					// if row already exist
					first->data.array->add_array(*second->data.array);
				}
				else {
					SparseMatrixEntry entry;
					entry.index = second->data.index;
					entry.array = new SparseArray(second->data.array->get_length());
					entry.array->add_array(*(second->data.array));
					list.insert_sorted(entry);
				}
				first = first->next;
			}
		}
	}

	void print_matrix() {
		Node<SparseMatrixEntry>* ptr = list.get_head();

		for (int i = 0; i < rows_count; ++i) {
			if (ptr && i == ptr->data.index) {
				ptr->data.array->print_array();
				ptr = ptr->next;
			}
			else {
				for (int j = 0; j < cols_count; ++j) {
					std::cout << "0 ";
				}
				std::cout << std::endl;
			}
		}
	}

	void print_matrix_nonzero() {
		Node<SparseMatrixEntry>* ptr = list.get_head();

		while (ptr) {
			ptr->data.array->print_array_non_zero();
			ptr = ptr->next;
		}
	}

	~SparseMatrix() {
		Node<SparseMatrixEntry>* ptr = list.get_head();

		while (ptr) {
			delete ptr->data.array;
			ptr = ptr->next;
		}
	}
};