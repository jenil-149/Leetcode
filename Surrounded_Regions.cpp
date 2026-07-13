/**
 * LeetCode Problem: Surrounded Regions
 * Pushed by LeetCommit
 * Date: 2026-07-13
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:

    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};

    bool isValid(int r,int c,int n,int m){
        return r>=0 && r<n && c>=0 && c<m;
    }

    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>& vis,int n,int m)
    {
        vis[row][col]=1;

        for(int i=0;i<4;i++){
            int r=row+dr[i];
            int c=col+dc[i];

            if(isValid(r,c,n,m) && board[r][c]=='O' && !vis[r][c])
                dfs(r,c,board,vis,n,m);
        }
    }

    void solve(vector<vector<char>>& board) {

        int n=board.size();
        int m=board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O' && !vis[i][0]) dfs(i,0,board,vis,n,m);
            if(board[i][m-1]=='O' && !vis[i][m-1]) dfs(i,m-1,board,vis,n,m);
        }

        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O' && !vis[0][j]) dfs(0,j,board,vis,n,m);
            if(board[n-1][j]=='O' && !vis[n-1][j]) dfs(n-1,j,board,vis,n,m);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j])
                {
                    board[i][j]='X';
                }
            }
        }
    }
};

int main() {
    return 0;
}
