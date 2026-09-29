/**
 * LeetCode Problem: Check if There Is a Valid Parentheses String Path
 * Pushed by LeetCommit
 * Date: 2026-09-29
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    bool dfs(int i, int j, int bal, vector<vector<char>>& grid) {

        if (grid[i][j] == '(')
            bal++;
        else
            bal--;

        if (bal < 0)
            return false;

        if (i == n - 1 && j == m - 1)
            return bal == 0;

        if (dp[i][j][bal] != -1)
            return dp[i][j][bal];

        bool ans = false;

        if (i + 1 < n)
            ans |= dfs(i + 1, j, bal, grid);

        if (j + 1 < m)
            ans |= dfs(i, j + 1, bal, grid);

        return dp[i][j][bal] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // Path length must be even
        if ((n + m - 1) % 2)
            return false;

        dp.assign(n, vector<vector<int>>(
            m, vector<int>(n + m, -1)
        ));

        return dfs(0, 0, 0, grid);
    }
};

int main() {
    return 0;
}
