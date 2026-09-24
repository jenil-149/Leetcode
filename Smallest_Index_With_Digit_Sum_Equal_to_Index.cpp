/**
 * LeetCode Problem: Smallest Index With Digit Sum Equal to Index
 * Pushed by LeetCommit
 * Date: 2026-09-24
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int findSum(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            if(findSum(nums[i])==i) return i;
        }

        return -1;
    }
};

int main() {
    return 0;
}
