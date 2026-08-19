// Q 15 brute force approach

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// Set usually takes O(log n) time, unordered set only takes O(1)
// Time complexity here is O(n³).

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;
        set<vector<int>> s; // Basically a set of unique triplets 
        

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {

                    if(nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> trip = {nums[i], nums[j], nums[k]};
                        sort(trip.begin(), trip.end());

                        if(s.find(trip) == s.end()) {  

                        //I searched for trip, and it reached the end without finding it
                        // Checking if another same triplet exits or not.
                        // if these are equal, then the triplet doesn't exit, we gotta add it.

                            s.insert(trip);
                            ans.push_back(trip);
                        }
                    }

                }
            }
        }

        return ans;
    }
};