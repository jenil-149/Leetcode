/**
 * LeetCode Problem: Maximum Strength of a Group
 * Pushed by LeetCommit
 * Date: 2026-10-04
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    long long f(int idx, vector<int>& nums, long long product, bool picked) {
        if (idx == nums.size()) {
            return picked ? product : LLONG_MIN;
        }

        long long take =f(idx + 1, nums, product * nums[idx], true);

        long long notTake = f(idx + 1, nums, product, picked);

        return max(take, notTake);
    }

    long long maxStrength(vector<int>& nums) {
        return f(0, nums, 1, false);
    }
};

int main() {
    return 0;
}
