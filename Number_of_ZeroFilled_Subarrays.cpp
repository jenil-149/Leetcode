/**
 * LeetCode Problem: Number of Zero-Filled Subarrays
 * Pushed by LeetCommit
 * Date: 2026-08-03
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    typedef long long ll;
    long long zeroFilledSubarray(vector<int>& nums) {
        ll ans=0;
        ll count=0;

        for(int num: nums){
            if(num == 0){
                count++;
                ans+=count;
            }
            else{
                count = 0;
            }
        }
        return ans;

    }
};

int main() {
    return 0;
}
