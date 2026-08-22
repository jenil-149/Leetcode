/**
 * LeetCode Problem: Check Divisibility by Digit Sum and Product
 * Pushed by LeetCommit
 * Date: 2026-08-22
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    bool checkDivisibility(int n) {
        int m=n;
        int sum=0;
        int product=1;
        while(m){
            int temp=m%10;
            sum+=temp;
            product*=temp;
            m/=10;
        }
        int d=sum+product;
        
        return n%d==0?1:0;
    }
};

int main() {
    return 0;
}
