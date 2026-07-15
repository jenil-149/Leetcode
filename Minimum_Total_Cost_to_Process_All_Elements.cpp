/**
 * LeetCode Problem: Minimum Total Cost to Process All Elements
 * Pushed by LeetCommit
 * Date: 2026-07-15
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int mod=1e9+7;
    int minimumCost(vector<int>& nums, int k) {

        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        long long  op=(sum-1)/k;
        op=op%mod;
        return ((op*(op+1))/2)%mod;

    }
};

// class Solution {
// public:
//     int mod=1e9+7;
//     int minimumCost(vector<int>& nums, int k) {
//         long long op=0;
//         int r=k;
//         for(int i=0;i<nums.size();i++){
//             if(r-nums[i]>=0){
//                 r=r-nums[i];
//             }
//             else{
//                 int temp=nums[i]-r;
//                 int add=(temp+k-1)/k;
//                 r=r+add*k-nums[i];
//                 op=(op+add)%mod;
//             }
//         }
//         return ((op*(op+1))/2)%mod;
//     }
// };

int main() {
    return 0;
}
