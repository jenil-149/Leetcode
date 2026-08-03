/**
 * LeetCode Problem: Largest Odd Number in String
 * Pushed by LeetCommit
 * Date: 2026-08-03
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    string largestOddNumber(string num) {
        
        int idx=-1;
        for(int i=num.size()-1;i>=0;i--){
            if((num[i]-'0')%2==1){
                idx=i;
                break;
            }
        }
        return num.substr(0,idx+1);
    }
};

int main() {
    return 0;
}
