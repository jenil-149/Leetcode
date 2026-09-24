/**
 * LeetCode Problem: Count Paths With the Given XOR Value
 * Pushed by LeetCommit
 * Date: 2026-09-24
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int n, m;
    const int mod = 1e9 + 7;
    int dp[301][301][16];

    int f(int i, int j, vector<vector<int>>& grid, int x) {
        x ^= grid[i][j];

        if (i == n - 1 && j == m - 1)
            return x == k ? 1 : 0;

        if (dp[i][j][x] != -1)
            return dp[i][j][x];

        int ans = 0;

        if (i + 1 < n)
            ans += f(i + 1, j, grid, x);

        if (j + 1 < m)
            ans += f(i, j + 1, grid, x);

        return dp[i][j][x] = ans % mod;
    }

    int k;

    int countPathsWithXorValue(vector<vector<int>>& grid, int K) {
        n = grid.size();
        m = grid[0].size();
        k = K;

        memset(dp, -1, sizeof(dp));

        return f(0, 0, grid, 0);
    }
};

int main() {
    return 0;
}
