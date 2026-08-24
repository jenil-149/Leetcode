/**
 * LeetCode Problem: Stone Game VIII
 * Pushed by LeetCommit
 * Date: 2026-08-24
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int n;
    vector<int> dp;
    vector<int> prefix;
    int f(int idx){
        if(idx==n-1) return prefix[n-1];

        if(dp[idx]!=INT_MIN) return dp[idx];

        int take=prefix[idx]-f(idx+1);
        int notTake=f(idx+1);

        return dp[idx]=max(take,notTake);
        
    }
    int stoneGameVIII(vector<int>& stones) {
        n=stones.size();
        prefix.resize(n);
        dp.assign(n,0);

        prefix[0]=stones[0];

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+stones[i];
        }
        dp[n-1]=prefix[n-1];

        for(int i=n-2;i>=1;i--){

            int take=prefix[i]-dp[i+1];
            int notTake=dp[i+1];

            dp[i]=max(take,notTake);
        }

        return dp[1];

    }
};

int main() {
    return 0;
}
