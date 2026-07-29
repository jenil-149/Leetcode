/**
 * LeetCode Problem: Smallest Palindromic Rearrangement II
 * Pushed by LeetCommit
 * Date: 2026-07-29
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:

    static constexpr long long LIMIT = 1000001; 
    typedef long long ll;

    ll nCr(int n,int r){

        if(r>n) return 0;
        r=min(r,n-r);

        ll ans=1;

        for(int i=1;i<=r;i++){
            ans=ans*(n-i+1)/i;

            if (ans >= LIMIT)
                return LIMIT;
        }

        return ans;

    }
    ll countWays(vector<int> &half){
        int rem=0;
        for(int x:half) rem+=x;
        ll ways=1;

        for(int x:half){
            if(x==0) continue;

            ways*=nCr(rem,x);
            if(ways>=LIMIT) return LIMIT;

            rem-=x;

        }
        return ways;
    }
   
    string smallestPalindrome(string s, int k) {

        int n=s.size();
        vector<int> freq(26,0),half(26,0);
        char mid=0;

        for(char c:s) freq[c-'a']++;

        for(int i=0;i<26;i++){
            half[i]=freq[i]/2;

            if(freq[i]&1) mid=char(i+'a');
        }

        if(countWays(half)<k) return "";
        
        string left;
        int len=0;

        for(int x:half) len+=x;

        while((int)left.size()<len){
            for(int c=0;c<26;c++){

                if(half[c]==0) continue;

                half[c]--;

                ll ways=countWays(half);

                if(ways>=k){
                    left.push_back((char)(c+'a'));
                    break;
                }
                k-=ways;
                half[c]++;
            }
        }

        string right=left;
        reverse(begin(right),end(right));

        if(mid) return left+string(1,mid)+right;
        return left+right;
    }
};

// class Solution {
// public:
//     string smallestPalindrome(string s, int k) {

//         int n=s.size();
//         string temp=s.substr(0,n/2);
//         sort(temp.begin(),temp.end());
//         k--;
//         while(k--){
//             if(!next_permutation(temp.begin(),temp.end())){ 
//                  return "";
//               }
//         }
//         for(int i=0;i<n/2;i++){
//             s[i]=temp[i];
//             s[n-1-i]=temp[i];
//         }
//         return s;
//     }
// };

int main() {
    return 0;
}
