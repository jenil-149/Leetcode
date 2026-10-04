/**
 * LeetCode Problem: Valid Parenthesis String
 * Pushed by LeetCommit
 * Date: 2026-10-04
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int n;
    vector<vector<int>> dp;

    bool f(int idx,int sum,string & s){
        if(sum<0) return false;

        if(idx==n){
          return sum==0;
        }
        if(dp[idx][sum]!=-1) return dp[idx][sum];

        bool ans=false;

        if(s[idx]=='(') ans|=f(idx+1,sum+1,s);
        else if(s[idx]==')') ans|=f(idx+1,sum-1,s);
        
        else{
            ans|=f(idx+1,sum+1,s);
            ans|=f(idx+1,sum-1,s);
            ans|= f(idx + 1, sum, s);
        }

        return dp[idx][sum]=ans;
    }
    bool checkValidString(string s) {
        n=s.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        return f(0,0,s);
    }
};

int main() {
    return 0;
}
