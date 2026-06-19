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
            // Check for positive overflow before pushing the digit
            
            x /= 10;
            // Pop the last digit off
            int pop = x % 10;
        
        while (x != 0) {
    int reverse(int x) {
        int result = 0;
public:
class Solution {

#include <climits>
            
            // Check for negative overflow (underflow) before pushing the digit
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8)) {
                return 0;
            }
            
            // Push the digit onto the result
            result = result * 10 + pop;
        }
        
        return result;

int main() {
    // Test cases can be written here
    return 0;
}
