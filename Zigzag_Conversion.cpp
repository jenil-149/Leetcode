/**
 * LeetCode Problem: Zigzag Conversion
 * Pushed by LeetCommit
 * Date: 2026-07-09
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(numRows==1|| numRows>=n) return s;

        vector<string> rows(numRows);

        int curR=0;
        bool up=true;

        for(char ch:s){
            //add char in the cuurr row strig
            rows[curR]+=ch;

            //change the increment/decrement if we reach 0 or numRow-1
            if(curR==0) up=true;
            if(curR==numRows-1) up=false;

            //increment/decremnet acc to the flag
            if(up) curR++;
            else curR--;

        }
        //add all string acc to row
        string ans="";
        for(auto str:rows){
            ans+=str;
        }

        return ans;

    }
};

int main() {
    return 0;
}
