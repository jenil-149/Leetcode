/**
 * LeetCode Problem: Number of Unique XOR Triplets II
 * Pushed by LeetCommit
 * Date: 2026-07-24
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int maxVal=(1<<11)+1;

        vector<bool> x1(maxVal,false);
        vector<bool> ans(maxVal,false);
       
        for(int i:nums){
            for(int j:nums){
                x1[i^j]=true;
            }
        }
        for(int i=0;i<n;i++){
            for(int x=0;x<maxVal;x++){

                if(x1[x]==true){
                ans[x^nums[i]]=true;
                }
            }
        }
        
        int val=0;
        for(int i=0;i<maxVal;i++){
            val+=ans[i];
        }

        return val;
    }
};

int main() {
    return 0;
}
