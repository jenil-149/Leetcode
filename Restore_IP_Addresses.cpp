/**
 * LeetCode Problem: Restore IP Addresses
 * Pushed by LeetCommit
 * Date: 2026-07-10
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:

    int n;

    //functio to check each part validation
    bool isvalid(string str){
        if(str.size()>1 && str[0]=='0') return false;

        int val=stoi(str);
        return val<=255;
    }

    //recursive function 3fun calls O(3^n)
    void f(string &s,int idx,int parts,string curr,vector<string>& ans){
        if(idx==n && parts==4){
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
            if(parts > 4) return;

            if(idx == n) return;
        if(idx+1<=n && isvalid(s.substr(idx,1)))
        f(s,idx+1,parts+1,curr+s.substr(idx,1)+".",ans);
        if(idx+2<=n && isvalid(s.substr(idx,2)))
        f(s,idx+2,parts+1,curr+s.substr(idx,2)+".",ans);
        if(idx+3<=n && isvalid(s.substr(idx,3)))
        f(s,idx+3,parts+1,curr+s.substr(idx,3)+".",ans);
    }

    vector<string> restoreIpAddresses(string s) {
        n=s.size();

        // if size is grater than 12 it cannot be made in part of 4 and size 3
        if(n>12) return {};
        vector<string> ans;

        int parts=0;
        string curr="";

        f(s,0,parts,curr,ans);

        return ans;

    }
};

int main() {
    return 0;
}
