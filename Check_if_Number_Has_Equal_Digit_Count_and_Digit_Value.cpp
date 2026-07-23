/**
 * LeetCode Problem: Check if Number Has Equal Digit Count and Digit Value
 * Pushed by LeetCommit
 * Date: 2026-07-23
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int,int> mp;
        for(int i=0;i<num.size();i++){
            mp[num[i]-'0']++;
        }
        for(int i=0;i<num.size();i++){
           if(mp[i]!=(num[i]-'0')) return false;
        }
        return true;
        
    }
};

int main() {
    return 0;
}
