/**
 * LeetCode Problem: Best Time to Buy and Sell Stock II
 * Pushed by LeetCommit
 * Date: 2026-07-25
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int f(int idx,int canBuy,vector<int>& p){
        if(idx==n) return 0;
        if(dp[idx][canBuy]!=-1) return dp[idx][canBuy];

        if(canBuy){
            return dp[idx][canBuy] = max(-p[idx]+f(idx+1,0,p),
                                                f(idx+1,1,p)
                                        );
        }else{
            return dp[idx][canBuy] = max(+p[idx]+f(idx+1,1,p),
                                                f(idx+1,0,p)
                                        );
        }
    }

    int maxProfit(vector<int>& p) {
        n=p.size();
        dp.assign(n+1,vector<int>(2,0));

        for(int idx=n-1;idx>=0;idx--){
            for(int canBuy=0;canBuy<=1;canBuy++){

                if(canBuy){
                    dp[idx][canBuy] = max( -p[idx]+dp[idx+1][0] , dp[idx+1][1] );
                }else{
                    dp[idx][canBuy] = max( +p[idx]+dp[idx+1][1] , dp[idx+1][0]);
                }  
            } 
        }
        return dp[0][1];
    }
};

int main() {
    return 0;
}
