/**
 * LeetCode Problem: Number of Islands
 * Pushed by LeetCommit
 * Date: 2026-08-08
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class DisjointSet{
public:
    vector<int> parent,rank;

    DisjointSet(int n){
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        rank.resize(n,0);
    }
    int findParent(int x){
        if(parent[x]==x) return x;
        return parent[x]=findParent(parent[x]);
    }
    void unionByRank(int u,int v){
        int rootU=findParent(u);
        int rootV=findParent(v);

        if(rootV==rootU) return;
        
        if(rank[rootU] < rank[rootV]){
            parent[rootU]=rootV;
        }else if(rank[rootV] < rank[rootU]){
            parent[rootV]=rootU;
        }else{
            parent[rootV]=rootU;
            rank[rootU]++;
        }

    }

};
class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};

    bool isValid(int x,int y,int n,int m) {
        return (x<n && x>=0 && y<m && y>=0);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        DisjointSet dsu(n*m);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]=='1'){
                    int node=i*m+j;

                    for(int k=0;k<4;k++){
                        int nr=i+dr[k];
                        int nc=j+dc[k];
                        int newNode=nr*m+nc;

                        if(isValid(nr,nc,n,m) && grid[nr][nc]=='1'){
                            dsu.unionByRank(node,newNode);
                        }
                    }
                }
            }
        }
        set<int> components;

        for (int i=0;i<n;i++) {
            for (int j=0; j<m;j++) {

                if (grid[i][j] == '1') {
                    int node = i * m + j;
                    components.insert(dsu.findParent(node));
                }
            }
        }

        return components.size();
    }
};

int main() {
    return 0;
}
