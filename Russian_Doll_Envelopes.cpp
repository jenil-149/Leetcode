/**
 * LeetCode Problem: Russian Doll Envelopes
 * Pushed by LeetCommit
 * Date: 2026-09-24
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();

        sort(env.begin(), env.end(), [](auto &a, auto &b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<int> dp;

        for (auto &e : env) {
            int h = e[1];

            auto it = lower_bound(dp.begin(), dp.end(), h);

            if (it == dp.end())
                dp.push_back(h);
            else
                *it = h;
        }

        return dp.size();
    }
};

int main() {
    return 0;
}
