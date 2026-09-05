#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = m * n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / n;
            int col = mid % n;
            int val = matrix[row][col];
            
            if (val == target) {
                return true;
            } else if (val < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return false;
    }
};

/*Set low = 0, high = m*n - 1 (pretend it's one flat array).
flat index:  0   1   2   3    4    5    6    7    8    9    10   11
value:       1   3   5   7    10   11   16   20   23   30   34   60

Take flat index 6. We said 6/4 = 1, so it's in row 1. But row 1 spans indices 4,5,6,7. Index 6 is the 3rd item in 
that row (0-indexed: position 2).

6 % 4 = 2   ← and yes, index 6 is at column 2 in row 1!*/