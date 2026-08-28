/**
 * LeetCode Problem: Divide Array Into Arrays With Max Difference
 * Pushed by LeetCommit
 * Date: 2026-08-28
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<=n-3;i+=3){
            ans.push_back({nums[i],nums[i+1],nums[i+2]});

            if(nums[i+2]-nums[i+1]>k || nums[i+1]-nums[i]>k || nums[i+2]-nums[i]>k) return {};
        }
        return ans;
    }
};

int main() {
    return 0;
}
