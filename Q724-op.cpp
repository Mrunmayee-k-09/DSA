#include<vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            total += nums[i];
        }

        int leftSum = 0;

        for (int i = 0; i < n; i++) {

            int rightSum = total - leftSum - nums[i];

            if (rightSum == leftSum) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};