/**
 * LeetCode Problem: Minimum Path Sum
 * Pushed by LeetCommit
 * Date: 2026-07-22
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<int> prev(m);
        prev[0] = grid[0][0];

        //take cumm. sum of the top row
        for(int j=1;j<m;j++)
         prev[j] = prev[j-1] + grid[0][j];

        for(int i=1;i<n;i++){

            vector<int> curr(m);
            //take sum of prev[0]+curr grid idxes
            curr[0]=prev[0]+grid[i][0];

            for(int j=1;j<m;j++){
                curr[j]= grid[i][j]+min(curr[j-1],prev[j]);
            }
            prev=curr;
        }
        return prev[m-1];
    }
};

int main() {
    return 0;
}
