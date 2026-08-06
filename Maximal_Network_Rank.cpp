/**
 * LeetCode Problem: Maximal Network Rank
 * Pushed by LeetCommit
 * Date: 2026-08-06
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> connectedRoads(n,0);
        vector<vector<int>> adj(n,vector<int>(n,0));

        for(auto r:roads){
            connectedRoads[r[0]]++;
            connectedRoads[r[1]]++;
            adj[r[0]][r[1]]=1;  
            adj[r[1]][r[0]]=1;        
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int totalRoads=connectedRoads[i]+connectedRoads[j]-adj[i][j];
                ans=max(ans,totalRoads);
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
