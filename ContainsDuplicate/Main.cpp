#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int count = 1;
        size_t n = nums.size(); // 1
        for (int i = 0; i < n; ++i) { // 2+n+n
            int el = nums[i]; // n
            for (int j = i + 1; j < n; ++j) { // n + n+1*n + n
                if (el == nums[j]) {  // n * n
                    return true;
                }
            }
        }

        return false;
    }

    bool containsDuplicateBetter(vector<int>& nums) {
        auto hashtbl = map<int, int>();
        size_t n = nums.size();

        for (int i = 0; i < n; ++i) {
            int el = nums[i];
            if (hashtbl.find(el) != hashtbl.end()) {
                return true;
            }
            else {
                hashtbl.insert({ el, 1 });
            }
        }

        return false;
    }
};

void AssertBoolean(string headLine, bool actual, bool expected) {
    static int count = 1;
    cout << "Test Case " << count++ << ": " << headLine << "\n";

    if (actual == expected) {
        cout << "Test Successeded" << "\n";
    }
    else {
        cout << "Test Failed" << "\n";
    }
}

int main() {
    Solution sol;

    auto nums = vector<int>();
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);

    bool result = sol.containsDuplicate(nums);

    AssertBoolean("[1, 2, 3, 1]:", result, true);

    nums.clear();
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    result = sol.containsDuplicate(nums);

    AssertBoolean("[1, 2, 3, 4]:", result, false);

    nums.clear();
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(2);

    result = sol.containsDuplicate(nums);

    AssertBoolean("[1,1,1,3,3,4,3,2,4,2]:", result, true);
}