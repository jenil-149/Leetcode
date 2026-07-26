/**
 * LeetCode Problem: Count Subarrays With Score Less Than K
 * Pushed by LeetCommit
 * Date: 2026-07-26
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    typedef long long ll;
    long long countSubarrays(vector<int>& nums, long long k) {
        ll ans=0;
        ll sum=0;
        int l=0;
        
        for(int r=0;r<nums.size();r++){
            sum += nums[r];

            while (sum * (r - l + 1LL) >= k) {
                sum -= nums[l];
                l++;
            }

            ans += (r - l + 1);
        }
        return ans;
    }
};

int main() {
    return 0;
}
