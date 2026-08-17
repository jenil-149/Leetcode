/**
 * LeetCode Problem: Bulls and Cows
 * Pushed by LeetCommit
 * Date: 2026-08-17
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    string getHint(string s, string g) {
        int n=s.size();
        int x=0,y=0;
        unordered_map<char,int> mp;
        for(char c: s) mp[c]++;

        for(int i=0;i<n;i++){
            if(s[i]==g[i]) {
                x++;
                mp[s[i]]--;
                if(mp[g[i]]==0) mp.erase(g[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]==g[i]) continue;
            if(mp.find(g[i])!=mp.end()){
                y++;
                mp[g[i]]--;
                if(mp[g[i]]==0) mp.erase(g[i]);
            }
        }
        string ans=to_string(x)+"A"+to_string(y)+"B";
        return ans;
    }
};

int main() {
    return 0;
}
