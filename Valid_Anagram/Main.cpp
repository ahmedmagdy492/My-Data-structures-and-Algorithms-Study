#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        size_t sLen = s.length(), tLen = t.length();
        if (sLen != tLen)
            return false;

        unordered_map<char, int> tbl;  // O(s) memory

        for (int i = 0; i < sLen; ++i) {  // O(s)
            if (tbl.find(s[i]) != tbl.end())
                tbl[s[i]]++;
            else
                tbl.insert({ s[i], 1 });
        }

        for (int i = 0; i < tLen; ++i) { // O(t)
            if (tbl.find(t[i]) != tbl.end()) {
                if (tbl[t[i]] == 0) {
                    return false;
                }
                else {
                    tbl[t[i]]--;
                }
            }
            else {
                return false;
            }
        }

        // O(s+t)

        return true;
    }
};

int main() {
    // Test Case 1
    Solution sol;
    string s = "anagram", t = "nagaram";
    bool result = sol.isAnagram(s, t);
    bool expected = true;

    if (result == expected) {
        cout << "Test with " << s << ", " << t << " has successfully passed the test" << endl;
    }
    else {
        cout << "Test with " << s << ", " << t << " has failed" << endl;
    }

    // Test Case 2
    s = "rat";
    t = "car";
    result = sol.isAnagram(s, t);
    expected = false;

    if (result == expected) {
        cout << "Test with " << s << ", " << t << " has successfully passed the test" << endl;
    }
    else {
        cout << "Test with " << s << ", " << t << " has failed" << endl;
    }
}