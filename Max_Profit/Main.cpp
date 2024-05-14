#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) { // O(n^2)
        int maxValue = 0;
        size_t size = prices.size();

        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                int diff = prices[j] - prices[i];
                if (diff > maxValue) {
                    maxValue = diff;
                }
            }
        }

        return maxValue;
    }

    int maxProfitBetter(vector<int>& prices) {
        int maxProfit = 0;
        size_t size = prices.size();

        for (int i = 0, j = i + 1; j < size; ) {
            if ((prices[j] - prices[i]) < 0) {
                i = j;
                ++j;
            }
            else if ((prices[j] - prices[i]) >= 0) {
                if ((prices[j] - prices[i]) > maxProfit) {
                    maxProfit = prices[j] - prices[i];
                }
                ++j;
            }
        }

        return maxProfit;
    }
};

int main() {
    vector<int> input = {7, 1, 5, 3, 6, 4};
    Solution sol;
    int expected = 5;
    int actual = sol.maxProfitBetter(input);

    if (expected == actual) {
        cout << "Test Case 1 Succeded" << endl;
    }
    else {
        cout << "Test Case 1 Failed" << endl;
    }

    vector<int> input2 = { 7,6,4,3,1 };
    expected = 0;
    actual = sol.maxProfitBetter(input2);

    if (expected == actual) {
        cout << "Test Case 2 Succeded" << endl;
    }
    else {
        cout << "Test Case 2 Failed" << endl;
    }
}