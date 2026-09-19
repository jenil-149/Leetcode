/**
 * LeetCode Problem: Circle and Rectangle Overlapping
 * Pushed by LeetCommit
 * Date: 2026-09-19
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    bool checkOverlap(int r, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {
        
        int xi = max(x1, min(xCenter, x2));
        int yi = max(y1, min(yCenter, y2));

        int dx = xi - xCenter;
        int dy = yi - yCenter;

        return dx * dx + dy * dy <= r * r;
    }
};

int main() {
    return 0;
}
