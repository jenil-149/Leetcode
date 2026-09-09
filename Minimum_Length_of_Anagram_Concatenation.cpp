/**
 * LeetCode Problem: Minimum Length of Anagram Concatenation
 * Pushed by LeetCommit
 * Date: 2026-09-09
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:

    bool isValid(string &s,int l,int n){
        vector<int> freq1(26,0);

        for(int i=0;i<l;i++) freq1[s[i]-'a']++;

        for(int start=l;start<n;start+=l){
            vector<int> curr(26,0);

            for(int i=0;i<l;i++){
                curr[s[start+i]-'a']++;
            }

            if(curr!=freq1) return false;
        }

        return true;
    }
    int minAnagramLength(string s) {
        int n=s.size();

        for(int l=1;l<n;l++){

            if(n%l!=0) continue;

            if(isValid(s,l,n)) return l;
        }

        return n;
    }
};

int main() {
    return 0;
}
