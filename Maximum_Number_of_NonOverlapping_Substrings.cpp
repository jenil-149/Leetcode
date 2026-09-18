/**
 * LeetCode Problem: Maximum Number of Non-Overlapping Substrings
 * Pushed by LeetCommit
 * Date: 2026-09-18
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int> firstIdx(26,-1);
        vector<int> lastIdx(26,-1);

        for(int i=0;i<n;i++){
            if(firstIdx[s[i]-'a']==-1) firstIdx[s[i]-'a']=i;
            lastIdx[s[i]-'a']=i;
        }
        vector<pair<int,int>> arr;
        for(int i=0;i<26;i++){
            if(firstIdx[i]==-1) continue;
            int l=firstIdx[i];
            int r=lastIdx[i];
            bool valid=true;

            for(int k=l;k<=r;k++){

                if(firstIdx[s[k]-'a'] < l){
                    valid=false;
                    break;
                }
                r=max(lastIdx[s[k]-'a'],r);
            }
            if(valid){
                arr.push_back({l,r});
            }
        }

        sort(arr.begin(),arr.end(),
            [](auto &a,auto &b){
                return a.second<b.second;
            });

        vector<string> ans;
        int prevIdx=-1;

        for(auto [l, r]: arr){
            if(l>prevIdx){
                ans.push_back(s.substr(l,r-l+1));
                prevIdx=r;
            }
        }
        return ans;
        
    }
};

int main() {
    return 0;
}
