#include <bits/stdc++.h>
using namespace std;

int min_path_sum(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp) {
    //base condition
    if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return 1e9;
    if(row == 0) return grid[row][col];

    //dp condition
    if(dp[row][col] != -1) return dp[row][col];

    //logic
    int straight = min_path_sum(grid, row - 1, col, dp);
    int leftDiagonal = min_path_sum(grid, row - 1, col - 1, dp);
    int rightDiagonal = min_path_sum(grid, row - 1, col + 1, dp);

    return dp[row][col] = grid[row][col] + min(straight, min(leftDiagonal, rightDiagonal));
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3, 4},
        {2, 1, 3, 4},
        {1, 2, 3, 4},
        {2 , 1, 3, 4}
    };

    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
    int result = INT_MAX;
    for(int i = 0; i < grid[0].size(); i++) {
        result = min(result, min_path_sum(grid, grid.size() - 1, i, dp));
    };

    cout << result << endl;
    return 0;
}