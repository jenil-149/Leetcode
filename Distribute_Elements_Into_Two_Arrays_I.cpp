/**
 * LeetCode Problem: Distribute Elements Into Two Arrays I
 * Pushed by LeetCommit
 * Date: 2026-08-20
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();

        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        
        for(int i=2;i<n;i++){
            if(arr1.back()> arr2.back()){
                arr1.push_back(nums[i]);
            }else{
                arr2.push_back(nums[i]);
            }
        }

        for(int i=0;i<arr2.size();i++) 
            arr1.push_back(arr2[i]);

        return arr1;


    }
};

int main() {
    return 0;
}
