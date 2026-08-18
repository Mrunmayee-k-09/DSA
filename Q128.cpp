#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_set>
using namespace std;

/*We have to create sets based on the consecutive numbers. 
Eg. nums = [100,4,200,1,3,2]
(1-> 2-> 3-> 4)     100     200
*/



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

    unordered_set<int> numSet;
    

    for(int num : nums) {
    numSet.insert(num);  // A set doesn't store duplicates.
}
    int longest =0;
        for(int num: numSet) {
            if(!numSet.count(num-1)) {  // "If num - 1 does NOT exist..."

            int current = num;
            int length = 1;
                while(numSet.count(current+1)) {  // Keep going while the next consecutive number exists.
                    current ++;
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};