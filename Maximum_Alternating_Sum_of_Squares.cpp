/**
 * LeetCode Problem: Maximum Alternating Sum of Squares
 * Pushed by LeetCommit
 * Date: 2026-10-13
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0;i<n;i++) nums[i]*=nums[i];

        nth_element(nums.begin(),nums.begin()+n/2,nums.end());

        return -accumulate(nums.begin(),nums.begin()+n/2,0LL)
                +accumulate(nums.begin()+n/2,nums.end(),0LL);
    }
};

int main() {
    return 0;
}
