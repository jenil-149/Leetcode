/**
 * LeetCode Problem: Maximum Number of Non-overlapping Palindrome Substrings
 * Pushed by LeetCommit
 * Date: 2026-09-15
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public: 
    int n;
    vector<vector<int>> dp;
    bool isPalidrome(int i,int j,string &s){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i,int j,int k,string & s){
        if(i>=n || j>=n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(isPalidrome(i,j,s)){
            int take=1+f(j+1,j+k,k,s);
            int grow=f(i,j+1,k,s);
            int slide=f(i+1,j+1,k,s);

            return dp[i][j]=max({take,grow,slide});
        }else{
            int grow=f(i,j+1,k,s);
            int slide=f(i+1,j+1,k,s);

            return dp[i][j]= max(grow,slide);
        }
    }
    int maxPalindromes(string s, int k) {
        n=s.size();

        if(k==1) return n;
        dp.assign(n+1,vector<int>(n+1,0));

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(isPalidrome(i,j,s)){
                    int take=1+(j+k<=n? dp[j+1][j+k]:0) ;
                    int grow=dp[i][j+1];
                    int slide=dp[i+1][j+1];

                    dp[i][j]=max({take,grow,slide});

                }else{
                    int grow=dp[i][j+1];
                    int slide=dp[i+1][j+1];

                    dp[i][j]= max(grow,slide);
                }
            }
        }
        return dp[0][k-1];
    }
};

int main() {
    return 0;
}
