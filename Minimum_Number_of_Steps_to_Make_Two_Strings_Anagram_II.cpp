/**
 * LeetCode Problem: Minimum Number of Steps to Make Two Strings Anagram II
 * Pushed by LeetCommit
 * Date: 2026-08-05
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c-'a']++;

        int common = 0;

        for (char c : t) {
            if (freq[c-'a'] > 0) {
                common++;
                freq[c-'a']--;
            }
        }

        return s.size() + t.size() - 2*common;
    }
};

int main() {
    return 0;
}
