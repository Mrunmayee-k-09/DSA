#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>grid(m, string(n, '#'));  // This creates a grid with m rows and n columns, initially filled with '#'

        grid[0] = string(n, '.');
        for(int i=0; i<m; i++) {
            grid[i][n-1] = '.';

        }
        return grid;
    }
};

/* Step 1:
- Zero paths → You can't reach the destination.
- Two or more paths → There are multiple ways to reach it.
- Exactly one path → There is only one valid way to reach it.

Step 2: What do . and # mean?
- . means the cell is free. You can move through it.
- # means there's an obstacle. You cannot move through it.


A simple strategy is:
- Initially fill every cell with #.
- Make the entire first row '.'.
- Make the entire last column '.'.
This creates one continuous route: right across the top, then down along the right edge. All other routes are blocked.*/
