/**
 * LeetCode Problem: Cinema Seat Allocation
 * Pushed by LeetCommit
 * Date: 2026-08-19
 */

#include <bits/stdc++.h>
using namespace std;

// --- LeetCode Solution ---
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>> mp;

        for(auto r:reservedSeats){
            mp[r[0]].insert(r[1]);
        }

        int result=(n-mp.size())*2;
        for(auto& [row, bookedSeats] : mp) {

            auto isAvailable = [&](int seat) {
                return bookedSeats.find(seat) == bookedSeats.end();
            };

            bool graupA = isAvailable(2) && isAvailable(3) && isAvailable(4) & isAvailable(5);
            bool graupB = isAvailable(4) && isAvailable(5) && isAvailable(6) & isAvailable(7);
            bool graupC = isAvailable(6) && isAvailable(7) && isAvailable(8) & isAvailable(9);

            if(graupA && graupC)
                result += 2;
            else if(graupA || graupB || graupC)
                result += 1;

        }

        return result;

    }
};

int main() {
    return 0;
}
