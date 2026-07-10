/**
 * LeetCode Problem: Number of Ways to Assign Edge Weights II
 * Pushed by LeetCommit
 * Date: 2026-07-10
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int M=1e9+7;
    int n;
    int col;

    unordered_map<int,vector<int>> adj;

    vector<vector<int>> up;
    vector<int> depth;
   

    void dfs(int node,int parent){
        int d=0;
        up[node][0]=parent;

        for(auto &it:adj[node]){
            if(it==parent) continue;
            
            depth[it]=depth[node]+1;

            dfs(it,node);
        }

    }

    void buildAncestorTable(){
        for(int j=1;j<col;j++){
            for(int node=0;node<n;node++){
                if(up[node][j-1]!=-1)
                up[node][j]=up[up[node][j-1]][j-1];
            }
        }
    }
    
    int findLCA(int u,int v){
        if(depth[u]<depth[v]) swap(u,v);

        int k=depth[u]-depth[v];

        for(int j=0;j<col;j++){
            if(k&(1<<j)){
                u=up[u][j];
            }
        }
        // both on same path
        if(u==v) return u;

        for(int j=col-1;j>=0;j--){
            if(up[u][j]==-1) continue;

            if(up[u][j]!=up[v][j]){
                u=up[u][j];
                v=up[v][j];

            }
        }

        return up[u][0];

    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        // no of nodes
        n=edges.size()+1;
        col=log2(n)+1;

        for(auto it:edges){

            int u=it[0]-1;//-1 for 0 based indexig
            int v=it[1]-1;

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        depth.resize(n,0);
        up.resize(n,vector<int>(col,-1));
        dfs(0,-1);

        buildAncestorTable();

        //precompute pow of 2
        vector<int>pow2(n+1);

        pow2[0]=1;
        for(int i=1;i<n+1;i++){
            pow2[i]=(pow2[i-1]*2LL)%M;
        }

        vector<int> ans;

        for(auto q:queries){
            int u=q[0]-1;
            int v=q[1]-1;
            int lca=findLCA(u,v);

            int d=depth[u]+depth[v]-2*depth[lca];

            if(d==0) ans.push_back(0);
            else ans.push_back(pow2[d-1]);

        }
        return ans;
    }
};

int main() {
    return 0;
}
