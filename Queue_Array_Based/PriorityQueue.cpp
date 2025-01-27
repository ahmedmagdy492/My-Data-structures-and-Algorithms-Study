
#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int size) : size(size) {
	q1 = new Queue(size);
	q2 = new Queue(size);
	q3 = new Queue(size);
}

void PriorityQueue::enqueue(int value, int priority) {
	if (q1->IsFull() || q2->IsFull() || q3->IsFull())
		throw std::runtime_error("Queue is full");

	if (priority == 1) {
		q1->EnqeueRear(value);
	}

	if (priority == 2) {
		q2->EnqeueRear(value);
	}
	
	if (priority == 3) {
		q3->EnqeueRear(value);
	}
}

int PriorityQueue::dequeue() {
	if (!q3->IsEmpty()) {
		return q3->DeqeueFront();
	}

	if (!q2->IsEmpty()) {
		return q2->DeqeueFront();
	}

	if (!q1->IsEmpty()) {
		return q1->DeqeueFront();
	}

	throw std::runtime_error("Queue is empty");
}

int PriorityQueue::peek() {
	if (!q3->IsEmpty()) {
		return q3->Front();
	}

	if (!q2->IsEmpty()) {
		return q2->Front();
	}

	if (!q1->IsEmpty()) {
		return q1->Front();
	}

	throw std::runtime_error("Queue is empty");
}

void PriorityQueue::display() {
	q3->Display();
	q2->Display();
	q1->Display();
}

PriorityQueue::~PriorityQueue() {
	delete q1;
	delete q2;
	delete q3;
}