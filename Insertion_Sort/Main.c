#include <stdio.h>

/*
* 
InsertionSort(int arr[], int n):
Output: void -> will modify the original array

Steps:
-setup pointers i = 1, j = 0
-pick up the ith element and store it in a seperate variable called the key
-compare the key with elements from j to 0
-if the ith element is less than the current jth element:
 -place the jth element at the next position
 -place the ith element at the jth position
*/

void InsertionSort(int arr[], size_t n);

int CmpInts(void* key1, void* key2) {
	int* el1 = (int*)key1;
	int* el2 = (int*)key2;
	if (el1 < el2) {
		return -1;
	}
	else if(el1 == el2) {
		return 0;
	}

	return 1;
}

int main(void) {
	int nums[] = { 15, 3, 2, 40, 1 };

	size_t n = sizeof(nums) / sizeof(int);
	InsertionSort(nums, n, sizeof(int), CmpInts);

	int i = 0;

	for (; i < n; ++i) {
		printf("%d ", nums[i]);
	}

	printf("\n");
}

// ascending order sorting
void InsertionSort(int arr[], size_t n) {
	
	for (int i = 1; i < n; ++i) {
		int key = arr[i];
		for (int j = i-1; j >= 0; --j) {
			if (arr[i] < arr[j]) {
				arr[j + 1] = arr[j];
				arr[j] = key;
			}
		}
	}
}