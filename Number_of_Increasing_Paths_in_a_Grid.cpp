/**
 * LeetCode Problem: Number of Increasing Paths in a Grid
 * Pushed by LeetCommit
 * Date: 2026-07-23
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<vector<int>> dp;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
    int n,m;
    int mod=1e9+7;
    int dfs(int r,int c,vector<vector<int>> & grid){

        if(dp[r][c]!=-1) return dp[r][c];
        
        long long ans=1;

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]>grid[r][c] ){
                ans=(ans+dfs(nr,nc,grid))%mod;
            }
        }
        return dp[r][c]=ans;
    }

    int countPaths(vector<vector<int>>& grid) {
        
        n=grid.size();
        m=grid[0].size();
        dp.assign(n,vector<int>(m,-1));

        long long ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=(ans+dfs(i,j,grid))%mod;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
