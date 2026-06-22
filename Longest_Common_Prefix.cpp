/**
 * LeetCode Problem: Longest Common Prefix
 * Pushed by LeetCommit
 * Date: 2026-06-22
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != ch) {
                    return ans;
                }
            }

            ans += ch;
        }

        return ans;
    }
};

int main() {
    return 0;
}
