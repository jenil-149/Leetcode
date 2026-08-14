/**
 * LeetCode Problem: Minimum Additions to Make Valid String
 * Pushed by LeetCommit
 * Date: 2026-08-14
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int addMinimum(string word) {
        int k = 0, prev = 'z';
        for (char& c: word) {
            k += c <= prev;
            prev = c;
        }
        return k*3 - word.size();
    }
};

int main() {
    return 0;
}
