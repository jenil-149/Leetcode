/**
 * LeetCode Problem: Largest Sum of Averages
 * Pushed by LeetCommit
 * Date: 2026-07-19
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<double> prefix;
    vector<vector<double>> dp;
    int n;
    double f(int idx,int k,vector<int>& nums){
        if(k==1){
            return (prefix[n]-prefix[idx])/(n-idx);
        }

        if(dp[idx][k]!=-1) return dp[idx][k];

        double ans=0;
        for(int j=idx;j<=n-k;j++){
            double avg=(prefix[j+1]-prefix[idx])/(j-idx+1);

            ans=max(ans,avg+f(j+1,k-1,nums));
        }

         return dp[idx][k]=ans;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        n=nums.size();
        dp.assign(n,vector<double>(k+1,-1));
        prefix.assign(n+1,0);

        for(int i=0;i<n;i++){
            prefix[i+1]=nums[i]+prefix[i];
        }
        return f(0,k,nums);
    }
};

int main() {
    return 0;
}
