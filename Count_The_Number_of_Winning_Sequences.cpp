/**
 * LeetCode Problem: Count The Number of Winning Sequences
 * Pushed by LeetCommit
 * Date: 2026-08-17
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
// fire beats earth
//earth beats water
//water beats fire
//tie -no points

//bob neverr repeats same char
//B0b wins B>A -> no. possible sqe of bob?

class Solution {
public:
    // 0-F 1-W 2-E
    typedef long long ll;
    const int  mod=1e9+7;
    int n;

    int dp[3][1001][2001];

    ll f(int idx,int prev,int score,string & s){
        if(idx==n) return score>0?1:0;
        ll fire=0,water=0,earth=0;

        if(dp[prev][idx][score+1000]!=-1) return dp[prev][idx][score+1000];

        if(s[idx]=='F'){
            if(prev!=0) fire  = f(idx+1,0,score,s)%mod;
            if(prev!=1) water = f(idx+1,1,score+1,s)%mod;
            if(prev!=2) earth = f(idx+1,2,score-1,s)%mod;
        }
        else if(s[idx]=='W'){

            if(prev!=0) fire  = f(idx+1,0,score-1,s)%mod;
            if(prev!=1) water = f(idx+1,1,score,s)%mod;
            if(prev!=2) earth = f(idx+1,2,score+1,s)%mod;

        }else if(s[idx]=='E'){

            if(prev!=0) fire  = f(idx+1,0,score+1,s)%mod;
            if(prev!=1) water = f(idx+1,1,score-1,s)%mod;
            if(prev!=2) earth = f(idx+1,2,score,s)%mod;
        }

        return dp[prev][idx][score+1000]=(fire+water+earth);

    }
    int countWinningSequences(string s) {
        n=s.size();
        memset(dp, -1, sizeof(dp));

        ll ans=(f(0,0,0,s) +f(0,1,0,s)+f(0,2,0,s));
        return (ans/2)%mod;

    }
};




int main() {
    return 0;
}
