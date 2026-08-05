/**
 * LeetCode Problem: Find the Divisibility Array of a String
 * Pushed by LeetCommit
 * Date: 2026-08-05
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long rem = 0;
        vector<int> ans;

        for (char c : word) {
            rem = (rem * 10 + (c - '0')) % m;

            if (rem == 0)
                ans.push_back(1);
            else
                ans.push_back(0);
        }

        return ans;
    }
};

int main() {
    return 0;
}
