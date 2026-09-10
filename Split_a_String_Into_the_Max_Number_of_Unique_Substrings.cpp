/**
 * LeetCode Problem: Split a String Into the Max Number of Unique Substrings
 * Pushed by LeetCommit
 * Date: 2026-09-10
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int n;
    int f(int idx,string &s,unordered_set<string> &st){
        if(idx==n) return st.size();

        int ans=0;
        for(int k=idx+1;k<=n;k++){

            string temp=s.substr(idx,k-idx);
           
            if(st.count(temp)) continue;
            
            st.insert(temp);
            ans=max(ans,f(k,s,st));

            st.erase(temp);
        }

        return ans;
    }
    int maxUniqueSplit(string s) {
        n=s.size();
        unordered_set<string> st;
        return f(0,s,st);  
    }
};

int main() {
    return 0;
}
