#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        /*Start with 1 banana per hour if the time limit exceeds, then increase the count to 2 bananas per hour.
        Like for example 1, [3,6,7,11], if we take 2 banana per hour, koko will take 2+3+4+6 =15 hours. So, too much.
        With 3 also, it'll exceed. Take 4 and we'll get 1+2+2+3 = 8hr. Voila ! Got it. 
        The will be from 1 ro 11 only. Because the max pile is of 11. If you eat 11 at one time it'll take 1+1++1+1 = 4 hours. Now after this if you take 12 13 14, it'll still give the same ans 1+1++1+1 = 4.
        So, max koko can have is 11 bananas at a time. 

        ans ( 1 to max in the pile array)
        req time = 0;
        func(pile, what can koko can eat per hour) 

        if(req time <= h) {
        return i;}

        totalHour = 0; 
        for(i to n-1)
        totalHour += ceil(pile arr[i]/ what can koko can eat per hour) 
         return totalHour
         But this is brute force. Will give T.C O(n × maxPile)
        */

       

        int maxPile = *max_element(piles.begin(), piles.end());

        // Try every possible eating speed from 1 to maxPile
        for (int k = 1; k <= maxPile; k++) {

            int totalHours = 0;

            // Calculate how many hours Koko needs at speed k
            for (int i = 0; i < piles.size(); i++) {

                totalHours += ceil((double)piles[i] / k);
            }

            // If she can finish within h hours,
            // this is the minimum possible speed
            if (totalHours <= h) {
                return k;
            }
        }

        return maxPile;
    }
};
