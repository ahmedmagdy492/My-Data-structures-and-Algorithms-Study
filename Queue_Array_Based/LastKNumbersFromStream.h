#pragma once

#include <iostream>
#include <queue>

using namespace std;

class LastKNumbersFromStream {
private:
	int k, sum;
	int added_elements;
	queue<int> q;

public:
	LastKNumbersFromStream(int k) : k(k), added_elements(0), sum(0) {
	}

	int next(int new_num) {
		q.push(new_num);
		sum += new_num;
		added_elements++;

		if (added_elements > k) {
			sum -= q.front();
			q.pop();
			added_elements--;
		}

		return sum;
	}

	/*int next(int new_num) {
		int start = std::max(1, new_num + 1 - k);
		int end = new_num;
		int sum = 0;

		for (int i = start; i <= end; ++i) {
			sum += i;
		}

		return sum;
	}*/
};