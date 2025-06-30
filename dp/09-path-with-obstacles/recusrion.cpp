#include <bits/stdc++.h>
using namespace std;

int findPath(vector<vector<int>>& grid, int row, int col) {
    //base condition
    if(row == 0 && col == 0) return 1;
    if(row < 0 || col < 0 || grid[row][col] == -1) return 0;

    //logic
    return findPath(grid, row - 1, col) + findPath(grid, row, col - 1);
}

int main() {
    vector<vector<int>> grid = {
        {0, -1, -1, 0},
        {0, 0, 0, -1},
        {0, 0, 0, 0}
    };

    int result = findPath(grid, grid.size() - 1, grid[0].size() - 1);
    cout << result << endl;
    return 0;
}