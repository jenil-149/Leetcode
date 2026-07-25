/**
 * LeetCode Problem: Maximum Sum of Three Numbers Divisible by Three
 * Pushed by LeetCommit
 * Date: 2026-07-25
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());

        vector<int> arr[3];

        for (int x : nums) {
            arr[x % 3].push_back(x);
        }

        int ans = 0;

        // (0,0,0)
        if (arr[0].size() >= 3)
            ans = max(ans, arr[0][0] + arr[0][1] + arr[0][2]);

        // (1,1,1)
        if (arr[1].size() >= 3)
            ans = max(ans, arr[1][0] + arr[1][1] + arr[1][2]);

        // (2,2,2)
        if (arr[2].size() >= 3)
            ans = max(ans, arr[2][0] + arr[2][1] + arr[2][2]);

        // (0,1,2)
        if (!arr[0].empty() && !arr[1].empty() && !arr[2].empty())
            ans = max(ans, arr[0][0] + arr[1][0] + arr[2][0]);

        return ans;
    }
};

int main() {
    return 0;
}
