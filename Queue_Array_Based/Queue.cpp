
#include "Queue.h"

#include <iostream>

Queue::Queue(int size) : size(size) {
	arr = new int[size];
}

int Queue::GetNextPosition(int x) {
	return (x+1) % size;
}

int Queue::GetPreviousPosition(int x) {
	if (x == 0) {
		return size - 1;
	}

	return x-1;
}

void Queue::EnqeueRear(int value) {
	if (IsFull())
		throw std::runtime_error("Queue is full");

	arr[rear] = value;
	rear = GetNextPosition(rear);
	added_elements++;
}

int Queue::DeqeueFront() {
	if (IsEmpty())
		throw std::runtime_error("Queue is empty");

	int value = arr[front];
	front = GetNextPosition(front);
	added_elements--;
	return value;
}

void Queue::EnqeueFront(int value) {
	if (IsFull())
		throw std::runtime_error("Queue is full");

	front = GetPreviousPosition(front);
	arr[front] = value;
	added_elements++;
}

int Queue::DeqeueRear() {
	if (IsEmpty())
		throw std::runtime_error("Queue is empty");

	rear = GetPreviousPosition(rear);
	int valueToReturn = arr[rear];
	added_elements--;
	return valueToReturn;
}

bool Queue::IsFull() const {
	return added_elements >= size;
}

bool Queue::IsEmpty() const {
	return added_elements <= 0;
}

void Queue::Display() {
	for (int cur = front, step = 0; step < added_elements; ++step, cur = GetNextPosition(cur)) {
		std::cout << arr[cur] << " ";
	}
	std::cout << "\n";
}

Queue::~Queue() {
	delete[] arr;
}