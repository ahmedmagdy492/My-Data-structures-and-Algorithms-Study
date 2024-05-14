#pragma once

#include <iostream>

class Vector {
private:
	size_t capcity;
	size_t size;
	int* arr;

	void Reallocate() {
		int* temp = arr;
		capcity *= 2;
		arr = new int[capcity];

		for (int i = 0; i < size; ++i) {
			arr[i] = temp[i];
		}
		delete[] temp;
	}

	void ShiftToTheRight(int* arr, int start, int size) {
		for (int i = size - 1; i >= start; --i) {
			arr[i + 1] = arr[i];
		}
	}

	void ShiftToTheLeft(int* arr, int start) {
		for (int i = start; i < size; ++i) {
			arr[i] = arr[i+1];
		}
	}

	void Swap(int* val1, int* val2) {
		int temp = *val1;
		*val1 = *val2;
		*val2 = temp;
	}

public:
	Vector(size_t size) : capcity(100), size(size) {
		if (size < 0)
			size = 10;
		arr = new int[capcity];
	}

	~Vector() {
		delete[] arr;
		arr = nullptr;
	}

	void Set(int index, int value) {
		if (index >= 0 || index < size)
			arr[index] = value;
	}

	int Get(int index) {
		if (index < 0 || index > size)
			throw "Invalid Index";

		return arr[index];
	}

	void Print() {
		for (int i = 0; i < size; ++i) {
			std::cout << arr[i] << std::endl;
		}
	}

	int Find(int value) {
		for (int i = 0; i < capcity; ++i) {
			if (arr[i] == value)
				return i;
		}

		return -1;
	}

	void Append(int value) {
		if (size >= capcity) {
			Reallocate();
		}
		arr[size++] = value;
	}

	void Insert(int index, int value) {
		if (index >= size) {
			throw "Index out of bound";
			return;
		}

		int sizeOfElementsToShift = size - index;
		if (++size >= capcity) {
			Reallocate();
		}

		ShiftToTheRight(arr, index, sizeOfElementsToShift);
		arr[index] = value;
	}

	void RotateToRight() {
		int temp = arr[size-1];

		for (int i = size - 2; i >= 0; --i) {
			arr[i + 1] = arr[i];
		}

		arr[0] = temp;
	}

	void RotateToRight(int times) {
		int r = times % size;
		if (r == 0) {
			times = size;
		}
		else {
			times = r;
		}

		for (int i = 0; i < times; ++i) {
			RotateToRight();
		}
	}

	void RotateToLeft() {
		int temp = arr[0];

		for (int i = 0; i < size; ++i) {
			arr[i] = arr[i+1];
		}

		arr[size-1] = temp;
	}

	int Pop(int index) {
		if (index < 0 || index >= size) {
			throw "Index out of bound";
			return -1;
		}

		int temp = arr[index];
		ShiftToTheLeft(arr, index);
		--size;
		return temp;
	}

	int FindTranspose(int value) {
		for (int i = 0; i < size; ++i) {
			if (arr[i] == value) {
				if (i > 0) {
					Swap(&arr[i], &arr[i - 1]);
					return i - 1;
				}
			}
		}
	}
};