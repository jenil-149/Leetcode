/**
 * LeetCode Problem: Minimum Score After Removals on a Tree
 * Pushed by LeetCommit
 * Date: 2026-09-03
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<vector<int>> adj;
    vector<int> in, out, subtreeXor;

    int timer = 0;
    void dfs(int node, int parent, vector<int>& nums) {

        in[node] = timer++;

        subtreeXor[node] = nums[node];
        for (int child : adj[node]) {

            if (child == parent) continue;

            dfs(child, node, nums);
     
            subtreeXor[node] ^= subtreeXor[child];
        }
        out[node] = timer;
    }

    bool isAncestor(int u, int v) {
        return in[u] < in[v] && in[v] < out[u];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {

        int n = nums.size();
        adj.assign(n, {});

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        in.resize(n);
        out.resize(n);
        subtreeXor.resize(n);

        dfs(0, -1, nums);

        int total = subtreeXor[0];
        int answer = INT_MAX;

        // Choose two non-root nodes.
        // Their parent edges will be removed.
        for (int u = 1; u < n; u++) {

            for (int v = u + 1; v < n; v++) {

                int x1, x2, x3;

                if (isAncestor(u, v)) {

                    x1 = total ^ subtreeXor[u];
                    x2 = subtreeXor[u] ^ subtreeXor[v];
                    x3 = subtreeXor[v];
                }

                else if (isAncestor(v, u)) {

                    x1 = total ^ subtreeXor[v];
                    x2 = subtreeXor[v] ^ subtreeXor[u];
                    x3 = subtreeXor[u];
                }
                else {

                    x1 = total ^ subtreeXor[u] ^ subtreeXor[v];
                    x2 = subtreeXor[u];
                    x3 = subtreeXor[v];
                }

                int score =
                    max({x1, x2, x3}) -
                    min({x1, x2, x3});

                answer = min(answer, score);
            }
        }

        return answer;
    }
};

int main() {
    return 0;
}
