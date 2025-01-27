#include <iostream>

#include "Queue.h"

int main() {
	Queue queue;

	queue.Enqueue(12);
	queue.Enqueue(45);
	queue.Enqueue(78);

	queue.Dequeue();

	queue.Display();
}