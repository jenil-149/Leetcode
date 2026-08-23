/**
 * LeetCode Problem: Longest Subarray With at Most K Distinct Prime Factors
 * Pushed by LeetCommit
 * Date: 2026-08-23
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    void findPrimes(int n,vector<vector<int>> &primes){
        vector<int> temp;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) temp.push_back(i);
            while(n%i==0) n/=i;
        }
        if(n!=1) temp.push_back(n);
        primes.push_back(temp);

    }
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> primes;
        for(int i=0;i<n;i++){
            findPrimes(nums[i],primes);
        }
        int l=0;
        int ans=0;
        unordered_map<int,int> mp;

        for(int r=0;r<n;r++){

            for(int p:primes[r]){
                mp[p]++;
            }

            while(mp.size()>k){
                for(int p:primes[l]) {
                    mp[p]--;
                    if(mp[p]==0) mp.erase(p);
                }
                l++;
            }
            ans=max(ans,r-l+1);
        }

        return ans;
        

    }
};

int main() {
    return 0;
}
