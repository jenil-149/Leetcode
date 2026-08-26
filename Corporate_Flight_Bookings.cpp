/**
 * LeetCode Problem: Corporate Flight Bookings
 * Pushed by LeetCommit
 * Date: 2026-08-26
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> d(n,0);

        for(auto b:bookings){
            int l=b[0];
            int r=b[1];
            int revSeats=b[2];

            d[l-1]+=revSeats;
            if(r<n) d[r]-=revSeats;
        }
        for(int i=1;i<n;i++) d[i]+=d[i-1];
        return d;


    }
};

int main() {
    return 0;
}
