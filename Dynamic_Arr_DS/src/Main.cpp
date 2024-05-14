#include <iostream>

#include "../helpers/Vector.hpp"

int main() {
	Vector v(4);

	v.Set(0, 12);
	v.Set(1, 4);
	v.Set(2, 7);
	v.Set(3, 1);

	// Test Case 1: insert at index 0
	//v.Insert(0, 99);

	// Test Case 2: insert at the middle
	//v.Insert(2, 678);

	// Test Case 3: insert at out of bound index
	//v.Insert(43, 800);

	// Insert(Test Case 4): insert when the size > the internal capacity
	//v.Insert(2, 888);

	v.Print();
	std::cout << "---------------------------------------" << "\n";

	// RotateRight(Test Case 1): rotate one item at a time
	/*v.RotateToRight();
	v.RotateToRight();

	v.RotateToLeft();
	v.RotateToLeft();*/

	//v.RotateToRight(1000000);

	int result = v.Pop(0);
	//v.FindTranspose(1);
	//v.FindTranspose(1);

	v.Print();
}