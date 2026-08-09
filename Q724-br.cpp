#include<vector>
using namespace std;


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i, j, n;
        n = nums.size();
        int pivot = -1 ;
        int left, right;
        
        for(i=0; i<n; i++) {
            left = 0;

            for(j=i-1; j>=0; j--){
            left += nums[j];
          }
            
            right = 0;
            
            for(j=i+1; j<n; j++) {
            right += nums[j];
        }
            if(left == right) {
               return i;
        }
        }
        return pivot;
    }
};


// int total = 0;


