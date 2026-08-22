#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.length();

        int left = 0;
        int right = 0;

        int freq[26] = {0};

        int maxFreq = 0;
        int ans = 0;

        while (right < n) {

            // Add the current character to our window
            freq[s[right] - 'A']++;

            // Update the highest frequency character
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // Current window length
            int windowLen = right - left + 1;

            // If we need more than k replacements,
            // shrink the window from the left
            if (windowLen - maxFreq > k) {

                freq[s[left] - 'A']--;
                left++;
            }

            // Window is valid, so update answer
            ans = max(ans, right - left + 1);

            // Expand window
            right++;
        }

        return ans;
    }
};