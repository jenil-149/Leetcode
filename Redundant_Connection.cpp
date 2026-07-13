/**
 * LeetCode Problem: Redundant Connection
 * Pushed by LeetCommit
 * Date: 2026-07-13
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class DisjointSet{
public:
    vector<int> parent, size;

    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int findParent(int x){
        if(parent[x]==x) return x;
        return parent[x]=findParent(parent[x]);
    }

    void unionBySize(int u,int v){

        int pu=findParent(u);
        int pv=findParent(v);

        if(pu==pv) return;

        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSet dsu(n);
      
        for(auto it:edges){
            if(dsu.findParent(it[0])==dsu.findParent(it[1])) return it;
            else{
                dsu.unionBySize(dsu.findParent(it[0]),dsu.findParent(it[1]));
            }
        }
        
     return {-1,-1};

    }
};

int main() {
    return 0;
}
