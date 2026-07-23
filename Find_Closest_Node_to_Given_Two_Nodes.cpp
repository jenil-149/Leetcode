/**
 * LeetCode Problem: Find Closest Node to Given Two Nodes
 * Pushed by LeetCommit
 * Date: 2026-07-23
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    void dfs(int node,vector<int> &dist,vector<int> &vis,vector<int>& edges){
        vis[node]=1;
        int v=edges[node];

        if(v!=-1 && vis[v]!=1){
            vis[v]=1;
            dist[v]=dist[node]+1;
            dfs(v,dist,vis,edges);
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> dist1(n,1e9),dist2(n,1e9);
        dist1[node1]=0;
        dist2[node2]=0;

        vector<int> vis1(n,0),vis2(n,0);

        dfs(node1,dist1,vis1,edges);
        dfs(node2,dist2,vis2,edges);

        int minDistNode=-1;
        int minDistTillNow=INT_MAX;

        for(int i=0;i<n;i++){
            int maxD=max(dist1[i],dist2[i]);

            if(maxD>=1e9) continue;
            if(minDistTillNow>maxD){
                minDistTillNow=maxD;
                minDistNode=i;
            }
        }
        return minDistNode;
    }
};

int main() {
    return 0;
}
