/**
 * LeetCode Problem: Dungeon Game
 * Pushed by LeetCommit
 * Date: 2026-07-28
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> dp(n,vector<int>(m,0));

        dp[n-1][m-1]=max(1,1-grid[n-1][m-1]);

        for(int i=n-2;i>=0;i--){
            dp[i][m-1]=max(1,dp[i+1][m-1]-grid[i][m-1]);
        }
        for(int i=m-2;i>=0;i--){
            dp[n-1][i]=max(1,dp[n-1][i+1]-grid[n-1][i]);
        }

        for( int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                int need=min(dp[i+1][j],dp[i][j+1])-grid[i][j];

                dp[i][j]=max(1,need);
            }
        }

        return dp[0][0];


    }
};

int main() {
    return 0;
}
