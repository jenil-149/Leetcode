/**
 * LeetCode Problem: Can I Win
 * Pushed by LeetCommit
 * Date: 2026-07-10
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:

    bool f(int mask,int sum,int m,int d,vector<int>& dp){

        if(dp[mask]!=-1) return dp[mask];

        for(int i=0;i<m;i++){
            if(mask&(1<<i)) continue;
            //if we win directly
            if(sum+i+1>=d) return dp[mask]= true;

            //if opponent looses by out ith move
            if(f((mask|(1<<i)),sum+i+1,m,d,dp)==false)
            return dp[mask]=true;

        }
        return dp[mask]=false;
        
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int m=maxChoosableInteger;
        int d=desiredTotal;

        if(d<=0) return true;

        if((m*(m+1))/2<d) return false;
        if((m*(m+1))/2==d) return (m%2==1);

        vector<int> dp(1<<m,-1);

        return f(0,0,m,d,dp);
    }
};

int main() {
    return 0;
}
