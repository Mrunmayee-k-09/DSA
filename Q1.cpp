// LeetCode #1 - Two Sum
// Approach: Brute Force
// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                int sum = nums[i] + nums[j];

                if (sum == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};