/**
 * LeetCode Problem: Maximum Number of Groups Entering a Competition
 * Pushed by LeetCommit
 * Date: 2026-08-17
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
    public:
    int maximumGroups(vector<int> grades) {
        int n = grades.size();

        int low = 0, high = n;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long sum = (long) mid * (mid + 1) / 2;

            if (sum <= n) {
                ans = mid;
                low = mid + 1; // try bigger k
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

//Greedy soln

// class Solution {
// public:
//     int maximumGroups(vector<int>& grades) {
//         int prevSum=0,prevCnt=0;
//          int currSum=0,currCnt=0;
//         int ans=0;

//         sort(grades.begin(),grades.end());

//         for(int g:grades){
           
//             currSum+=g;
//             currCnt++;
//             if(currCnt>prevCnt && currSum>prevSum){
//                 ans++;
//                 prevSum=currSum;
//                 prevCnt=currCnt;

//                 currCnt=0;
//                 currSum=0;
//             }
//         }
//         return ans;

//     }
// };

int main() {
    return 0;
}
