/**
 * LeetCode Problem: Stone Game II
 * Pushed by LeetCommit
 * Date: 2026-08-03
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int n;
    int dp[101][101];
    vector<int> suffix;

    int solve(int i, int M) {

        if(i >= n) return 0;
        if(2 * M >= n - i)  return suffix[i];

        if(dp[i][M] != -1) return dp[i][M];

        int ans = 0;

        for(int x = 1; x <= 2 * M; x++) {
            ans = max(ans,suffix[i] - solve(i + x, max(M, x)));
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();
        memset(dp, -1, sizeof(dp));

        suffix.resize(n + 1, 0);
        for(int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + piles[i];

        return solve(0, 1);
    }
};

int main() {
    return 0;
}
