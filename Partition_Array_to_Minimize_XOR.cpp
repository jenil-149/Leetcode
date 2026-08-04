/**
 * LeetCode Problem: Partition Array to Minimize XOR
 * Pushed by LeetCommit
 * Date: 2026-08-04
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int f(int idx,int k,vector<int> &nums){
        
        if(k==1) {
            int xr=0;
            for(int i=idx;i<n;i++) 
                xr^=nums[i];
            return xr;
        }
        if(dp[idx][k]!=-1) return dp[idx][k];

        int ans=INT_MAX;
        int xr=0;

        for(int j=idx;j<=n-k;j++){
            
            xr^=nums[j];
            ans=min(ans,max(xr,f(j+1,k-1,nums)));
        }
        return dp[idx][k]=ans;
    }
    
    int minXor(vector<int>& nums, int k) {
        n=nums.size();
        dp.assign(n,vector<int>(k+1,-1));
       
        return f(0,k,nums);
    }
};

int main() {
    return 0;
}
