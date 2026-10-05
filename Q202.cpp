#include<iostream>
#include<set>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {

        set<int> seen;

        while(n != 1) {

            // If we've already seen this number,
            // we're stuck in a cycle
            if(seen.count(n)) {
                return false;
            }

            seen.insert(n);

            int sum = 0;

            // Calculate sum of squares of digits
            while(n > 0) {
                int digit = n % 10;
                sum = sum + digit * digit;
                n = n / 10;
            }

            n = sum;
        }

        return true;
    }
};

/*2 → 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4
                                              ↑
                                          seen before!
                                              ↓
                                         return false*/