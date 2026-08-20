#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        for(int i=0; i<height.size(); i++) {
            for(int j=i+1; j<height.size(); j++) {
                int w = j-i; // width

                int h = min(height[i], height[j]);  // Height
                int currWater = w*h;

                maxWater = max(maxWater, currWater);
            }
        } 
        return maxWater;
    }
};