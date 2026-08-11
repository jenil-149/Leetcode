/**
 * LeetCode Problem: Tuple with Same Product
 * Pushed by LeetCommit
 * Date: 2026-08-11
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
   
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        int ans=0;
        for(auto &[num,freq]:mp){
            if(freq==1) continue;

            ans+=(freq*(freq-1))/2*8;
        }
        return ans;
    }
};

int main() {
    return 0;
}
