/**
 * LeetCode Problem: Minimum Size Subarray in Infinite Array
 * Pushed by LeetCommit
 * Date: 2026-08-25
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    typedef long long ll;
    int minSizeSubarray(vector<int>& nums, int t) {
        ll sum=accumulate(nums.begin(),nums.end(),0LL);

        int n=nums.size();
        int full=t/sum;
        int rem=t%sum;

        if(rem==0) return n*full;

        unordered_map<ll,int> mp;
        mp[0]=-1;
        ll currSum=0;

        int mn=INT_MAX;
        for(int i=0;i<2*n;i++){
            currSum+=nums[i%n];

            if(mp.find(currSum-rem)!=mp.end()){
                mn=min(mn,i-mp[currSum-rem]);
            }

            mp[currSum]=i;
        }

        return mn==INT_MAX?-1:full*n+mn;


    }
};

int main() {
    return 0;
}
