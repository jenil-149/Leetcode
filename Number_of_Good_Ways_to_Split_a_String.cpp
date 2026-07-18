/**
 * LeetCode Problem: Number of Good Ways to Split a String
 * Pushed by LeetCommit
 * Date: 2026-07-18
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int numSplits(string s) {
       unordered_map<char,int> mp1;
       unordered_map<char,int> mp2;
       int n=s.size();
       int ans=0;

       for(char c:s){
        mp1[c]++;
       }
      
       for(int i=0;i<n;i++){
        char c=s[i];

        mp2[c]++;
        mp1[c]--;

        if(mp1[c]==0) mp1.erase(c);

        if(mp1.size()==mp2.size()) ans++;
       }

       return ans;

    }
};

int main() {
    return 0;
}
