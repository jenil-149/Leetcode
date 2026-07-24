/**
 * LeetCode Problem: Sum of Matrix After Queries
 * Pushed by LeetCommit
 * Date: 2026-07-24
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {

        vector<int> rowFlag(n, 1), colFlag(n, 1);

        int leftRows = n;
        int leftCols = n;
        long long ans = 0;

        for (int q = queries.size() - 1; q >= 0; q--) {

            int type = queries[q][0];
            int idx  = queries[q][1];
            int val  = queries[q][2];

            if (type == 0 && rowFlag[idx]) {
                ans += 1LL * leftCols * val;
                rowFlag[idx] = 0;
                leftRows--;
            }

            if (type == 1 && colFlag[idx]) {
                ans += 1LL * leftRows * val;
                colFlag[idx] = 0;
                leftCols--;
            }
        }
        return ans;
    }
};



//brutforce results MLE

// class Solution {
// public:
//     long long matrixSumQueries(int n, vector<vector<int>>& queries) {

//         vector<vector<int>> grid(n,vector<int>(n,-1));
//         reverse(begin(queries),end(queries));
//         for(auto q:queries){
//             int type=q[0];
//             int idx=q[1];
//             int val=q[2];

//             if(type==0){
//                 for(int i=0;i<n;i++){
//                     if(grid[idx][i]==-1)
//                          grid[idx][i]=val;
//                 }
//             }
//             else{
//                 for(int i=0;i<n;i++){
//                     if(grid[i][idx]==-1)
//                          grid[i][idx]=val;
//                 }
//             }
//         }
//         long long ans=0;

//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 ans+=max(grid[i][j],0);
//             }
//         }
//         return ans;
//     }
// };

int main() {
    return 0;
}
