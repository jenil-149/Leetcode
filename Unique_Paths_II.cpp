/**
 * LeetCode Problem: Unique Paths II
 * Pushed by LeetCommit
 * Date: 2026-07-22
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<int> dp(m,0);
        dp[0]=(grid[0][0]==1)?0:1;
        for(int i=1;i<m;i++){
            if(grid[0][i]==1) dp[i]=0;
            else dp[i]=dp[i-1];
        } 

        for(int i=1;i<n;i++){

            vector<int> curr(m,0);
            if(grid[i][0]==1) curr[0]=0;
            else curr[0]=dp[0];

            for(int j=1;j<m;j++){

                if(grid[i][j]==1) curr[j]=0;
                else curr[j]=dp[j]+curr[j-1];
            }
            dp=curr;
        }
        return dp[m-1];

    }
};

int main() {
    return 0;
}
