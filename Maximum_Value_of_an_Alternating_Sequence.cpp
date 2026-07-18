/**
 * LeetCode Problem: Maximum Value of an Alternating Sequence
 * Pushed by LeetCommit
 * Date: 2026-07-18
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n==1) return s;
        return (long long)s+ 1LL (n/2)*m-((n 2)-1);
    }
};

int main() {
    return 0;
}
