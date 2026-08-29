/**
 * LeetCode Problem: Pacific Atlantic Water Flow
 * Pushed by LeetCommit
 * Date: 2026-08-29
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int n,m;
    bool isValid(int r,int c){
        return( r>=0&& r<n && c>=0 && c<m);
    }
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};

    void dfs(int x,int y,vector<vector<int>>& h,vector<vector<int>>& vis){
        if(vis[x][y]) return;
        vis[x][y]=1;

        for(int i=0;i<4;i++){
            int r=x+dr[i];
            int c=y+dc[i];

            if(isValid(r,c) && !vis[r][c] && h[r][c]>=h[x][y]){
                dfs(r,c,h,vis);
            }
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        n=h.size();
        m=h[0].size();
        vector<vector<int>> a(n,vector<int>(m,0));
        vector<vector<int>> p(n,vector<int>(m,0));

        for(int j=0;j<m;j++){
            dfs(n-1,j,h,a);
            dfs(0,j,h,p);
        }
        for(int i=0;i<n;i++) {
            dfs(i,m-1,h,a);
            dfs(i,0,h,p);
        }

        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(p[i][j] && a[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}
