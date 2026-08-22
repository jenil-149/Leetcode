/**
 * LeetCode Problem: Number of ZigZag Arrays I
 * Pushed by LeetCommit
 * Date: 2026-08-22
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m=r-l+1;
        const int MOD=1e9+7;
        vector<int> dp(m, 1);

        for (int i = 2; i <= n; i++) {

            // Turn suffix sums into prefix sums
            reverse(dp.begin(), dp.end());

            // Compute prefix sums in-place
            int sum = 0;
            for (auto& d : dp) {
                int old = d;
                d = sum;
                sum = (sum + old) % MOD;
            }
        }
        return ((accumulate(dp.begin(), dp.end(), 0LL) % MOD) << 1) % MOD;
    }
};

int main() {
    return 0;
}
