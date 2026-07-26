/**
 * LeetCode Problem: Maximum Product of Three Numbers
 * Pushed by LeetCommit
 * Date: 2026-07-26
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        int mx1,mx2,mx3,mn1,mn2;
        mx1=mx2=mx3=INT_MIN;
        mn1=mn2=INT_MAX;

        for(int i=0;i<n;i++){
            if(nums[i]>=mx1){
                mx3=mx2;
                mx2=mx1;
                mx1=nums[i];
            }else if(nums[i]>=mx2){
                mx3=mx2;
                mx2=nums[i];
            }else if(nums[i]>mx3){
                mx3=nums[i];                
            }

            if(nums[i]<=mn1){
                mn2=mn1;
                mn1=nums[i];
            }else if(nums[i]<mn2){
                mn2=nums[i];
            }
        }

        return max(mx1*mx2*mx3 ,mn1*mn2*mx1);
    }
};
// class Solution {
// public:
//     int maximumProduct(vector<int>& nums) {
//         int n=nums.size();
//         sort(begin(nums),end(nums));
//         int a1=nums[0]*nums[1]*nums[n-1];
//         int a2=nums[n-1]*nums[n-2]*nums[n-3];

//         return max(a1,a2);
//     }
// };

int main() {
    return 0;
}
