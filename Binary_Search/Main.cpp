#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, end = nums.size()-1;
        static int counter = 0;

        while (low <= end) {
            int midIndex = (low + end) / 2;
            counter++;
            if (nums[midIndex] == target) {
                cout << "count: " << counter << ", len: " << nums.size() << endl;
                return midIndex;
            }
            else if (nums[midIndex] > target) {
                end = midIndex-1;
            }
            else {
                low = midIndex+1;
            }
        }

        cout << "count: " << counter << ", len: " << nums.size() << endl;
        return -1;
    }
};

int main() {
    vector<int> nums = { -1, 0, 3, 5, 9, 12 };
    int target = 9;
    Solution sol;

    // Test Case 1
    int result = sol.search(nums, target);
    int expected = 4;

    if (result == expected) {
        cout << "Test Case 1 Successeded" << endl;
    }
    else {
        cout << "Test Case 1 Failed" << endl;
    }

    // Test Case 2
    vector<int> nums2 = { -1,0,3,5,9,12 };
    target = 2;
    result = sol.search(nums2, target);
    expected = -1;

    if (result == expected) {
        cout << "Test Case 2 Successeded" << endl;
    }
    else {
        cout << "Test Case 2 Failed" << endl;
    }


    // Test Case 3
    vector<int> nums3 = { 5 };
    target = 5;
    result = sol.search(nums3, target);
    expected = 0;

    if (result == expected) {
        cout << "Test Case 3 Successeded" << endl;
    }
    else {
        cout << "Test Case 3 Failed" << endl;
    }

    // Test Case 4
    target = -5;
    result = sol.search(nums3, target);
    expected = -1;

    if (result == expected) {
        cout << "Test Case 4 Successeded" << endl;
    }
    else {
        cout << "Test Case 4 Failed" << endl;
    }
}