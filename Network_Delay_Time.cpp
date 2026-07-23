/**
 * LeetCode Problem: Network Delay Time
 * Pushed by LeetCommit
 * Date: 2026-07-23
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int t=it[2];
            adj[u].push_back({t,v});
        }

        priority_queue< pair<int,int>,
                        vector<pair<int,int>>,
                        greater<pair<int,int>>
                        > pq;

        vector<int> time(n+1,1e9);
        time[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int t=it.first;

            for(auto ngbr:adj[node]){
                int T=ngbr.first;
                int adjNode=ngbr.second;

                if(time[adjNode]>t+T) {
                    time[adjNode]=t+T;
                    pq.push({t+T,adjNode});
                }        
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(time[i]>=1e9) return -1;
            ans=max(time[i],ans);
        }
        return ans;

    }
};

int main() {
    return 0;
}
