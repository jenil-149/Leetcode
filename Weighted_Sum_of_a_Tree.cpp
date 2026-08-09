/**
 * LeetCode Problem: Weighted Sum of a Tree
 * Pushed by LeetCommit
 * Date: 2026-08-09
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    using ll = long long;

    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();

        vector<vector<int>> children(n);
        //adjList
        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        vector<int> depth(n);
        queue<int> q;

        depth[0] = 1;
        q.push(0);

        int h = 1;
        //BFS
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            h = max(h, depth[u]);

            for (int v : children[u]) {
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }

        ll ans = 0;

        for (int i = 0; i < n; i++) {
            ans += 1LL * nums[i] * (h - depth[i] + 1);
        }

        return ans;
    }
};


int main() {
    return 0;
}
