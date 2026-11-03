#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int low = 0;
        int high = letters.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (letters[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        if (low == letters.size()) {
            return letters[0];
        }

        return letters[low];
    }
};

/*
When the loop ends (left > right): The left pointer has crossed over right. At this exact moment, left points to the index of the first element greater than target (or to n if target is larger than all elements in the array).*/