/**
 * LeetCode Problem: Decode Ways
 * Pushed by LeetCommit
 * Date: 2026-07-22
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    // vector<int> dp;
    // // int f(int idx, string &s) {

    //     if (idx == s.size()) return 1;
    //     if (s[idx] == '0') return 0;

    //     if(dp[idx]!=-1) return dp[idx];


    //     int ways = f(idx + 1, s);

    //     if (idx + 1 < s.size()) {
    //         int num = stoi(s.substr(idx, 2));
    //         if (num >= 10 && num <= 26)
    //             ways += f(idx + 2, s);
    //     }

    //     return dp[idx]=ways;
    // }
    int numDecodings(string s) {
        int n=s.size();
        int next1=1;
        int next2=0;
       

        for(int i=n-1;i>=0;i--){

            int curr=0;

            if(s[i]!='0'){
                curr+=next1;
            }
            

            if(i+1<n){
                int num=(s[i] - '0') * 10 + (s[i + 1] - '0');
                if(num>=10 && num<=26){
                    curr+=next2;
                }
            }
            next2=next1;
            next1=curr;

        }
        return next1;
    }
};

int main() {
    return 0;
}
