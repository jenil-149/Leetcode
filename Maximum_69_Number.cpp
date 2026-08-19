/**
 * LeetCode Problem: Maximum 69 Number
 * Pushed by LeetCommit
 * Date: 2026-08-19
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        for(int i=0;i<s.size();i++){
            if(s[i]=='6') {
                s[i]='9';
                break;
            }
        }
        return stoi(s);
    }
};

int main() {
    return 0;
}
