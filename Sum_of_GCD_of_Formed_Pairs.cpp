/**
 * LeetCode Problem: Sum of GCD of Formed Pairs
 * Pushed by LeetCommit
 * Date: 2026-07-16
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    typedef long long ll;
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
       
        vector<int> prefixGcd(n);
        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
            prefixGcd[i]=gcd(nums[i],maxi);
        }
        sort(prefixGcd.begin(),prefixGcd.end());

        ll sum=0;
        for(int i=0;i<n/2;i++){
            sum+=(1LL*gcd(prefixGcd[i],prefixGcd[n-1-i]));
        }

        return sum;      
    }
};

int main() {
    return 0;
}
