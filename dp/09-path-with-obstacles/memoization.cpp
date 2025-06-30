#include <bits/stdc++.h>
using namespace std;

int findPath(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp) {
    //base condition
    if(row == 0 && col == 0) return 1;
    if(row < 0 || col < 0 || grid[row][col] == -1) return 0;

    //dp condition
    if(dp[row][col] != -1) return dp[row][col];

    //logic
    return dp[row][col] = findPath(grid, row - 1, col, dp) + findPath(grid, row, col - 1, dp);
}

int main() {
    vector<vector<int>> grid = {
        {0, -1, -1, 0},
        {0, 0, -1, -1},
        {0, 0, 0, 0}
    };

    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));

    int result = findPath(grid, grid.size() - 1, grid[0].size() - 1, dp);
    cout << result << endl;
    return result;
}