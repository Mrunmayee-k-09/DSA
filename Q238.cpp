#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        long long left = 1;
        long long right = 1;

        vector<int> ans(n);

        // Left → Right
        for(int i = 0; i < n; i++) {
            ans[i] = left;
            left *= nums[i];
        }

        // Right → Left
        for(int i = n - 1; i >= 0; i--) {
            ans[i] *= right;
            right *= nums[i];
        }

        return ans;
    }
};