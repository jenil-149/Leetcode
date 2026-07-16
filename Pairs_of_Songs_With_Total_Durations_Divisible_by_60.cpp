/**
 * LeetCode Problem: Pairs of Songs With Total Durations Divisible by 60
 * Pushed by LeetCommit
 * Date: 2026-07-16
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> mp;
        int ans=0;
      
        for(int i=0;i<time.size();i++){
            int rem=time[i]%60;
            int req=(60-rem)%60;
            if(mp.find(req)!=mp.end()){
                ans+=mp[req];
            }
            mp[rem]++;
        }
        return ans;
    }
};

int main() {
    return 0;
}
