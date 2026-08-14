/**
 * LeetCode Problem: Maximum Length Substring With Two Occurrences
 * Pushed by LeetCommit
 * Date: 2026-08-14
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0;
        vector<int> mp(26,0);
        int ans=0;
        for(int r=0;r<s.size();r++){
            mp[s[r]-'a']++;

            while(mp[s[r]-'a']>2){
                mp[s[l]-'a']--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};

int main() {
    return 0;
}
