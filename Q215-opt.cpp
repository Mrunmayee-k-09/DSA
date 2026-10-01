#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

// Using max heap. From max we always get the largest element.
// From the min heap, we get the smallest element.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       //max heap 
       priority_queue<int> q;
       for(int i=0; i<nums.size(); i++) {
        q.push(nums[i]);
       }
       for(int i=0; i<k; i++) {
        if(i==k-1) {
            return q.top();
        }
        else{
            q.pop();
        }
       }
       return -1;
    }
};
//O(n log n)