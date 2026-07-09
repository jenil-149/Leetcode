/**
 * LeetCode Problem: Find First and Last Position of Element in Sorted Array
 * Pushed by LeetCommit
 * Date: 2026-07-09
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int up=upper_bound(nums.begin(),nums.end(),target)-nums.begin();

        if(lb==nums.size()||nums[lb]!=target) return {-1,-1};
        else return {lb,up-1};
    }
};

int main() {
    return 0;
}
