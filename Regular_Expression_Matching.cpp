/**
 * LeetCode Problem: Regular Expression Matching
 * Pushed by LeetCommit
 * Date: 2026-07-09
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
                    curr[j] = prev[j-1];
                }

                else if(p[j-1] == '*')
                {
                    // Ignore x*
                    curr[j] = curr[j-2];

                    // Use x*
                    if(p[j-2] == '.' || p[j-2] == s[i-1])
                        curr[j] = curr[j] || prev[j];
                }

                else
                {
                    curr[j] = false;
                }

int main() {
    return 0;
}
