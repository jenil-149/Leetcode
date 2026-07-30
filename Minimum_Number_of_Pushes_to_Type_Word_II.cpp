/**
 * LeetCode Problem: Minimum Number of Pushes to Type Word II
 * Pushed by LeetCommit
 * Date: 2026-07-30
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int minimumPushes(string word) {
       vector<int> freq(26,0);

       for(char c:word) freq[c-'a']++;

       sort(rbegin(freq),rend(freq));

       int ans=0;
       for(int i=0;i<26;i++){
            if(freq[i]!= 0) {
                ans += (i/8 +1) * freq[i]; 
            }
        }
        return ans;

    }
};

int main() {
    return 0;
}
