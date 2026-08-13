/**
 * LeetCode Problem: Apply Operations on Array to Maximize Sum of Squares
 * Pushed by LeetCommit
 * Date: 2026-08-13
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    const int mod=1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> bitCount(32,0);

        for(int n:nums){
            for(int i=0;i<32;i++){

                if(n & (1<<i))  bitCount[i]++;

            }
        }
        vector<int> largest(k,0);
        //we change the pos of bits bcz on applyiing & and | we only transfer 1's we do not create/destroy them so we are just making use of them to make biggest num possible to max ans
        
        for(int i=31;i>=0;i--){
            int cnt=bitCount[i];

            for(int j=0;j<k && cnt>0 ;j++){
                largest[j] |=(1<<i);
                cnt--;
            }
        }

        long long ans=0;
        for(int n:largest){
            ans=(ans+(1LL*n*n)%mod)%mod;
        }
        return (int)ans;

    }
};

int main() {
    return 0;
}
