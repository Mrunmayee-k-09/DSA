#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//T.C. = O(n^2)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        

        for(int i=0; i<n; i++) {
            int minHeight = INT_MAX;
            for(int j=i; j<n; j++) {

                minHeight = min(minHeight, heights[j]);
                int width = j-i+1;

                int area = width*minHeight;
                maxArea = max(maxArea, area);
            }
            
        }
         return maxArea; 
    }
};