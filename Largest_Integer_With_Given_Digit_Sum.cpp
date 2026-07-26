/**
 * LeetCode Problem: Largest Integer With Given Digit Sum
 * Pushed by LeetCommit
 * Date: 2026-07-26
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int largestInteger(int n, int s) {
        if(n*9 <s) return -1;
        if(s==0) return 0;

        string ans="";
        for(int i=0;i<n;i++){
            int d=min(9,s);
            ans+=char(d+'0');
            s-=(d);
        }
        return stoi(ans);


    }
};

int main() {
    return 0;
}
