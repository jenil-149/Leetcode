/**
 * LeetCode Problem: Best Time to Buy and Sell Stock with Transaction Fee
 * Pushed by LeetCommit
 * Date: 2026-08-03
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int n;

    // int f(int idx,vector<int>& p,int fee,int buy){
    //     if(idx==n) return 0;

    //     if(buy){
    //         return max( -p[idx]+f(idx+1,p,fee,0),
    //                     f(idx+1,p,fee,1)
    //                     );
    //     }
    //     else{
    //         return max( -fee+p[idx]+f(idx+1,p,fee,1),
    //                     f(idx+1,p,fee,0)
    //                     );
    //     }
    // 
    int maxProfit(vector<int>& prices, int fee) {

        n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for(int idx = n - 1; idx >= 0; idx--) {

            // Can buy
            dp[idx][1] = max(
                -prices[idx] + dp[idx + 1][0],
                dp[idx + 1][1]
            );

            // Can sell
            dp[idx][0] = max(
                prices[idx] - fee + dp[idx + 1][1],
                dp[idx + 1][0]
            );
        }

        return dp[0][1];
    }
};

int main() {
    return 0;
}
