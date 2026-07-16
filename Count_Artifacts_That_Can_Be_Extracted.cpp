/**
 * LeetCode Problem: Count Artifacts That Can Be Extracted
 * Pushed by LeetCommit
 * Date: 2026-07-16
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
       // using set(can sotore pair) nlogn
       //using unoredered set(cannot store pair) tc=n
       unordered_set<long long> s;

        for(auto it:dig){
            s.insert(1LL*it[0]*n+it[1]);
        }
        int ans=0;
        for(auto p:artifacts){

            int r1=p[0];
            int r2=p[2];
            int c1=p[1];
            int c2=p[3];

            int isDug=1;

            for(int i=r1;i<=r2;i++){
                for(int j=c1;j<=c2;j++){
                    if(!s.count(1LL*i*n+j))
                    {
                        isDug=0;
                        break;
                    }
                }
            }
            ans+=isDug;
        }
        
        return ans;
    }
};









// time compexity o(n^2) space O(n^2)
//not optimal

// class Solution {
// public:
//     int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
//         int m=artifacts.size();
//         vector<int> arr(m,0);

//         vector<vector<int>> grid(n,vector<int>(n,-1));

//         for(int k=0;k<m;k++){
//             for(int i=artifacts[k][0];i<=artifacts[k][2];i++){
//                 for(int j=artifacts[k][1];j<=artifacts[k][3];j++){
//                     grid[i][j]=k;
//                     arr[k]++;
//                 }
//             }
//         }
//         for(auto it:dig){
//             int r=it[0];
//             int c=it[1];
//             if(grid[r][c]!=-1)
//             arr[grid[r][c]]--;
//         }
//         int ans=0;
//         for(int i=0;i<m;i++){
//             if(arr[i]==0) ans++;
//         }
        
//         return ans;
//     }
// };

int main() {
    return 0;
}
