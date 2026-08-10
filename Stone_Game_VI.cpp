/**
 * LeetCode Problem: Stone Game VI
 * Pushed by LeetCommit
 * Date: 2026-08-10
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();

        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({
                aliceValues[i] + bobValues[i],
                i
            });
        }

        sort(v.rbegin(), v.rend());
        int score = 0;

        for (int turn = 0; turn < n; turn++) {
            int idx = v[turn].second;

            if (turn % 2 == 0)
                score += aliceValues[idx];
            else
                score -= bobValues[idx];
        }

        if (score > 0) return 1;
        if (score < 0) return -1;
        return 0;
    }
};

int main() {
    return 0;
}
