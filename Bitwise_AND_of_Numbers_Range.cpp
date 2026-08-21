/**
 * LeetCode Problem: Bitwise AND of Numbers Range
 * Pushed by LeetCommit
 * Date: 2026-08-21
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(left<right){
            right=right & right-1;// right-1 gives 1 less than right and we do this till we reach left 
        }

        return right;
    }
};

// class Solution {
// public:
//     int rangeBitwiseAnd(int left, int right) {
       
//         int l=left,r=right;
//         int lb=0;
//         int rb=0;
//         while(l){
//             lb++;
//             l=l>>1;
//         }
//         while(r){
//             rb++;
//             r=r>>1;
//         }
//         if(lb!=rb) return 0;
         
//         long long ans=left;
//         for(long long i=left;i<=right;i++) ans&=(i);

//         return ans;
//     }
// };


int main() {
    return 0;
}
