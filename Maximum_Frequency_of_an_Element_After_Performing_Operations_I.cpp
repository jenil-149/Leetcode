/**
 * LeetCode Problem: Maximum Frequency of an Element After Performing Operations I
 * Pushed by LeetCommit
 * Date: 2026-07-22
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal=*max_element(nums.begin(),nums.end());

        vector<int> diff(maxVal+2,0);
        unordered_map<int,int> freq;

        for(int i=0;i<nums.size();i++){
            //store the freq of the elems that are already present
            freq[nums[i]]++;

            int l=max(nums[i]-k,0);
            int r=min(nums[i]+k,maxVal);

            diff[l]+=1;
            diff[r+1]-=1;

        }

        int result=1;

        for(int target=0;target<=maxVal;target++){
          
            diff[target]+= (target >0? diff[target-1]:0);

            //higest freq that can be acheived
            int targetFreq= freq[target];
            //req conversions ,subtract freq already present
            int reqConversion=diff[target]-targetFreq;

            //maxOperations that we can perform
            int maxOperations= min(reqConversion,numOperations);
            //store maxFreq achiveable
            result=max(result,targetFreq+maxOperations);

        }
        return result;
    }
};

int main() {
    return 0;
}
