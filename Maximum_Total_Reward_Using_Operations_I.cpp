/**
 * LeetCode Problem: Maximum Total Reward Using Operations I
 * Pushed by LeetCommit
 * Date: 2026-09-04
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int maxTotalReward(vector<int>& rewards) {
        sort(rewards.begin(), rewards.end());

        int sum = accumulate(rewards.begin(), rewards.end(), 0);

        vector<bool> dp(sum + 1, false);
        dp[0] = true;

        int ans = 0;

        for (int x : rewards) {
            // x can be taken only when current reward < x
            for (int curr = x - 1; curr >= 0; --curr) {
                if (dp[curr]) {
                    dp[curr + x] = true;
                    ans = max(ans, curr + x);
                }
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}
