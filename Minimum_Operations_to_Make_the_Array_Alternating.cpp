/**
 * LeetCode Problem: Minimum Operations to Make the Array Alternating
 * Pushed by LeetCommit
 * Date: 2026-07-25
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
    int freq[100001][2];

public:
    int minimumOperations(vector<int>& nums) {
        memset(freq, 0, sizeof(freq));

        int n = nums.size();

        // Count frequency of each value at even and odd indices
        for (int i = 0; i < n; i++) {
            freq[nums[i]][i % 2]++;
        }

        int ans = 0;
        int bestEven = 0; // Maximum frequency at even indices seen so far
        int bestOdd = 0;  // Maximum frequency at odd indices seen so far

        for (int val = 1; val <= 100000; val++) {
            // Choose 'val' for even indices
            ans = max(ans, freq[val][0] + bestOdd);

            // Choose 'val' for odd indices
            ans = max(ans, freq[val][1] + bestEven);

            // Update best frequencies
            bestEven = max(bestEven, freq[val][0]);
            bestOdd = max(bestOdd, freq[val][1]);
        }

        return n - ans;
    }
};


// class Solution {
// public:
//     int minimumOperations(vector<int>& nums) {
//         int n = nums.size();

//         unordered_map<int, int> evenFreq, oddFreq;

//         for (int i = 0; i < n; i++) {
//             if (i % 2 == 0)
//                 evenFreq[nums[i]]++;
//             else
//                 oddFreq[nums[i]]++;
//         }

//         // {frequency, value}
//         pair<int, int> even1 = {0, 0}, even2 = {0, 0};
//         pair<int, int> odd1 = {0, 0}, odd2 = {0, 0};

//         // Find top 2 frequent elements for even indices
//         for (auto &it : evenFreq) {
//             if (it.second > even1.first) {
//                 even2 = even1;
//                 even1 = {it.second, it.first};
//             } else if (it.second > even2.first) {
//                 even2 = {it.second, it.first};
//             }
//         }

//         // Find top 2 frequent elements for odd indices
//         for (auto &it : oddFreq) {
//             if (it.second > odd1.first) {
//                 odd2 = odd1;
//                 odd1 = {it.second, it.first};
//             } else if (it.second > odd2.first) {
//                 odd2 = {it.second, it.first};
//             }
//         }

//         int evenCount = (n + 1) / 2;
//         int oddCount = n / 2;

//         // Best values are different
//         if (even1.second != odd1.second) {
//             return (evenCount - even1.first) + (oddCount - odd1.first);
//         }

//         // Best values are same
//         int option1 = (evenCount - even1.first) + (oddCount - odd2.first);
//         int option2 = (evenCount - even2.first) + (oddCount - odd1.first);

//         return min(option1, option2);
//     }
// };

int main() {
    return 0;
}
