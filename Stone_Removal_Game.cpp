/**
 * LeetCode Problem: Stone Removal Game
 * Pushed by LeetCommit
 * Date: 2026-08-29
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    bool canAliceWin(int n) {
        for(int i=10;i>=1;i--){
            if(i>n) {
                return i%2==0?0:1;
            }
            n-=i;
        }
        return false;
    }
};

int main() {
    return 0;
}
