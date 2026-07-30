/**
 * LeetCode Problem: Minimum Cost to Reach Destination in Time
 * Pushed by LeetCommit
 * Date: 2026-07-30
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fees) {
        int n = fees.size();

        vector<pair<int,int>> adj[n];
        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        // min-heap: {cost, node, time}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<int> minTime(n, INT_MAX);

        pq.push({fees[0], 0, 0}); // cost, node, time
        minTime[0] = 0;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int cost = curr[0];
            int node = curr[1];
            int time = curr[2];
         

            if(node == n-1) return cost;

            for(auto &[next, t] : adj[node]){
                int newTime = time + t;
                int newCost = cost + fees[next];

                if(newTime <= maxTime && newTime < minTime[next]){
                    minTime[next] = newTime;
                    pq.push({newCost, next, newTime});
                }
            }
        }

        return -1;
    }
};

int main() {
    return 0;
}
