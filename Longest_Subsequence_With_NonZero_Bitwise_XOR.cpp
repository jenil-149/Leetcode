/**
 * LeetCode Problem: Longest Subsequence With Non-Zero Bitwise XOR
 * Pushed by LeetCommit
 * Date: 2026-08-15
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        bool z=true;
        for(int n:nums){
            x^=n;
            if(n!=0) z=false;
        }
        if(z) return 0;
        if(x==0) return n-1;
        else return n; 

    }
};

int main() {
    return 0;
}
