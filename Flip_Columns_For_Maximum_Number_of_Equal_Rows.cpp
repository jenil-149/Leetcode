/**
 * LeetCode Problem: Flip Columns For Maximum Number of Equal Rows
 * Pushed by LeetCommit
 * Date: 2026-08-06
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> mp;
        //we keep track of simialr patterns in each rows(1101 and 0010 are same pattern)
        for(auto x:matrix){
            string s="";
            for(auto y:x){
                if(y==x[0]) s+="1";
                else s+="0";
            }
            mp[s]++;
        }

        int ans=0;
        for(auto &[s,val]:mp){
            ans=max(ans,val);
        }
        return ans;
    }
};

int main() {
    return 0;
}
