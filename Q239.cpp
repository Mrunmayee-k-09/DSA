#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int>result;

        // 1st window 
        for(int i=0; i<k; i++) {
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
         }
        // Next windows.
         for(int i=k; i<nums.size(); i++) {
            result.push_back(nums[dq.front()]);

            // remove elements which aren't part of current window.
            while(dq.size() > 0 && dq.front() <= i-k) {
                dq.pop_front();
            }
            // Remove the smaller values
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
         }

         result.push_back(nums[dq.front()]);
         return result;
    }
};