/**
 * LeetCode Problem: Removing Minimum Number of Magic Beans
 * Pushed by LeetCommit
 * Date: 2026-09-04
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());

        long long total = 0;
        for (long long x : beans)
            total += x;

        long long ans = LLONG_MAX;
        int n = beans.size();

        for (int i = 0; i < n; i++) {
            long long cost = total - 1LL * beans[i] * (n - i);
            ans = min(ans, cost);
        }

        return ans;
    }
};

int main() {
    return 0;
}
