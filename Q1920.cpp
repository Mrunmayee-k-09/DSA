/* Logic is basically to do nums[nums[i]], means 
5 2 3 4 1 9
nums[nums[1]] = nums[5] = 9 */

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        // Final Value
        for(int i=0; i<n; i++) {
            nums[i] = nums[i] + 1000*(nums[nums[i]] % 1000);
        }

        for(int i=0; i<n; i++) {
            nums[i] /= 1000;
        }
        return nums;
    }
};