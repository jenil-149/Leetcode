/**
 * LeetCode Problem: Number of Ways to Assign Edge Weights I
 * Pushed by LeetCommit
 * Date: 2026-07-10
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    const long long MOD = 1000000007;

    long long power(long long base, long long exp) {
    if (exp == 0) return 1;

    long long half = power(base, exp / 2);
    long long result = (half * half) % MOD;

    if (exp & 1)
        result = (result * base) % MOD;

    return result;
}

    int getDepth(unordered_map<int,vector<int>> &adj,int node,int parent)
    {
        int depth=0;
        for(auto it:adj[node]){
            if( it==parent) continue;

            depth=max(depth,1+getDepth(adj,it,node));

        }
        return depth;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int d=getDepth(adj,1,-1);

        return power(2,d-1);
    }
};

int main() {
    return 0;
}
