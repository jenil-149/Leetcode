/**
 * LeetCode Problem: Number of Pairs of Strings With Concatenation Equal to Target
 * Pushed by LeetCommit
 * Date: 2026-08-25
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int ans=0;
        int n=nums.size();
        unordered_map<string,int> mp;
        for(auto s:nums) mp[s]++;

        for(auto &n:nums){
            if(target.size()<=n.size()) continue;
            int size=n.size();

            if(target.substr(0,size)==n){
                string req=target.substr(size);

                ans+=mp[req];
                if(req==n) ans--;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
