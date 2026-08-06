/**
 * LeetCode Problem: Unique Morse Code Words
 * Pushed by LeetCommit
 * Date: 2026-08-06
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse={".-","-...","-.-.","-..",".","..-.","--.",
                         "....","..",".---","-.-",".-..","--","-.",
                         "---",".--.","--.-",".-.","...","-","..-",
                         "...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        for(auto w:words){
            string temp="";
            for(char c: w) temp+=morse[c-'a'];
            s.insert(temp);
        }
        return s.size();
    }
};

int main() {
    return 0;
}
