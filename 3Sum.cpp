/**
 * LeetCode Problem: 3Sum
 * Pushed by LeetCommit
 * Date: 2026-07-09
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---

        int n=nums.size();
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){

            // fix one element && skip if the same comes again
            if(i>0 && nums[i]==nums[i-1]) continue;

            // use two pointers to find target sum
            int l=i+1;
            int r=n-1;

            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];

                if(sum==0) {
                    ans.push_back({nums[i],nums[l],nums[r]});

int main() {
    return 0;
}
