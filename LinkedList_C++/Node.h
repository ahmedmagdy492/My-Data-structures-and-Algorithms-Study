#pragma once
#include <iostream>
using namespace std;

struct Node {
	int data{ };
	Node* next{ };
	Node(int data) : data(data) {}
	~Node() {
		cout << "Destroy value: " << data << " at address " << this << "\n";
	}
};