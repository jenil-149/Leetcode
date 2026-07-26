/**
 * LeetCode Problem: Count Palindromic Subsequences
 * Pushed by LeetCommit
 * Date: 2026-07-26
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int mod=1e9+7;
    typedef long long ll;

    int countPalindromes(string s) {
        int n=s.size();

        vector<vector<vector<ll>>> pre(n+1,(vector<vector<ll>>(10,vector<ll>(10,0))));

        vector<ll>cnt (101,0);

        for(int i=0;i<n;i++){
            pre[i+1]=pre[i];

            int d=s[i]-'0';
            for(int x=0;x<10;x++){
                pre[i+1][x][d] = ( pre[i+1][x][d] + cnt[x] ) % mod;
            }

            cnt[d]++;
        }

        vector<vector<vector<ll>>> suf(n+1,(vector<vector<ll>>(10,vector<ll>(10,0))));

        fill(cnt.begin(), cnt.end(), 0);

        for(int i=n-1;i>=0;i--){
            suf[i]=suf[i+1];

            int d=s[i]-'0';
            for(int x=0;x<10;x++){
                suf[i][d][x] = ( suf[i][d][x] + cnt[x] ) % mod;
            }

            cnt[d]++;
        }

        ll ans=0;

        for(int mid=2;mid<=n-3;mid++){
            for(int a=0;a<10;a++){
                for(int b=0;b<10;b++){
                    ans=( ans + pre[mid][a][b]*suf[mid+1][b][a] ) % mod;
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
