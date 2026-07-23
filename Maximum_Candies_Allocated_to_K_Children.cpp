/**
 * LeetCode Problem: Maximum Candies Allocated to K Children
 * Pushed by LeetCommit
 * Date: 2026-07-23
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    bool check(vector<int>& candies,int k,long long mid){
        long long curr=0;
        for(auto it:candies){
            curr+=(it/mid);
        }
        if(curr>=k)return true;
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long left=1;
        long long right=accumulate(candies.begin(),candies.end(),0LL)/k;
        long long ans=0;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(check(candies,k,mid)){
                ans=mid;
                left=mid+1;
            }
            else right=mid-1;
        }
        return ans;
    }
};

int main() {
    return 0;
}
