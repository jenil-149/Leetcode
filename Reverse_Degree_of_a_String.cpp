/**
 * LeetCode Problem: Reverse Degree of a String
 * Pushed by LeetCommit
 * Date: 2026-09-20
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans+=(26-(s[i]-'a'))*(i+1);
        }
        return ans;
    }
};

int main() {
    return 0;
}
