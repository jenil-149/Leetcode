/**
 * LeetCode Problem: Roman to Integer
 * Pushed by LeetCommit
 * Date: 2026-08-24
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    int n = s.size();

    // Iterate through the string
    for (int i = 0; i < n; ++i) {
        if (i + 1 < n && romanMap[s[i]] < romanMap[s[i + 1]]) {
            result -= romanMap[s[i]];
        } else {
            // Otherwise, add its value
            result += romanMap[s[i]];
        }
    }

    return result;
    }
};


int main() {
    return 0;
}
