/**
 * LeetCode Problem: Find the Substring With Maximum Cost
 * Pushed by LeetCommit
 * Date: 2026-08-26
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int maximumCostSubstring(string s, string c, vector<int>& vals) {
        vector<int> cost(26);
        for(int i=0;i<26;i++) cost[i]=i+1;

        for(int i=0;i<c.size();i++) cost[c[i]-'a']=vals[i];

        int mx=0;
        int currCost=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            currCost+=cost[s[i]-'a'];
            
            if(currCost<0) {
                currCost=0;
            }
            mx=max(mx,currCost);
        }

        return mx;
    }
};

int main() {
    return 0;
}
