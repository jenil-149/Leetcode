/**
 * LeetCode Problem: Distinct Subsequences
 * Pushed by LeetCommit
 * Date: 2026-09-06
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int dp[1001][1001];
    int f(int i, int j, string &s, string &t) {
        if (j < 0) return 1;
        if (i < 0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int notTake = f(i - 1, j, s, t);
        int take = 0;
        if (s[i] == t[j])   take = f(i - 1, j - 1, s, t);
        
        return dp[i][j]=take+notTake;
    }

    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        memset(dp,-1,sizeof(dp));
        f(n-1,m-1,s,t);
        return dp[n-1][m-1];
    }
};

int main() {
    return 0;
}
