/**
 * LeetCode Problem: Maximum Score of a Split
 * Pushed by LeetCommit
 * Date: 2026-07-18
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    typedef long long ll;

    long long maximumScore(vector<int>& nums) {
        int n = nums.size();

        vector<ll> prefix(n), suffix(n);

        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];

        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = min((ll)nums[i], suffix[i + 1]);

        ll ans = LLONG_MIN;
        for (int i = 0; i < n-1; i++)
            ans = max(ans, prefix[i] - suffix[i+1]);

        return ans;
    }
};

int main() {
    return 0;
}
