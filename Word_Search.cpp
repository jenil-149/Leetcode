/**
 * LeetCode Problem: Word Search
 * Pushed by LeetCommit
 * Date: 2026-07-17
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
   
    vector<vector<int>> vis;
    int m,n;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};

    bool isValid(int x,int y){
        return(x<m && x>=0 && y>=0 && y<n);
    }

    bool dfs(int x,int y,int idx,string& word,vector<vector<char>>& board){
        if(idx==word.size()) return true;

        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int row=x+dr[i];
            int col=y+dc[i];

            if( isValid(row,col) && !vis[row][col] && word[idx]==board[row][col]){
                if(dfs(row,col,idx+1,word,board)) return true;
            }
        }
        vis[x][y]=0;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
         vis.assign(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0]==board[i][j]){
                    if(dfs(i,j,1,word,board)) return true;
                }
            }
        }

        return false;
    }
};

int main() {
    return 0;
}
