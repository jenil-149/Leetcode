/**
 * LeetCode Problem: Divide Intervals Into Minimum Number of Groups
 * Pushed by LeetCommit
 * Date: 2026-08-26
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        vector<int> d(1e6+2,0);

        for(auto i: intervals){
            int l=i[0];
            int r=i[1];

            d[l]+=1;
            d[r+1]-=1;
        }
        int ans=1;

        for(int i=1;i<d.size();i++){
            d[i]+=d[i-1];
            ans=max(ans,d[i]);
        }

        return ans;


    }
};

int main() {
    return 0;
}
