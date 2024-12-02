#include "Stack.h"

Stack::Stack(size_t size) : size(size) {
	arr = new int[size];
}

void Stack::push(int value) {
	if(is_full())
		throw std::string("Stack is full");
	
	arr[++top] = value;
}

int Stack::pop() {
	if (is_empty())
		throw std::string("Stack is empty");

	return arr[top--];
}

int Stack::peek() {
	if (is_empty())
		throw std::string("Stack is empty");

	return arr[top];
}

bool Stack::is_empty() {
	return top == -1;
}

bool Stack::is_full() {
	return (top+1) == size;
}

void Stack::clear() {
	top = -1;
}

int Stack::stack_size() {
	return top+1;
}

void Stack::display() {
	for (int i = top; i >= 0; --i)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}

void Stack::shift_right(int arr[], int len) {
	if (len >= 1) {
		arr[len] = arr[len - 1];
		shift_right(arr, --len);
	}
}

void Stack::insert_at_bottom(int x) {
	if (is_empty()) {
		push(x);
	}
	else {
		int cur = pop();

		insert_at_bottom(x);

		push(cur);
	}
}

void Stack::reverse() {
	if (!is_empty()) {
		int cur = pop();
		reverse();
		insert_at_bottom(cur);
	}
}

Stack::~Stack() {
	if (arr)
		delete arr;
	arr = nullptr;
}