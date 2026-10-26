/**
 * LeetCode Problem: Count Islands With Total Value Divisible by K
 * Pushed by LeetCommit
 * Date: 2026-10-26
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int n,m;
    // vector<vector<int>> vis;
    int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};

    bool isValid(int i,int j){
        return (i<n && i>=0 && j<m && j>=0);
    }

    int dfsSum(int x,int y,vector<vector<int>>& grid,int k){
        int sum=grid[x][y]%k;
        grid[x][y]=0;

        for(int i=0;i<4;i++){
            int nr=x+dr[i];
            int nc=y+dc[i];

            if(isValid(nr,nc) && grid[nr][nc]!=0){
                sum=(sum+dfsSum(nr,nc,grid,k))%k;
            }
        }

        return sum%k;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]!=0){
                    int total=dfsSum(i,j,grid,k);
                    if(total%k==0) ans++;
                }
               
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}
