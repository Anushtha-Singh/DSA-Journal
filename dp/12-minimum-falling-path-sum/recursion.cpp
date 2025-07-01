#include <bits/stdc++.h>
using namespace std;

int min_falling_path(vector<vector<int>>& grid, int row, int col) {
    //base condition
    if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return 1e9;
    if(row == 0) return grid[row][col];

    //logic
    int mini = INT_MAX;
    int straight = min_falling_path(grid, row - 1, col);
    int leftDiagonal = min_falling_path(grid, row - 1, col - 1);
    int rightDiagonal = min_falling_path(grid, row - 1, col + 1);
    mini = min(mini, grid[row][col] + min(straight, min(leftDiagonal, rightDiagonal)));

    return mini;
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3, 4},
        {2, 1, 3, 4},
        {1, 2, 3, 4},
        {2 , 1, 3, 4}
    };

    int result = INT_MAX;
    for(int i = 0; i < grid[0].size(); i++) {
        result = min(result, min_falling_path(grid, grid.size() - 1, i));
    }

    cout << result << endl;
    return 0;
}