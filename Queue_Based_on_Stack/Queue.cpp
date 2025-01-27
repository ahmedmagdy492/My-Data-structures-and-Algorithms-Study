
#include "Queue.h"

#include <iostream>

Queue::Queue(int size) : addedElements(0), size(size) {
}

void Queue::Enqueue(int value) {
	if (IsFull()) {
		throw std::runtime_error("Queue is full");
	}

	if (enqueueStack.empty()) {
		enqueueStack.push(value);
	}
	else {
		while (!enqueueStack.empty()) {
			dequeueStack.push(enqueueStack.top());
			enqueueStack.pop();
		}

		enqueueStack.push(value);

		while (!dequeueStack.empty()) {
			enqueueStack.push(dequeueStack.top());
			dequeueStack.pop();
		}
	}

	addedElements++;
}

int Queue::Dequeue() {
	if (IsEmpty()) {
		throw std::runtime_error("Queue is empty");
	}

	if (dequeueStack.empty()) {
		while (!enqueueStack.empty()) {
			dequeueStack.push(enqueueStack.top());
			enqueueStack.pop();
		}

		--addedElements;
		int valueToRet = dequeueStack.top();
		dequeueStack.pop();
		return valueToRet;
	}

	--addedElements;
	int valueToRet = dequeueStack.top();
	dequeueStack.pop();
	return valueToRet;
}

bool Queue::IsEmpty() const {
	return enqueueStack.empty() && dequeueStack.empty();
}

bool Queue::IsFull() const {
	return addedElements == size;
}

Queue::~Queue() {

}