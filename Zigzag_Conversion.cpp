/**
 * LeetCode Problem: Zigzag Conversion
 * Pushed by LeetCommit
 * Date: 2026-07-09
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
        int curR=0;
        bool up=true;

        for(char ch:s){
            //add char in the cuurr row strig
            rows[curR]+=ch;

            //change the increment/decrement if we reach 0 or numRow-1
            if(curR==0) up=true;
            if(curR==numRows-1) up=false;

            //increment/decremnet acc to the flag
            if(up) curR++;
            else curR--;

        }
        //add all string acc to row
        string ans="";

int main() {
    return 0;
}
