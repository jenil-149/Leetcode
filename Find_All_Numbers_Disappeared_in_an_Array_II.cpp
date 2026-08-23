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

        sort(nums.begin(),nums.end());
        int n=nums.size();
        int prev=lower-1;

        vector<vector<int>> ans;
        
        for(int n:nums){
            if(n<lower) continue;
            if(n>upper) break;

            if(n>prev+1){
                ans.push_back({prev+1,n-1});
            }

            prev=n;
        }
        if(prev<upper){
            ans.push_back({prev+1,upper});
        }
        return ans; 
    }
};

int main() {
    return 0;
}
