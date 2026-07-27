/**
 * LeetCode Problem: Maximum Product of Two Elements in an Array
 * Pushed by LeetCommit
 * Date: 2026-07-27
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1,mx2;
        mx1=mx2=INT_MIN;
        int mn1,mn2;
        mn1=mn2=INT_MAX;

        for(int n:nums){
            if(n>=mx1){
                mx2=mx1;
                mx1=n;
            }else if(n>mx2){
                mx2=n;
            }

            if(n<=mn1){
                mn2=mn1;
                mn1=n;
            }else if(n<mn2){
                mn2=n;
            }
        }
        return max(((mn1-1)*(mn2-1)),((mx1-1)*(mx2-1)));

    }
};

int main() {
    return 0;
}
