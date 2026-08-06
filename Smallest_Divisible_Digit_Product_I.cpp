/**
 * LeetCode Problem: Smallest Divisible Digit Product I
 * Pushed by LeetCommit
 * Date: 2026-08-06
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int product(int n){
        int p=1;
        while(n){
            p*=n%10;
            n/=10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        
        while(product(n)%t!=0) n++;
        return n;
    }
};

int main() {
    return 0;
}
