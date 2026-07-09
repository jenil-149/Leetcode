/**
 * LeetCode Problem: Longest Palindromic Substring
 * Pushed by LeetCommit
 * Date: 2026-07-09
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    void expand(int l,int r ,int& maxLen,int n,string &s,int &start){
        while(l>=0 &&r<n && s[l]==s[r]){
           if(maxLen<r-l+1)
            {   
                maxLen=r-l+1;
                start=l;
            }
            l--;
            r++;
        }  
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0;
        int maxLen=1;
        for(int i=0;i<n;i++){
            // if palidrome is odd length we expand from the same char
            expand(i,i,maxLen,n,s,start);
            //if it is of even lenght we expand with current and next char
            expand(i,i+1,maxLen,n,s,start);
        }
        //we get substring using the start and maxLen
        return s.substr(start,maxLen);
    }
};

int main() {
    return 0;
}
