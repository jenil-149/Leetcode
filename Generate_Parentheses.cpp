/**
 * LeetCode Problem: Generate Parentheses
 * Pushed by LeetCommit
 * Date: 2026-07-10
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    void f(string s,vector<string> &ans,int open,int close){
        // base case if both iopen and close are 0 we get out desired string so we push in our ans
        if(open==0 && close==0) {
            ans.push_back(s);
        }
        // add open bracket and subtract open and now we can add close any time so increase close
        if(open>0) f(s+"(",ans,open-1,close+1);
        // if we close we subtract one from close and open remains as it is
        if(close>0) f(s+")",ans,open,close-1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        // we pass n open brackets and 0 close so we do not get close without any open 
        f("",ans,n,0);
        return ans;
    }
};

int main() {
    return 0;
}
