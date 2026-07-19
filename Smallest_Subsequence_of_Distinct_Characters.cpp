/**
 * LeetCode Problem: Smallest Subsequence of Distinct Characters
 * Pushed by LeetCommit
 * Date: 2026-07-19
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        string ans="";

        vector<bool> taken(26,false);
        vector<int> lastIdx(26,-1);
        
        for(int i=0;i<n;i++){
            lastIdx[s[i]-'a']=i;
        }
        for(int i=0;i<n;i++){
            char c=s[i];
            int idx=c-'a';

            if(taken[idx]==true) continue;

            while( ans.size()>0 && ans.back()>c && lastIdx[ans.back()-'a'] > i ){
                taken[ans.back()-'a']=false;
                ans.pop_back();

            }
            ans.push_back(c);
            taken[idx]=true;
        }

        return ans;

    }
};

int main() {
    return 0;
}
