/**
 * LeetCode Problem: N-Queens
 * Pushed by LeetCommit
 * Date: 2026-07-12
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<vector<string>> ans;
    bool isSafe(int row,int col,vector<string> &board,int n){
        //check all till curr row only bcz we not have placed in lower rows
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q' && i!= row) return false;
        }

        int r=row;
        int c=col;
        // check upper left diagonal
        while(r>=0 && c>=0){
            if(board[r][c]=='Q') return false;
            r--;
            c--;
        }
        // check  upper right diagonal
        r=row;
        c=col;
        while(r>=0 && c<n){
           if(board[r][c]=='Q') return false;
            r--;
            c++;
        }
        return true;

    }

    void solve(int row,vector<string> &board,int n){
        if(row==n){
            ans.push_back(board);
        }

        for(int col=0;col<n;col++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(row+1,board,n);
                board[row][col]='.';
                
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));

        solve(0,board,n);
        return ans;
    }
};

int main() {
    return 0;
}
