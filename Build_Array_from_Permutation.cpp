/**
 * LeetCode Problem: Build Array from Permutation
 * Pushed by LeetCommit
 * Date: 2026-08-05
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) 
            nums[i] += (1001* (nums[nums[i]] % 1001));
        
        for (int i = 0; i < nums.size(); i++) 
            nums[i] /= 1001;
        
        return nums;
    }
};

int main() {
    return 0;
}
