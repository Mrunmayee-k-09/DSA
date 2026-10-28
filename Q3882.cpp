#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(); // Rows
        int n = grid[0].size(); // Columns 

        vector<vector<unordered_set<int>>>      //An unordered_set is a collection of unique values.
           dp( m, vector<unordered_set<int>>(n)  /*
            This creates n empty sets, one for each column.
            If n = 2, we have:
            [ {}, {} ]
our example:
1  2
3  4
            */
        );

        dp[0][0].insert(grid[0][0]);  //We start at the top-left cell.

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0) {
                    continue;
                }

/*This checks whether we're at the starting cell.
If both i and j are zero, we're at (0,0).
We skip it because we've already initialized its set with:
dp[0][0].insert(grid[0][0]); We don't want to process the starting cell again as if it had a previous cell.*/

                if (i > 0) { 
                    for (auto x : dp[i - 1][j]) {
                        dp[i][j].insert(x ^ grid[i][j]);
                    }
                }

/*if (i > 0) {
This checks whether the current cell has a row above it.
For example:
- Cell (0,1) has no row above it.
- Cell (1,0) does have a row above it.
Why check this? Because we can only move down from a cell that exists above us.

for (auto x : dp[i - 1][j]) {
This loops through every XOR value stored in the set of the cell directly above.

Let's say our current cell is (1,1), whose value is 4.

The cell above it is (0,1), whose DP set is:
dp[0][1] = {3}*/

                if (j > 0) {
                    for (auto x : dp[i][j - 1]) {
                        dp[i][j].insert(x ^ grid[i][j]);
                    }
                }
            }
        }
/*if (j > 0) {
This checks whether the current cell has a column to its left.

If j == 0, we're in the first column, so there is no cell to the left.

for (auto x : dp[i][j - 1]) {
This loops through every XOR value that can reach the cell immediately to the left.

For destination (1,1), the cell to the left is (1,0).

Its DP set will be:
dp[1][0] = {2}
So x = 2


dp[i][j].insert(x ^ grid[i][j]);
THIS is the heart of your solution.

It means:
1. Take a possible XOR value from the cell above.
2. XOR it with the value of the current cell.
3. Store the new result in the current cell's set.
Previous XOR = 3
Current cell value = 4

New XOR = 3 ^ 4 = 7*/

        int ans = INT_MAX;

        for (int x : dp[m - 1][n - 1]) {
            ans = min(ans, x);
        }

        return ans;
    }
};

/*for (int x : dp[m - 1][n - 1]) {
This accesses the bottom-right cell.

Why these indices?
- m - 1 is the last row.
- n - 1 is the last column.
For our grid, both are 1.

Therefore, we iterate over:
dp[1][1] = {6, 7}*/


/*
XOR : 
Same bits → 0
Different bits → 1

3D DP(Dynamic Programming)
dp[i][j][x] - 
Is it possible to reach cell (i, j) with XOR value x? It stores true or false.

1) For every cell we have 2 possibilities to move. Down or Right. So, we have total m*n cells. So, total possibilities will be 2^(m*n).

2) The meaning of dp[i][j] is:

The set of all XOR values with which we can reach cell (i,j).

*/