/**
 * LeetCode Problem: Find if Path Exists in Graph
 * Pushed by LeetCommit
 * Date: 2026-08-06
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    bool dfs(int node,vector<int> adj[],vector<int> &vis,int dest){
        if(node==dest) return true;
        vis[node]=1;

        for(auto ngbr:adj[node]){
            if(!vis[ngbr]){
                if(dfs(ngbr,adj,vis,dest)==true) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        vector<int> adj[n];

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n,0);
        return dfs(src,adj,vis,dest);
    }
};

int main() {
    return 0;
}
