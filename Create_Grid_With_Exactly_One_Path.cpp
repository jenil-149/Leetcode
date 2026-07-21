/**
 * LeetCode Problem: Create Grid With Exactly One Path
 * Pushed by LeetCommit
 * Date: 2026-07-21
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m,string(n, '#'));
        for(int r = 0; r < m; r++) grid[r][0] = '.';
        for(int c = 1; c < n; c++) grid[m-1][c] = '.';
        return grid;
    }

};

int main() {
    return 0;
}
