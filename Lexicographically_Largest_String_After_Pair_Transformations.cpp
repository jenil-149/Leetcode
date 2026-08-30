/**
 * LeetCode Problem: Lexicographically Largest String After Pair Transformations
 * Pushed by LeetCommit
 * Date: 2026-08-30
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;

        for (int x : nums) {
            string s;

            int high = x >> 26;
            s.append(high * 2, 'z');

            x &= (1 << 26) - 1;

            for (int bit = 25; bit >= 0; --bit) {
                if (x & (1 << bit)) {
                    s += char('a' + bit);
                }
            }

            ans.push_back(s);
        }

        return ans;
    }
};

int main() {
    return 0;
}
