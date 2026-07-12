/**
 * LeetCode Problem: Word Break
 * Pushed by LeetCommit
 * Date: 2026-07-12
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<int> dp;
    unordered_set<string> dict;

    bool solve(int idx,string s){
        if(idx==s.size()) return true;
        if(dp[idx]!=-1) return dp[idx];

        string word="";
        for(int i=idx;i<s.size();i++){
            word+=s[i];

            if(dict.count(word))
            {
               if(solve(i+1,s)) return dp[idx]= true;
            }
        }
        return dp[idx]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {

        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        dp.resize(s.size(),-1);
        solve(0,s);
        return dp[0];

    }
};

int main() {
    return 0;
}
