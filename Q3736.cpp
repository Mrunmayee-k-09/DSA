#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maximum = *max_element(nums.begin(), nums.end()); //This gives us the largest number in the array.

        int moves = 0;

        for(int i = 0; i < nums.size(); i++) {
        moves += maximum - nums[i];
}
return moves;
    }
};