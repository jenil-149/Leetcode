/**
 * LeetCode Problem: Number of Unique XOR Triplets I
 * Pushed by LeetCommit
 * Date: 2026-07-23
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int i=1;

        while(i<=n){
           i=(i<<1);
        }
    
        if(n<=2) return n;
        else return (i);
    }
};

int main() {
    return 0;
}
