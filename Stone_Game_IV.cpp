/**
 * LeetCode Problem: Stone Game IV
 * Pushed by LeetCommit
 * Date: 2026-08-10
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    // vector<int> dp;
    // bool f(int x){
    //     if(x==0) return false;
    //     if(dp[x]!=-1) return dp[x];

    //     bool ans=false;
    //     for(int i=1;i*i<=x;i++){
    //         if(f(x-i*i)==false)
    //             return dp[x]=true;
    //     }
    //     return dp[x]=false;
    // }
    bool winnerSquareGame(int n) {

        vector<bool> dp(n+1,false);
        for(int x=1;x<=n;x++){
            for(int i=1;i*i<=x;i++){
                if(dp[x-i*i]==false)
                    dp[x]=true;
            }
        }

        return dp[n];
    }
};

int main() {
    return 0;
}
