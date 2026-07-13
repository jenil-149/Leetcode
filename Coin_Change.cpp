/**
 * LeetCode Problem: Coin Change
 * Pushed by LeetCommit
 * Date: 2026-07-13
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    
    // int f(int idx,int target,vector<int> &coins){
    //     if(target==0  ) return 0;
    //     if(idx<0) return 1e9;
    //     if(dp[idx][target]!=-1) return dp[idx][target];

    //     int notTake=f(idx-1,target,coins);
    //     int take=1e9;
    //     if(coins[idx]<=target){
    //         take=1+f(idx,target-coins[idx],coins);
    //     }
    //     return dp[idx][target]= min(take,notTake);
    // }
    int coinChange(vector<int>& coins, int amount) {

        int n=coins.size();
        vector<int> prev(amount+1, 0);
        vector<int> curr(amount+1,0);
        for(int j=0;j<=amount;j++){
            if(j%coins[0]==0) {
                prev[j]=j/coins[0];
            }
            else prev[j]=1e9;
        }

        for(int idx=1;idx<n;idx++){
            
            for(int target=0;target<=amount;target++){
                int notTake=prev[target];
                int take=1e9;
                if(coins[idx]<=target)  take=1+curr[target-coins[idx]];

                curr[target]= min(take,notTake);
            }
            prev=curr;
        }
        return prev[amount]>=1e9?-1:prev[amount];
        
    }
};

int main() {
    return 0;
}
