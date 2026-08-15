/**
 * LeetCode Problem: Minimum Difficulty of a Job Schedule
 * Pushed by LeetCommit
 * Date: 2026-08-15
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int t[301][11];
    int f(int idx,int d,int n,vector<int> & jd){
        if(d==1){
            int maxD=jd[idx];
            for(int i=idx+1;i<n;i++){
                maxD=max(maxD,jd[i]);
            }
            return maxD;
        }
        if(t[idx][d]!=-1) return t[idx][d];

        int maxD=jd[idx];
        int ans=INT_MAX;

        for(int k=idx;k<=n-d;k++){
            maxD=max(maxD,jd[k]);
            int res=maxD+f(k+1,d-1,n,jd);
            ans=min(ans,res);
        }
        return t[idx][d]=ans;
    }
    int minDifficulty(vector<int>& jd, int d) {
        int n=jd.size();
        if(n<d ) return -1;

        memset(t,-1,sizeof(t));
        return f(0,d,n,jd);
    }
};

int main() {
    return 0;
}
