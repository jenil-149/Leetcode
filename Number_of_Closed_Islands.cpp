/**
 * LeetCode Problem: Number of Closed Islands
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

    void dfs(int x,int y,vector<vector<int>>& grid){
       
        grid[x][y]=1;

        for(int i=0;i<4;i++){
            int nr=x+dr[i];
            int nc=y+dc[i];

            if(isValid(nr,nc) && grid[nr][nc]!=1){
                dfs(nr,nc,grid);
            }
        }

    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        for(int j=0;j<m;j++) {
           if(grid[0][j]==0) dfs(0,j,grid);
           if(grid[n-1][j]==0)  dfs(n-1,j,grid);
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==0) dfs(i,0,grid);
            if(grid[i][m-1]==0) dfs(i,m-1,grid);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
