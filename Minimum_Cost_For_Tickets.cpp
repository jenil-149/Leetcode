/**
 * LeetCode Problem: Minimum Cost For Tickets
 * Pushed by LeetCommit
 * Date: 2026-09-05
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int n;
    vector<int> dp;

    int f(int idx, vector<int>& days, vector<int>& costs) {
        if (idx >= n) return 0;

        if (dp[idx] != -1) return dp[idx];

        int i = idx;

        while (i < n && days[i] < days[idx] + 1)
            i++;
        int oneDay = costs[0] + f(i, days, costs);

        // 7-day pass
        i = idx;
        while (i < n && days[i] < days[idx] + 7)
            i++;
        int sevenDay = costs[1] + f(i, days, costs);

        // 30-day pass
        i = idx;
        while (i < n && days[i] < days[idx] + 30)
            i++;
        int thirtyDay = costs[2] + f(i, days, costs);

        return dp[idx] = min({oneDay, sevenDay, thirtyDay});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        dp.assign(n, -1);

        return f(0, days, costs);
    }
};

int main() {
    return 0;
}
