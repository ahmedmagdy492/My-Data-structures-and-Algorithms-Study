#include "Stack.h"


Stack::Stack(size_t size) : size(size), added_elements(0) {
	arr = new int[size];
}

void Stack::array_shift_right() {
	for (int i = added_elements; i > 0; --i) {
		arr[i] = arr[i - 1];
	}
}


void Stack::array_shift_left() {
	for (int i = 0; i < added_elements-1; ++i) {
		arr[i] = arr[i + 1];
	}
}

bool Stack::push(int value) {
	if (is_full())
		return false;

	// 1.shift to the right by 1 element
	array_shift_right();
	// 2.set the first element of the array to the new value
	arr[0] = value;
	added_elements++;

	return true;
}

bool Stack::pop(int& value) {
	if (is_empty())
		return false;

	value = arr[0];
	// TODO: shift to the left by 1 element
	array_shift_left();
	added_elements--;

	return true;
}

bool Stack::peek(int& value) {
	if (is_empty())
		return false;

	value = arr[0];
	return true;
}

bool Stack::is_empty() {
	return added_elements == 0;
}

bool Stack::is_full() {
	return added_elements == size;
}

void Stack::display() {
	for (int i = 0; i < added_elements; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

Stack::~Stack() {
	if (arr)
		delete arr;
	arr = nullptr;
}