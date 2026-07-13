/**
 * LeetCode Problem: Making A Large Island
 * Pushed by LeetCommit
 * Date: 2026-07-13
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class DisjointSet{

public:
	vector<int> parent,rank,size;
	DisjointSet(int n){
		parent.resize(n+1);
		for(int i=0;i<=n;i++){
			parent[i]=i;
		}
		size.resize(n+1,1);
		rank.resize(n+1,0);
	}
	int findParent(int x){
		if(parent[x]==x) return x;
		return parent[x]=findParent(parent[x]);
	}
	void UnionBySize(int u,int v){
		int parent_u=findParent(u);
		int parent_v=findParent(v);
		if(parent_u==parent_v) return;
		if(size[parent_u]<size[parent_v]){
			parent[parent_u]=parent_v;
			size[parent_v]+=size[parent_u];
		}
		else{
			parent[parent_v]=parent_u;
			size[parent_u]+=size[parent_v];
		}
	}
};

class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
	    DisjointSet ds(n*n);


	    for(int i=0;i<n;i++){
		    for(int j=0;j<n;j++){
			    if(grid[i][j]==0) continue;
			        for(int d=0;d<4;d++){
				        int nr=i+dr[d];
				        int nc=j+dc[d];
				        if(nr<n && nr>=0 && nc<n && nc>=0
				        && grid[nr][nc]==1){
					    int node=i*n+j;
					    int adjNode=nr*n+nc;

					ds.UnionBySize(node,adjNode);
				}
			}
		}
	}
	int mx=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(grid[i][j]==1){
				continue;
			}
			set<int> comp;

			for(int d=0;d<4;d++){
				int nr=i+dr[d];
				int nc=j+dc[d];
				if(nr<n && nr>=0 && nc<n && nc>=0
				&& grid[nr][nc]==1){
					comp.insert(ds.findParent(nr*n+nc));
				}
			}
			int ans=1;
			for(auto it:comp){
				ans+=ds.size[it];
			}
			mx=max(mx,ans);
		}
	}
	for(int i=0;i<n*n;i++){
		mx=max(mx,ds.size[ds.findParent(i)]);
	}
	return mx;

    }
};

int main() {
    return 0;
}
