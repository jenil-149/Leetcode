/**
 * LeetCode Problem: Minimum Adjacent Swaps to Partition Array
 * Pushed by LeetCommit
 * Date: 2026-07-18
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int p2=0;
        int p3=0;
        int ans=0;
        int mod=1e9+7;
        
        for(auto num:nums){
            if(num<a){
                ans=(ans+p2+p3)%mod;
            }
            else if(num>=a && num<=b){
                p2++;
                ans=(ans+p3)%mod;
            }
            else{
                p3++;
            }
        }


      
        return ans;
    }
};

int main() {
    return 0;
}
