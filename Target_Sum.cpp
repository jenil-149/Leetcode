/**
 * LeetCode Problem: Target Sum
 * Pushed by LeetCommit
 * Date: 2026-07-27
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    
    int f(int idx,int k,vector<int> & nums,vector<vector<int>> &dp){
        if (idx == 0) {
            if (k == 0 && nums[0] == 0) return 2;
            if (k == 0 || k == nums[0]) return 1;
            return 0;
        }
        if(dp[idx][k]!=-1) return dp[idx][k];

        int notTake=f(idx-1,k,nums,dp);
        int take=0;
        if((k-nums[idx])>=0) take =f(idx-1,k-nums[idx],nums,dp);

        return  dp[idx][k]=take+notTake;

    }
    int findTargetSumWays(vector<int>& nums, int target) {

        int total=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();

        if (abs(target) > total) return 0;
        if((target+total)%2==1) return 0;
        int k=(target+total)/2;

        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

            // Base case
        if (nums[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;

        if (nums[0] != 0 && nums[0] <= k)  dp[0][nums[0]] = 1;


        for (int idx = 1; idx < n; idx++) {
            for (int sum = 0; sum <= k; sum++) {

                int notTake = dp[idx - 1][sum];
                int take = 0;
                if (nums[idx] <= sum)  take = dp[idx - 1][sum - nums[idx]];

                dp[idx][sum] = take + notTake;
            }
        }

        return dp[n-1][k];

    }
};


int main() {
    return 0;
}
