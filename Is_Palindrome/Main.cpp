#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string& lowerStr(string& str) {
        size_t len = str.length();
        for (int i = 0; i < len; ++i) {
            str[i] = tolower(str[i]);
        }

        return str;
    }

    bool isPalindrome(string s) {
        s = lowerStr(s);
        size_t len = s.length();

        for (int i = 0, j = len - 1; i < j; ++i, --j) {
            if (!iswalnum(s[i])) {
                while (!iswalnum(s[i]) && i < j) {
                    ++i;
                }
            }
            if (!iswalnum(s[j])) {
                while (!iswalnum(s[j]) && j > i) {
                    --j;
                }
            }
            
            if (s[i] != s[j]) {
                return false;
            }
        }

        return true;
    }

    bool isPalindromeBetter(string s) {
        s = lowerStr(s);
        size_t len = s.length();
        vector<char> str;

        for (int i = 0; i < len; ++i) {
            if (isalnum(s[i])) {
                str.push_back(s[i]);
            }
        }

        len = str.size();
        for (int i = 0, j = len - 1; i < j; ++i, --j) {
            if (str[i] != str[j]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    string str = "A man, a plan, a canal: Panama";
    bool result = sol.isPalindromeBetter(str);
    bool expected = true;

    if (result == expected) {
        cout << "Test 1 Successeded" << endl;
    }
    else {
        cout << "Test 1 Failed" << endl;
    }

    // Test Case 2
    str = "race a car";
    result = sol.isPalindromeBetter(str);
    expected = false;

    if (result == expected) {
        cout << "Test 2 Successeded" << endl;
    }
    else {
        cout << "Test 2 Failed" << endl;
    }

    // Test Case 3
    str = " ";
    result = sol.isPalindromeBetter(str);
    expected = true;

    if (result == expected) {
        cout << "Test 3 Successeded" << endl;
    }
    else {
        cout << "Test 3 Failed" << endl;
    }
}