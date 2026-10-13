#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int j = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                ans[j] = nums[i];
                j++;
            }
        }

        for (int i = 0; i < n; i++) {
            nums[i] = ans[i];
        }
    }
};

/*nums = [0, 1, 0, 3, 12]
1. Create ans = [0, 0, 0, 0, 0].
2. Pick the non-zero elements in their original order: 1, 3, 12.
3. Place them at the beginning of ans: [1, 3, 12, 0, 0].
4. Copy ans back into nums.

We modified ans, not nums!
At this point, nums is still [0, 1, 0, 3, 12].
So,  nums[i] = ans[i]*/