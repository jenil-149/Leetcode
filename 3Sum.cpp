/**
 * LeetCode Problem: 3Sum
 * Pushed by LeetCommit
 * Date: 2026-07-09
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
// brutforce: 3 for loop i,j,k check if nums[i]+nums[j]+nums[k]==0 && i!=j!=k
// complexity will be O(n^3) not optimal acc to constraints

// another approach fix i and make target=0-nums[i] 
// use two sum (hash map approach) to fins other two
// o(n^2) still not optimal

//optimal using sorting and 3 pointers

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // sort so two pointers can be applied easily 
        sort(nums.begin(),nums.end());

        int n=nums.size();
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){

            // fix one element && skip if the same comes again
            if(i>0 && nums[i]==nums[i-1]) continue;

            // use two pointers to find target sum
            int l=i+1;
            int r=n-1;

            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];

                if(sum==0) {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;

                    //skip duplicates
                    while( l<r &&nums[l]==nums[l-1]) l++;
                    while( l<r &&nums[r]==nums[r+1]) r--;
                }

                else if(sum<0) {
                    l++;
                }
                else{
                    r--;
                }
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}
