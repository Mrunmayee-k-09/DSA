#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int m, n;

    int dfs(int r, int c, vector<vector<int>>& grid) {
        // Base case: outside grid or water/visited
        if (r < 0 || c < 0 || r >= m || c >= n ||
            grid[r][c] == 0) {
            return 0;
        }

        // Save current cell's value
        int value = grid[r][c];

        // Mark this cell as visited
        grid[r][c] = 0;

        // Add the values of all connected land cells
        int sum = value;
        sum += dfs(r - 1, c, grid);
        sum += dfs(r + 1, c, grid);
        sum += dfs(r, c - 1, grid);
        sum += dfs(r, c + 1, grid);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] != 0) {
                    int islandSum = dfs(r, c, grid);

                    if (islandSum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};

//When we find an unvisited land cell, we explore all connected land cells. This is exactly what DFS (Depth-First Search)
// How to Avoid visiting the same cell again?
/*
Imagine DFS starts at 1, moves to 2, then moves back towards 1. Without a way to track visited cells, it could keep revisiting the same cells forever.

One simple technique is to mark a cell as visited by changing its value to 0 after saving its original value.
int value = grid[r][c];
grid[r][c] = 0;
Explore the four directions
From any cell, an island can continue:
- Up: (r - 1, c)
- Down: (r + 1, c)
- Left: (r, c - 1)
- Right: (r, c + 1)
So the DFS function adds the current cell's value to the sums returned by its four neighbours.*/