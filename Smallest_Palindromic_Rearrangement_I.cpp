/**
 * LeetCode Problem: Smallest Palindromic Rearrangement I
 * Pushed by LeetCommit
 * Date: 2026-07-28
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        vector<int> freq(26,0);
        
        for(int i=0;i<n/2;i++){
           freq[s[i]-'a']++;
        }

        int l=0;
        int r=n-1;
       
        for(int i=0;i<26;i++){

            while(freq[i]>0){

                s[l++]=i+'a';;
                s[r--]=i+'a';;
                freq[i]--;
            }
    
        }
        return s;
    }
};

// class Solution {
// public:
//     string smallestPalindrome(string s) {
//         int n=s.size();
//         sort(s.begin(),s.begin()+n/2);
//         sort(s.begin() + (n+1)/2,s.end(), greater<char>());
//         return s;
//     }
// };

int main() {
    return 0;
}
