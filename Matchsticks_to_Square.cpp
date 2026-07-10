/**
 * LeetCode Problem: Matchsticks to Square
 * Pushed by LeetCommit
 * Date: 2026-07-10
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);

        if(sum%4) return false;

        int target=sum/4;
        int n=matchsticks.size();

        sort(matchsticks.begin(),matchsticks.end());

        vector<int> dp(1<<n,-1);
        dp[0]=0;

        for(int mask=0;mask<(1<<n);mask++){

            if(dp[mask]==-1) continue;

            for(int i=0;i<n;i++){

                // stick is already used
                if(mask&(1<<i))
                    continue;
                //adding ith stick makes sum>target  we ignore it and all other as it is sorted
                if(dp[mask]+matchsticks[i] > target)
                    continue;

                int newMask=mask|(1<<i);
                dp[newMask]=(dp[mask]+matchsticks[i])%target;
            }
        }
        return dp[(1<<n)-1]==0;
    }
};

int main() {
    return 0;
}
