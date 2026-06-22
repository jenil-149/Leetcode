/**
 * LeetCode Problem: Find the Index of the First Occurrence in a String
 * Pushed by LeetCommit
 * Date: 2026-06-22
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=needle.size();
        int n=haystack.size();
        if(m>n) return -1;
        

        for(int i=0;i<=n-m;i++){
            string s=haystack.substr(i,m);
            if(needle==s) return i;
        }
        return -1;
        
    }
};

int main() {
    return 0;
}
