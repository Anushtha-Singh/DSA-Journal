#include <bits/stdc++.h>
using namespace std;

int min_path(vector<vector<int>>& grid, int row, int col) {
    //define dp
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, -1));
    dp[0][0] = grid[0][0];

    for(int i = 0; i <= row; i++) {
        for(int j = 0; j <= col; j++) {
            if(i == 0 && j == 0)  dp[i][j] = grid[i][j];
            else {
                int up = (i > 0) ? dp[i - 1][j] : INT_MAX;
                int left = ( j > 0 ) ? dp[i][j - 1] : INT_MAX;
                dp[i][j] = grid[i][j] + min(up, left);
            }
        }
    }
    return dp[row][col];
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3, 4},
        {2, 3, 3, 4},
        {3, 2, 2, 4}
    };

    int result = min_path(grid, grid.size() - 1, grid[0].size() - 1);
    cout << result << endl;
    return 0;
}