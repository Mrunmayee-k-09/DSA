#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int left = 0;
        int maxLength = 0;
        int right = 0;
        
        set<char>setChar;

        while(right<n) {
            while(setChar.find(s[right]) != setChar.end()) {  //If s[right] is found inside setChar → duplicate.
                    setChar.erase(s[left]);
                    left++;
            }

            setChar.insert(s[right]);

            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
};

/* left = 0
right = 2

a b c
↑   ↑

There are 3 characters, not 2.

So:

int length = right - left + 1;*/