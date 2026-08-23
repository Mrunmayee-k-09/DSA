#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {

        int need[128] = {0};
        int window[128] = {0};

        int required = 0, have = 0;
        int left = 0;
        int start = 0, minLen = INT_MAX;

        // Count characters we need from t
        for(char c : t) {
            if(need[c] == 0)
                required++;
            need[c]++;
        }

        // Expand window using right
        for(int right = 0; right < s.length(); right++) {

            window[s[right]]++;

            // This character's required frequency is satisfied
            if(window[s[right]] == need[s[right]])
                have++;

            // Window is valid → shrink it
            while(have == required) {

                // Save smallest window
                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                window[s[left]]--;

                // Removing it broke a requirement
                if(window[s[left]] < need[s[left]])
                    have--;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};