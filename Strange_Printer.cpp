/**
 * LeetCode Problem: Strange Printer
 * Pushed by LeetCommit
 * Date: 2026-08-02
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int f(int l,int r,string & s){

        if(l==r) return 1;
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];

        int i=l+1;
        while(i<=r && s[i]==s[l]){
            i++;

            if(i==r+1) return 1;
        }
        int basic=1+f(i,r,s);
        int greedy=INT_MAX;

        for(int j=i;j<=r;j++){
            if(s[j]==s[l]){
                int ans=f(i,j-1,s)+f(j,r,s);
                greedy=min(ans,greedy);
            }
        }
        return  dp[l][r]=min(basic,greedy);
    }

    int strangePrinter(string s) {
        n=s.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        return f(0,n-1,s);
    }
};

int main() {
    return 0;
}
