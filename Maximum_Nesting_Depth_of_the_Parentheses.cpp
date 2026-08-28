/**
 * LeetCode Problem: Maximum Nesting Depth of the Parentheses
 * Pushed by LeetCommit
 * Date: 2026-08-28
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int maxDepth(string s) {
        int mxOpen=0;
        int open=0;
        for(char c:s){
            if(c=='(') open++;
            else if(c==')') open--;

            mxOpen=max(mxOpen,open);
        }
        return mxOpen;
    }
};

int main() {
    return 0;
}
