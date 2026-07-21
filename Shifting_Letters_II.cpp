/**
 * LeetCode Problem: Shifting Letters II
 * Pushed by LeetCommit
 * Date: 2026-07-21
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        int n=s.size();
        vector<int> diff(n,0);

        for(auto q:shifts){
            int start=q[0];
            int end=q[1];
            int dir=q[2];
            int x=0;

            if(dir==1){
                 x=1;
            }else{
                x=-1;
            }

            diff[start]+=x;
            if(end+1<n)
                diff[end+1]-=x;

        }
        for(int i=1;i<n;i++){
            diff[i]=diff[i]+diff[i-1];
        }

        for(int i=0;i<n;i++){

            int shift=diff[i]%26;
            if(shift<0) shift+=26;

            s[i]=(((s[i]-'a')+shift)%26)+'a';

        }
        return s;
    }
};

int main() {
    return 0;
}
