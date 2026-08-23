/**
 * LeetCode Problem: Find All Numbers Disappeared in an Array II
 * Pushed by LeetCommit
 * Date: 2026-08-23
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        nums.push_back(lower-1);
        nums.push_back(upper+1);

        sort(nums.begin(),nums.end());

        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0,j=1;j<n;i++,j++){
            if(nums[i]<lower-1 || nums[j]>upper+1) continue;

            if(nums[i]+1>nums[j]-1) continue;
            ans.push_back({nums[i]+1,nums[j]-1});
        }

        return ans;
        
    }
};

int main() {
    return 0;
}
