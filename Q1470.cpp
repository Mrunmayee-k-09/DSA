/* We want i with n+i
Pair 1 → positions 0, 1
Pair 2 → positions 2, 3
Pair 3 → positions 4, 5
*/

#include<vector>
using namespace std;
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
       vector<int>ans(2*n);   // 2*n is the array size. We just created an ans array.
        n = nums.size()/2;   // Write it or not, question has already given its n 
        for(int i=0; i<n; i++){
        ans[2*i] = nums[i];
        ans[2*i+1] = nums[n+i]; 
        }
        return ans; 
    }
};