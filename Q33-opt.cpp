#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            // Target found
            if(nums[mid] == target) {
                return mid;
            }

            // Left half is sorted
            if(nums[low] <= nums[mid]) {

                // Target lies in left sorted half
                if(target >= nums[low] && target <= nums[mid]) {
                    high = mid - 1;
                }

                // Target lies in right half
                else {
                    low = mid + 1;
                }
            }

            // Right half is sorted
            else {

                // Target lies in right sorted half
                if(target >= nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                }

                // Target lies in left half
                else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};