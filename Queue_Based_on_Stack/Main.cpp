#include <iostream>

#include "Queue.h"

int main() {
	Queue qu(6);

	for (int i = 1; i <= 3; ++i) {
		qu.Enqueue(i);
	}

	while (!qu.IsEmpty()) {
		std::cout << qu.Dequeue() << std::endl;
	}
}