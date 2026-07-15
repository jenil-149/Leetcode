/**
 * LeetCode Problem: Equal Sum Grid Partition II
 * Pushed by LeetCommit
 * Date: 2026-07-15
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    
    typedef long long ll;
    ll total=0;
   

    bool checkCuts(vector<vector<int>> & grid){
        int m=grid.size();
        int n=grid[0].size();

        unordered_set<ll> s;
        ll top=0;

        for(int i=0;i<m-1;i++){
            for(int j=0;j<n;j++){
                s.insert(grid[i][j]);
                top+=grid[i][j];
            }
            ll bottom=total-top;
            ll diff=top-bottom;

            if(diff==0) return true;
            if(diff==(ll) grid[0][0]) return true;
            if(diff==(ll)grid[0][n-1]) return true;
            if(diff==(ll)grid[i][0]) return true;

            if(i>0 && n>1 && s.count(diff)) return true;
        }
        return false;
    }
    
    bool canPartitionGrid(vector<vector<int>>& grid) {
  
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                total+=grid[i][j];
            }
        }
        //check for horizontal cuts
        if(checkCuts(grid)) return true;
        //revserse so we get req elem in o(1)
        reverse(grid.begin(),grid.end());
        if(checkCuts(grid)) return true;

        //take transpose to reuse the same function
        vector<vector<int>> transposeGrid(n,vector<int>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                transposeGrid[j][i]=grid[i][j];
            }
        }

        if(checkCuts(transposeGrid)) return true;
        reverse(transposeGrid.begin(), transposeGrid.end());
        if(checkCuts( transposeGrid)) return true;

        //if nothing works return false
        return false;
        
    }
};

int main() {
    return 0;
}
