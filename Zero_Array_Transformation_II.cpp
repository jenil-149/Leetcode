/**
 * LeetCode Problem: Zero Array Transformation II
 * Pushed by LeetCommit
 * Date: 2026-07-21
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:

    bool checkDiffArray(vector<int>& nums,vector<vector<int>> &queries,int k){
        int n=nums.size();
        vector<int> diff(n,0);
      
        for(int i=0;i<=k;i++){
            int start=queries[i][0];
            int end=queries[i][1];
            int val=queries[i][2];

            diff[start]+=val;
            if(end+1<n)
                diff[end+1] -=val; 
  
        }
       int cummSum=0;
        for(int i=0;i<n;i++){
            cummSum+=diff[i];
            diff[i]=cummSum;

            if(nums[i]>diff[i]) return false;
        }

        return true;


    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();  
        int q=queries.size();

        // if all nums are already zeros no queries req
        auto lamda =[](int x){
            return x==0;
        };  
        if(all_of(nums.begin(),nums.end(),lamda)) return 0;
        int l=0,r=q-1;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;

            if(checkDiffArray(nums,queries,mid)==true){
                ans=mid+1;
                r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return ans;


    }
};

int main() {
    return 0;
}
