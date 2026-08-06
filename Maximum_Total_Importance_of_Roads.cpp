/**
 * LeetCode Problem: Maximum Total Importance of Roads
 * Pushed by LeetCommit
 * Date: 2026-08-06
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    typedef long long ll;

    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);

        for (auto &r : roads) {
            degree[r[0]]++;
            degree[r[1]]++;
        }

        sort(degree.begin(), degree.end());

        ll ans = 0;
        for (ll i = 1; i <= n; i++) {
            ans += i * degree[i - 1];
        }

        return ans;
    }
};

int main() {
    return 0;
}
