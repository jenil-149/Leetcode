/**
 * LeetCode Problem: Construct the Longest New String
 * Pushed by LeetCommit
 * Date: 2026-07-24
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int longestString(int x, int y, int z) {
        if(x==y) return 2*(x+y+z);

        int mxy=min(x,y);
        return 2*(2*mxy+1+z);
    }
};

int main() {
    return 0;
}
