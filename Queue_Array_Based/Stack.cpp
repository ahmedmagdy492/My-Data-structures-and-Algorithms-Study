#include "Stack.h"

Stack::Stack(int size) : added_elements(0) {
	q = new Queue(size);
}

void Stack::Push(int value) {
	q->EnqeueRear(value);
	++added_elements;
}

int Stack::Pop() {
	int value = q->DeqeueRear();
	--added_elements;
	return value;
}

int Stack::Peek() {
	int poppedValue = q->DeqeueRear();
	q->EnqeueRear(poppedValue);
	return poppedValue;
}

bool Stack::IsEmpty() {
	return q->IsEmpty();
}

bool Stack::IsFull() {
	return q->IsFull();
}

Stack::~Stack() {
	delete q;
}