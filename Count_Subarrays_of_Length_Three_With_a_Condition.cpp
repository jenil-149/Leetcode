/**
 * LeetCode Problem: Count Subarrays of Length Three With a Condition
 * Pushed by LeetCommit
 * Date: 2026-07-16
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size()-2;i++){
            if((2*(nums[i]+nums[i+2]))==nums[i+1]) ans++;
        }
        return ans;
    }
};

int main() {
    return 0;
}
