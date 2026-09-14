/**
 * LeetCode Problem: Rectangle Overlap
 * Pushed by LeetCommit
 * Date: 2026-09-14
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    bool isRectangleOverlap(auto& r1, auto& r2) {
        return r1[0] < r2[2] && r2[0] < r1[2] &&
               r1[1] < r2[3] && r2[1] < r1[3];
    }
};

int main() {
    return 0;
}
