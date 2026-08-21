/**
 * LeetCode Problem: Smallest Missing Multiple of K
 * Pushed by LeetCommit
 * Date: 2026-08-21
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> n(101,0);
        for(int num:nums){
            n[num]++;
        }
        int i=k;
        for(i;i<=100;i+=k){
            if(n[i]==0) return i;
        }
        return i;
    }
};

int main() {
    return 0;
}
