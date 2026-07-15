/**
 * LeetCode Problem: Remove K Digits
 * Pushed by LeetCommit
 * Date: 2026-07-15
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        
        for(char c: num){
            while( !st.empty() && st.top()>c && k>0){
                st.pop();
                k--;
            }
            st.push(c);
            // remove leading zeros
            if(st.size()==1 && st.top()=='0') st.pop();
        }
        //remaining k removal
        while(k-- && !st.empty()){
            st.pop();
        }
        // store ans in string
        string s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        
        reverse(s.begin(),s.end());

        // return 0 if empty string 
        return s==""?"0":s;
        
    }
};

int main() {
    return 0;
}
