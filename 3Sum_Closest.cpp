/**
 * LeetCode Problem: 3Sum Closest
 * Pushed by LeetCommit
 * Date: 2026-07-09
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int n=nums.size();
        int ans=nums[0]+nums[1]+nums[2];

        for(int i=0;i<n-2;i++){
            // use two pointers to find target sum
            int l=i+1;
            int r=n-1;

            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];

                if(abs(sum-target)<abs(ans-target)) ans=sum;

                if(sum==target) {
                    return sum;
                }

                else if(sum<target) {
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
