#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
          k = k % n;
        vector<int> answer(n);

        int newIndex;

        for(int i = 0; i < n; i++) {
            newIndex = (i + k) % n;
            answer[newIndex] = nums[i];
        }

        nums = answer;
    }
};

//T.C and S.C. = O(n)
