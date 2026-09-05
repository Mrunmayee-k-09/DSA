#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j] == target ) {
                    return true;
                }
            }

        }
        return false;
    }
};

//matrix[0] → gives you the first row
//matrix.size() → gives you the number of rows

//matrix[0].size() → gives you the number of columns (how many elements are in that first row).
/*matrix[0].size() is not about "going to row 0"

It's not saying "look at row 0's data." It's saying "ask row 0 how long it is." We're using row 0 purely as 
a ruler — since every row has the same length in this problem, we can check any one row to find out the column 
count. matrix[0] is just the easiest/first one to grab.

If you wrote matrix[1].size() or matrix[2].size() instead, you'd get the exact same number (4, in our example) — 
because all rows are equal length. So it doesn't matter which row you peek at for the size. [0] is just 
convention (first thing, easiest to reach).*/