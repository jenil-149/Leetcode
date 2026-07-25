/**
 * LeetCode Problem: Maximum Product of Two Digits
 * Pushed by LeetCommit
 * Date: 2026-07-25
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        sort(s.rbegin(),s.rend());
        int maxAns=(s[0]-'0')*(s[1]-'0');
        return maxAns;
    }
};


// class Solution {
// public:
//     int maxProduct(int n) {
//         vector<int> arr;
//         while(n>0){
//             arr.push_back(n%10);
//             n/=10;
//         }
//         int mx1=0;
//         int mx2=0;
//         for(int i=0;i<arr.size();i++){
//             if(arr[i]>=mx1){
//                 mx2=mx1;
//                 mx1=arr[i];
//             }
//             else if(arr[i]>mx2){
//                 mx2=arr[i];
//             }

//         }
//         return (mx1*mx2);
//     }
// };

int main() {
    return 0;
}
