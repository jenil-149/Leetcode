/**
 * LeetCode Problem: Reverse Integer
 * Auto-synced by LeetCommit
 * Date: 2026-06-19
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7)) {
                return 0;
            }
            
            x /= 10;
            int pop = x % 10;
        
        while (x != 0) {
            
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8)) {
                return 0;
            }
            result = result * 10 + pop;
        }
        
        return result;
        int result = 0;
    int reverse(int x) {
public:
class Solution {

#include <climits>
    }
};

int main() {
    // Test cases can be written here
    return 0;
}
