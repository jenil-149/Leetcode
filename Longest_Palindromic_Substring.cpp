/**
 * LeetCode Problem: Longest Palindromic Substring
 * Pushed by LeetCommit
 * Date: 2026-07-09
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    void expand(int l,int r ,int& maxLen,int n,string &s,int &start){
        while(l>=0 &&r<n && s[l]==s[r]){
           if(maxLen<r-l+1)
            {   
                maxLen=r-l+1;
                start=l;
            }
            l--;
            r++;
        }  
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0;
        int maxLen=1;

int main() {
    return 0;
}
