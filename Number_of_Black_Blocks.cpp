/**
 * LeetCode Problem: Number of Black Blocks
 * Pushed by LeetCommit
 * Date: 2026-07-15
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
       map<pair<int,int>, int> mp;
       vector<long long> ans(5,0);

       for(auto c:coordinates){
        
        int x=c[0];
        int y=c[1];
        // one black box can be part of atmost 4 left corners of 2*2 
        //top left
        if(x>0 && y>0) mp[{x-1,y-1}]++;
        //upp
        if(x>0 && y<n-1)  mp[{x-1,y}]++;
        //left
        if(x<m-1 && y>0) mp[{x,y-1}]++;
        //own
        if(x<m-1 && y<n-1) mp[{x,y}]++;
        }
        
        for(auto it:mp){
            ans[it.second]++;
        }
        long long total=1LL*(m-1)*(n-1);
        ans[0]=total-(ans[1]+ans[2]+ans[3]+ans[4]);

        return ans;
    }
};

int main() {
    return 0;
}
