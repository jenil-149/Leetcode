/**
 * LeetCode Problem: Prison Cells After N Days
 * Pushed by LeetCommit
 * Date: 2026-07-24
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {

        unordered_map<int, int> seen; // state -> day

        int day = 0;

        while (day < n) {

            // Encode current state
            int state = 0;
            for (int x : cells)
                state = (state << 1) | x;

            // Cycle found
            if (seen.count(state)) {
                int cycleLength = day - seen[state];
                int remaining = (n - day) % cycleLength;

                day = n - remaining;
            }

            seen[state] = day;

            if (day == n) break;

            vector<int> next(8, 0);

            for (int i = 1; i < 7; i++)
                next[i] = (cells[i - 1] == cells[i + 1]);

            cells = next;
            day++;
        }

        return cells;
    }
};

int main() {
    return 0;
}
