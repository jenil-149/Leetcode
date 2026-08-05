/**
 * LeetCode Problem: Single Number III
 * Pushed by LeetCommit
 * Date: 2026-08-05
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr=0;
        for(int n:nums) xr^=n;
        //get the set rightmost bit
        int pos = 0;
        while (((xr >> pos) & 1) == 0)
            pos++;

        int a=0,b=0;
        for( int n:nums){
            if((n>>pos)&1){
                a^=n;
            }else{
                b^=n;
            }
        }
        return {a,b};
    }
};

int main() {
    return 0;
}
