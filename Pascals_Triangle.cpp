/**
 * LeetCode Problem: Pascal's Triangle
 * Pushed by LeetCommit
 * Date: 2026-07-15
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
       

        for(int i=0;i<numRows;i++){
            ans[i].resize(i+1,0);
           for(int j=0;j<=i;j++){
            if(j==0 || j==i){
                ans[i][j]=1;
            }
            else{
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
            }
           } 
        }
        return ans;
    }
};

int main() {
    return 0;
}
