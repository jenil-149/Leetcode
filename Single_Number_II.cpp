/**
 * LeetCode Problem: Single Number II
 * Pushed by LeetCommit
 * Date: 2026-08-05
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ones = 0;
    int twos = 0;

    for (const int num : nums) {
      ones ^= (num & ~twos);
      twos ^= (num & ~ones);
    }

    return ones;
  }
};

int main() {
    return 0;
}
