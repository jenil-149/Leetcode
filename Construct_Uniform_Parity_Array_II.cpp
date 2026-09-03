/**
 * LeetCode Problem: Construct Uniform Parity Array II
 * Pushed by LeetCommit
 * Date: 2026-09-03
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn=*min_element(nums1.begin(),nums1.end());
        if(mn%2==1) return true;
        
        for(int n:nums1){
            if(n%2==1) return false;
        }

        return true;

    }
};

int main() {
    return 0;
}
