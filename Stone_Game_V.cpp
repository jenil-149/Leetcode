/**
 * LeetCode Problem: Stone Game V
 * Pushed by LeetCommit
 * Date: 2026-08-17
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<vector<int>> dp;
    vector<int> prefix;
    int f(int l ,int r,vector<int> &nums){
        if(l==r) return 0;

        if(dp[l][r]!=-1) return dp[l][r];

        int sum=prefix[r+1]-prefix[l];
        int currSum=0;
        int ans=0;

        for(int i=l;i<r;i++){
            currSum += nums[i];
            if(currSum < sum-currSum){
                ans=max( ans, currSum + f(l,i,nums));
            }
            else if(currSum==sum-currSum){
                ans=max(ans,max(currSum + f(l,i,nums),
                                currSum + f(i+1,r,nums)
                                ));
            }
            else{
                ans=max(ans , sum-currSum + f(i+1,r,nums));
            }
        }
        return dp[l][r]=ans;
    }
    int stoneGameV(vector<int>& nums) {
        int n=nums.size();
        prefix.assign(n+1,0);
        dp.assign(n,vector<int>(n,-1));

        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }

        return f(0,n-1,nums);
    } 
};

int main() {
    return 0;
}
