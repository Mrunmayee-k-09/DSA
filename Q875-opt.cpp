#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

//T.C. = O(n×log(maxPile))​

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = INT_MAX;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long  totalHours = 0;

            // Calculate hours needed at speed = mid
            for (int i = 0; i < piles.size(); i++) {
                totalHours += ceil((double)piles[i] / mid);
            }

            if (totalHours <= h) {
                // mid works, but maybe we can go slower
                ans = mid;
                high = mid - 1;
            }
            else {
                // mid is too slow
                low = mid + 1;
            }
        }

        return ans;
    }
};