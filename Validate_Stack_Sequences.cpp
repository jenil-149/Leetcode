/**
 * LeetCode Problem: Validate Stack Sequences
 * Pushed by LeetCommit
 * Date: 2026-08-11
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0;
        for(int n:pushed){
            st.push(n);
            while(!st.empty() && st.top()==popped[i]){
                st.pop();
                i++;
            }

        }
        return st.empty();
    }
};

int main() {
    return 0;
}
