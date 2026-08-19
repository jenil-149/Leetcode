/**
 * LeetCode Problem: Smallest String With A Given Numeric Value
 * Pushed by LeetCommit
 * Date: 2026-08-19
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    string getSmallestString(int n, int k) {
        int s = n - 1;
        int a = 0;

        while (s > 0 && k - s * 26 <= a) {
            s--;
            a++;
        }

        int req = k - s * 26 - a;

        string a1(a, 'a');
        string a2(1, char('a' + req - 1));
        string a3(s, 'z');

        return a1 + a2 + a3;
    }
};

int main() {
    return 0;
}
