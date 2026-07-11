/**
 * LeetCode Problem: Count the Number of Complete Components
 * Pushed by LeetCommit
 * Date: 2026-07-11
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    void dfs(int node,vector<int> &vis,vector<int>adj[],int &no_nodes,int &degree){
        vis[node]=1;
        no_nodes++;
        degree+=adj[node].size();
        for(auto ngbr:adj[node]){
            if(!vis[ngbr]){
                dfs(ngbr,vis,adj,no_nodes,degree);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        int no_comp=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int no_nodes=0;
                int degree=0;
                dfs(i,vis,adj,no_nodes,degree);

                //complete component the no of edges should be equal to  n=nodes in that comp(n*(n-1))/2
                int ed=degree/2;
                if(ed==(no_nodes*(no_nodes-1))/2) no_comp++;

            }
        }
        return no_comp; 

    }
};

int main() {
    return 0;
}
