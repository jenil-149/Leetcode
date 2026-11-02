/**
 * LeetCode Problem: Minimum Moves to Equal Array Elements II
 * Pushed by LeetCommit
 * Date: 2026-11-02
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long minMoves=0;
        int n=nums.size();

        sort(nums.begin(),nums.end());
        int median=nums[n/2];

        for (int x : nums) {
            minMoves += abs(1LL * x - median);
        }
        return minMoves;
    }
};

int main() {
    return 0;
}
