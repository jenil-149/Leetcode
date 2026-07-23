/**
 * LeetCode Problem: Maximum Prime Difference
 * Pushed by LeetCommit
 * Date: 2026-07-23
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        int left = 0;
        while (!isPrime(nums[left])) left++;

        int right = nums.size() - 1;
        while (!isPrime(nums[right])) right--;

        return right - left;
    }
};

int main() {
    return 0;
}
