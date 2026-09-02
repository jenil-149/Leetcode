/**
 * LeetCode Problem: Number of Dice Rolls With Target Sum
 * Pushed by LeetCommit
 * Date: 2026-09-02
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int dp[31][31][1001];
    const int mod=1e9+7;
    int f(int n,int k,int t){
        
        if(n==0 && t==0) return 1;
        if(t<0 || n==0) return 0;
        if(dp[n][k][t]!=-1) return dp[n][k][t];

        long long ans=0;
        for(int i=1;i<=k;i++){
            ans=(ans+f(n-1,k,t-i)%mod);
        }
        return dp[n][k][t]=(int)(ans%mod);

    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        f(n,k,target);
        return dp[n][k][target];
    }
};

int main() {
    return 0;
}
