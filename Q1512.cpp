#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(nums[i] == nums[j] && i < j) {
                    ans++;
                }

            }
        }

        return ans;
    }
};