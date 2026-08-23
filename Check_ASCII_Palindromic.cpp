/**
 * LeetCode Problem: Check ASCII Palindromic
 * Pushed by LeetCommit
 * Date: 2026-08-23
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    bool isPalindromic(string s) {
        string b="";
        for(char c:s){
            b+=bitset<8>(c).to_string();
        }
        string r=b;
        reverse(r.begin(),r.end());

        return r==b;
    }
};

int main() {
    return 0;
}
