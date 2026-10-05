#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> count;

        for(int i = 0; i < nums.size(); i++) {
            ans += count[nums[i]];
            count[nums[i]]++;
        }

        return ans;
    }
};