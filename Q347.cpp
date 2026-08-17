#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        // Bucket sort 
        // We will treat index positions as count i -> count
        /* For eg. [1, 1, 1, 2, 2, 100]
        i = 0 
            1 - [100]
            2 - [2]
            3 - [1]
            4
            5
            6 
        Why did we stop at 6? 
        -> Because the input array has size 6. So, even all the numbers are same, the max times a number can repeat is 6. No need to 0 actually. Just took it as an index.
        We'll go in descending order through the indexes (From 6 to 1) to the max ones.
        So, we go from index 6(nothing),index 5(nothing), index 4(nothing), index 3(got 1) i.e. 1 HAS occured max times. So, we'll put that 1 in the K. Next go to index 2(got 2) */

        unordered_map<int, int>mp;

        // Count the frequencies 
        for(int i = 0; i<n; i++) {
            mp[nums[i]]++;
        }
        vector<vector<int>>bucket(n + 1); // To get 0 to 6, so total 7.

        // Now put numbers into their frequency bucket.
        for(auto pair : mp) {
            bucket[pair.second].push_back(pair.first);
        }

        vector<int> ans;

        
        for(int i = n; i>=1; i--) {
            for(int num : bucket[i]) {
                ans.push_back(num);

                if(ans.size() == k) {
                    return ans;
                }
            }
        }
          
        return ans;  
    }
};