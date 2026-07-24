/**
 * LeetCode Problem: Maximum Star Sum of a Graph
 * Pushed by LeetCommit
 * Date: 2026-07-24
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {

        int n = vals.size();
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
           int u=e[0];
           int v=e[1];

           adj[u].push_back(vals[v]);
           adj[v].push_back(vals[u]);
        }

        for (auto &v : adj)
            sort(v.begin(), v.end(), greater<int>());

        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            int sum = vals[i];

            for (int j = 0; j < min((int)adj[i].size(), k); j++) {
                if (adj[i][j] <= 0)
                    break;
                sum += adj[i][j];
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};

int main() {
    return 0;
}
