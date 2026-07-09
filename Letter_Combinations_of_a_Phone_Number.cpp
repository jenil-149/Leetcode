/**
 * LeetCode Problem: Letter Combinations of a Phone Number
 * Pushed by LeetCommit
 * Date: 2026-07-09
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:

    void solve(int i,string& digits,vector<string> &letters,string &curr,vector<string> &ans){
        if(i==digits.size()) {
            ans.push_back(curr);
            return;
        }

        for(char ch: letters[digits[i]-'0']){
            curr.push_back(ch);
            solve(i+1,digits,letters,curr,ans);
            curr.pop_back();

        }
    }
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        
        vector<string> letters={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string curr="";

        solve(0,digits,letters,curr,ans);
        
        return ans;
    }
};

int main() {
    return 0;
}
