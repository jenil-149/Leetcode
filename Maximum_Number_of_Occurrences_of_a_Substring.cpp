/**
 * LeetCode Problem: Maximum Number of Occurrences of a Substring
 * Pushed by LeetCommit
 * Date: 2026-08-13
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> mp;
        unordered_map<char, int> cnt;

        int i = 0, ans = 0;

        for(int j = 0; j < s.size(); j++) {
            cnt[s[j]]++;

            if(j - i + 1 > minSize) {
                cnt[s[i]]--;
                if(cnt[s[i]] == 0)
                    cnt.erase(s[i]);
                i++;
            }

            if(j - i + 1 == minSize && cnt.size() <= maxLetters) {
                string temp = s.substr(i, minSize);
                mp[temp]++;
                ans = max(ans, mp[temp]);
            }
        }

        return ans;
    }
};

// class Solution {
// public:
//     int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
//         unordered_map<string,int> mp;
        
//         for(int i=0;i<=s.size()-minSize;i++){
//             unordered_set<char> cs={};
//             string temp="";
//             for(int j=i;j<(i+minSize);j++){
//                 cs.insert(s[j]);
//                 temp+=s[j];
//             }
//             if(cs.size()<=maxLetters) mp[temp]++;
//         }
//         int ans=0;
//         for(auto &[str,freq]:mp){
//             ans=max(ans,freq);
//         }
//         return ans;
//     }
// };

int main() {
    return 0;
}
