/**
 * LeetCode Problem: Smallest String With A Given Numeric Value
 * Pushed by LeetCommit
 * Date: 2026-08-19
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        k -= n;  // remaining value after assigning 'a' to every position

        for (int i = n - 1; i >= 0 && k > 0; i--) {
            int add = min(25, k);
            ans[i] += add;
            k -= add;
        }

        return ans;
    }
};

int main() {
    return 0;
}
