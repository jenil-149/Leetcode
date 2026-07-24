/**
 * LeetCode Problem: Split the Array
 * Pushed by LeetCommit
 * Date: 2026-07-24
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        vector<int> freq(101,0);
        
        for(int n:nums){
            freq[n]++;
        }
        for(int f:freq){
            if(f>2) return false;
        }
        return true;

    }
};

int main() {
    return 0;
}
