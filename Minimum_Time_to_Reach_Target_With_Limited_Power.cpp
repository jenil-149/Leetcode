/**
 * LeetCode Problem: Minimum Time to Reach Target With Limited Power
 * Pushed by LeetCommit
 * Date: 2026-08-06
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---

class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges,
                                      int power, vector<int>& cost,
                                      int source, int target) {

        vector<pair<int,int>> adj[n];
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]}); 
        }

        const long long INF = 1e18;

        // dist[node][remainingPower] = minimum time
        vector<vector<long long>> dist(n, vector<long long>(power + 1, INF));

        // {time, node, remainingPower}
        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > pq;

        dist[source][power] = 0;
        pq.push({0, source, power});

        while (!pq.empty()) {
            auto [time, node, remPower] = pq.top();
            pq.pop();

            if (time != dist[node][remPower])
                continue;

            if (remPower < cost[node])
                continue;

            int newPower = remPower - cost[node];

            for (auto &[nextNode, wt] : adj[node]) {
                long long newTime = time + wt;

                if (newTime < dist[nextNode][newPower]) {
                    dist[nextNode][newPower] = newTime;
                    pq.push({newTime, nextNode, newPower});
                }
            }
        }

        long long bestTime = INF;
        int bestPower = -1;

        for (int p = 0; p <= power; p++) {
            if (dist[target][p] < bestTime) {
                bestTime = dist[target][p];
                bestPower = p;
            } else if (dist[target][p] == bestTime) {
                bestPower = max(bestPower, p);
            }
        }

        if (bestTime == INF)
            return {-1, -1};

        return {bestTime, bestPower};
    }
};

int main() {
    return 0;
}
