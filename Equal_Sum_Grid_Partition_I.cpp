/**
 * LeetCode Problem: Equal Sum Grid Partition I
 * Pushed by LeetCommit
 * Date: 2026-07-15
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        // vector<ll> rowSum(m,0);
        // vector<ll> colSum(n,0);
        ll total=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                total+=grid[i][j];
                // rowSum[i]+=grid[i][j];
                // colSum[j]+=grid[i][j];
            }
        }
        ll sum=0;
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n;j++){
                sum+=grid[i][j];
            }
            if(sum*2==total) return true; 
        }
        sum=0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                sum+=grid[j][i];
            }
            if(sum*2==total) return true; 
        }
        
        return false;
    }
};

int main() {
    return 0;
}
