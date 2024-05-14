#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> tbl;
        size_t len = nums.size();

        for (int i = 0; i < len; ++i) {
            if (tbl.find(nums[i]) != tbl.end()) {
                result.push_back(tbl[nums[i]]);
                result.push_back(i);
                return result;
            }
            else {
                tbl.insert({ target - nums[i], i });
            }
        }

        return result;
    }
};

bool compareVecs(vector<int>& actual, vector<int>& expected) {
    for (int i = 0; i < actual.size(); ++i) {
        return actual[i] == expected[i];
    }

    return false;
}

int main() {
    Solution sol;
    vector<int> in1 = { 2,7,11,15 };
    auto result = sol.twoSum(in1, 9);
    vector<int> expected = { 0, 1 };

    bool testResult = compareVecs(result, expected);
    if (testResult) {
        cout << "Test Case 1 Success" << endl;
    }
    else {
        cout << "Test Case 1 Failed" << endl;
    }

    // Test Case 2
    vector<int> in2 = { 3,2,4 };
    result = sol.twoSum(in2, 6);
    expected = { 1, 2 };

    testResult = compareVecs(result, expected);
    if (testResult) {
        cout << "Test Case 2 Success" << endl;
    }
    else {
        cout << "Test Case 2 Failed" << endl;
    }

    // Test Case 3

    vector<int> in3 = { 3,3 };
    result = sol.twoSum(in3, 6);
    expected = { 0, 1 };

    testResult = compareVecs(result, expected);
    if (testResult) {
        cout << "Test Case 3 Success" << endl;
    }
    else {
        cout << "Test Case 3 Failed" << endl;
    }
}