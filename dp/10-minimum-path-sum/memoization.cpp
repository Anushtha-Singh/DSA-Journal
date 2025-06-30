#include <bits/stdc++.h>
using namespace std;

int min_path(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp) {
    //base condition
    if(row == 0 && col == 0) return grid[row][col];
    if(row < 0 || col < 0) return INT_MAX;

    //dp condition
    if(dp[row][col] != -1) return dp[row][col];

    //logic
    int up = min_path(grid, row - 1, col, dp);
    int left = min_path(grid, row, col - 1, dp);
    return dp[row][col] = grid[row][col] +  min(up, left);
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3, 4},
        {2, 3, 3, 4},
        {3, 2, 2, 4}
    };
    
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));

    int result = min_path(grid, grid.size() - 1, grid[0].size() - 1, dp);
    cout << result << endl;
    return 0;
}