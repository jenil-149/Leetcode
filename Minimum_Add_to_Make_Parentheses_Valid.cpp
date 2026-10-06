/**
 * LeetCode Problem: Minimum Add to Make Parentheses Valid
 * Pushed by LeetCommit
 * Date: 2026-10-06
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int minAddToMakeValid(string s) {
        int curr=0;
        int moves=0;
        for(char c: s){
            if(c=='(') curr++;

            else {
                if(curr==0){
                    moves++;
                }
                else curr--;
            }

        }
        return moves+curr;
    }
};
// ( ( ) ) )
//( ( ) ) ) ( )) 

int main() {
    return 0;
}
