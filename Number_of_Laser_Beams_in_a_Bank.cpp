/**
 * LeetCode Problem: Number of Laser Beams in a Bank
 * Pushed by LeetCommit
 * Date: 2026-08-09
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> cnt;
        for(auto s: bank){
            int lasers=0;
            for(char c: s){
                if(c=='1') lasers++;
            }
            if(lasers>0) cnt.push_back(lasers);
        }
        int n=cnt.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans+=(cnt[i]*cnt[i+1]);
        }
        return ans;
    }
};

int main() {
    return 0;
}
