/**
 * LeetCode Problem: Reachable Nodes In Subdivided Graph
 * Pushed by LeetCommit
 * Date: 2026-09-07
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    typedef long long ll;
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<pair<ll,ll>> adj[n];

        for(auto e: edges){
            ll u=e[0];
            ll v=e[1];
            ll cnt=e[2];

            adj[u].push_back({v,cnt});
            adj[v].push_back({u,cnt});
        }

        vector<ll> dist(n,LLONG_MAX);
        dist[0]=0;

        priority_queue<pair<ll,ll>,
                        vector<pair<ll,ll>>,
                        greater<pair<ll,ll>>
                        > pq;
        pq.push({0,0});

        while(!pq.empty()){
            auto [d , node ]=pq.top();
            pq.pop();

            if(d>dist[node]) continue;

            for(auto [adjNode,cnt]:adj[node]){
                ll nd=d+cnt+1;

                if(nd<dist[adjNode]){
                    dist[adjNode]=nd;
                    pq.push({nd,adjNode});
                }
            }
        }

        int ans=0;

        for(auto it: dist){
            if(it<=maxMoves) ans++;
        }

        for(auto e: edges){
            ll u=e[0];
            ll v=e[1];
            ll cnt=e[2];

            ll a=0,b=0;
            if(dist[u]<maxMoves){
                a=min(cnt,maxMoves-dist[u]);
            }

            if(dist[v]<maxMoves){
                b=min(cnt,maxMoves-dist[v]);
            }

            int reachable=min(cnt,a+b);

            ans+=(int)reachable;
        }
        return ans;

    }
};

int main() {
    return 0;
}
