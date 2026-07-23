/**
 * LeetCode Problem: House Robber II
 * Pushed by LeetCommit
 * Date: 2026-07-23
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int rob1(vector<int>& nums, int l, int r) {
        int prev1 = 0, prev2 = 0;

        for (int i = l; i <= r; i++) {
            int take = nums[i] + prev2;
            int notTake = prev1;

            int curr = max(take, notTake);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)return nums[0];

        return max(rob1(nums, 0, n - 2), rob1(nums, 1, n - 1));
    }
};

int main() {
    return 0;
}
