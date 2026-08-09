#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        int runningSum = nums[0];

        for(int i = 1; i < n; i++) {
            runningSum += nums[i];
            nums[i] = runningSum;
        }

        return nums;
    }
};