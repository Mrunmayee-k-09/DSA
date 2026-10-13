#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int required = target - nums[i];

            if(seen.find(required) != seen.end()) {
                return {seen[required], i};
            }

            seen[nums[i]] = i;
        }

        return {};
    }
};


/*

Step 1: Current number = 2
Required number = (9-2=7)
We haven't seen 7 yet, so store 2 and its index.



7

Step 2: Current number = 7
Required number = (9-7=2)
We already have 2 stored! Its index is 0, and 7's index is 1.


Answer: {0, 1}*/