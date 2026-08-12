/**
 * LeetCode Problem: Loud and Rich
 * Pushed by LeetCommit
 * Date: 2026-08-12
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();

        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);

        for(auto r : richer) {
            int a = r[0];
            int b = r[1];

            adj[a].push_back(b);
            indegree[b]++;
        }

        queue<int> q;

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            ans[i] = i;
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int ngbr : adj[node]) {

                if(quiet[ans[node]] < quiet[ans[ngbr]]) {
                    ans[ngbr] = ans[node];
                }

                indegree[ngbr]--;

                if(indegree[ngbr] == 0) {
                    q.push(ngbr);
                }
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}
