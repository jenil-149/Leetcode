/**
 * LeetCode Problem: Minimum Operations to Transform String
 * Pushed by LeetCommit
 * Date: 2026-09-18
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int minOperations(string s) {
        int idx=26;

        for(auto c: s){
            int temp=c-'a';
            if(temp==0) continue;
            idx=min(idx,temp);
        }

        return 26-idx;

    }
};


int main() {
    return 0;
}
