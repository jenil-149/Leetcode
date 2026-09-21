/**
 * LeetCode Problem: Find X Value of Array I
 * Pushed by LeetCommit
 * Date: 2026-09-21
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    typedef long long ll;
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();

        vector<ll> ans(k);
        vector<ll> prevRemCount(k,0);

        for(int i=0;i<n;i++){

            vector<ll> currRemCount(k,0);

            int currRem=nums[i]%k;
            currRemCount[currRem]++;

            for(int oldRem=0;oldRem<k;oldRem++){
                int newRem=(oldRem*currRem)%k;

                currRemCount[newRem]+=prevRemCount[oldRem];
            }
            prevRemCount=currRemCount;

            for(int r=0;r<k;r++){
                ans[r]+=prevRemCount[r];
            }

        }
        return ans;


    }
};


int main() {
    return 0;
}
