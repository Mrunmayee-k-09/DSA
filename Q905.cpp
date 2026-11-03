#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n, 0);

        int pos = 0;

        // First, place all even numbers
        for (int i = 0; i < n; i++) {

            if (nums[i] % 2 == 0) {
                ans[pos] = nums[i];
                pos++;
            }
        }

        // Then, place all odd numbers
        for (int i = 0; i < n; i++) {

            if (nums[i] % 2 != 0) {
                ans[pos] = nums[i];
                pos++;
            }
        }

        return ans;
    }
};