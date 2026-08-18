/**
 * LeetCode Problem: Divisible Game
 * Pushed by LeetCommit
 * Date: 2026-08-18
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    const int  mod=1e9+7;

    void getPrimes(vector<int> & nums,set<int>& primes){
        for(int n:nums){
            for(int i=2;i*i<=n;i++){
                if(n%i==0){ 
                    primes.insert(i);
                    while(n%i==0) n/=i;
                }
            }
            if(n>1) primes.insert(n);
        }
    }
    int score(vector<int> &nums,int p){
        int currSum=0;
        int maxSum=INT_MIN;
        for(int n:nums){
            if(n%p==0) currSum+=n;
            else       currSum-=n;

            maxSum=max(maxSum,currSum);
            if(currSum<0) currSum=0;
        }
        return maxSum;
    }
    int divisibleGame(vector<int>& nums) {
        set<int> primes;
        getPrimes(nums,primes);

        if(primes.size()==0) primes.insert(2);

        int k;
        int maxScore=INT_MIN;
        for(auto p:primes){
            int currScore=score(nums,p);
            if(currScore>maxScore){
                maxScore=currScore;
                k=p;
            }
        }
        maxScore=(k*(maxScore*1LL)%mod)%mod;

        return (maxScore+mod)%mod;
    }
};

int main() {
    return 0;
}
