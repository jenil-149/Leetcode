/**
 * LeetCode Problem: Minimum Seconds to Equalize a Circular Array
 * Pushed by LeetCommit
 * Date: 2026-08-14
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto &[num,idxs]:mp){
            int mx=0;
            int s=idxs.size();
            if(s==1) mx=n/2;

            for(int i=0;i<s;i++)
            {
                mx=max(mx,(abs(idxs[(i+1)%s]-idxs[i]+n)%n)/2);
            }

            ans=min(ans,mx);
        }
        return ans;
    }
};

int main() {
    return 0;
}
