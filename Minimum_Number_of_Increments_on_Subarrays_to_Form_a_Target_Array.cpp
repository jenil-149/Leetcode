/**
 * LeetCode Problem: Minimum Number of Increments on Subarrays to Form a Target Array
 * Pushed by LeetCommit
 * Date: 2026-08-19
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans=0;
        int prev=0;
        for(int n:target){
            if(n>prev)
                ans+=(n-prev);
            prev=n;
        }
        return ans;
    }
};

int main() {
    return 0;
}
