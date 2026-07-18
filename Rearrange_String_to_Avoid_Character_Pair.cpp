/**
 * LeetCode Problem: Rearrange String to Avoid Character Pair
 * Pushed by LeetCommit
 * Date: 2026-07-18
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
// move zeros to end approach
class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int n=s.size();
        int l=0;
        for(int r=0;r<n;r++){
            if(s[r]!=x){
                swap(s[l],s[r]);
                l++;
            }
        }
        return s;
    }
};

int main() {
    return 0;
}
