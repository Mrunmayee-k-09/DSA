#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

/* First we are gonna sort the array
We'll go with left and right pointer method. First we'll be taking the
an element from the array on the position (let's say a) and then we'll
travel from left and right both to get the numbers (let's say at 
positions b & c) which, on adding in a, will give 0
If sum>0, we'll do right-- and if sum<0, we'll do left++. This works
because we have sorted the array in the 1st place.

There could be duplicates among these left & right values too. So, in 
that case, we would shift our pointer once more.
T.C - O(n log n) + O(n^2). S.C. - O(1) / O(n)
*/class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {

            // Skip duplicate values of a
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while(left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // Skip duplicate b values
                    while(left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // Skip duplicate c values
                    while(left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }

                else if(sum < 0) {
                    left++;
                }

                else {
                    right--;
                }
            }
        }

        return ans;
    }
};

