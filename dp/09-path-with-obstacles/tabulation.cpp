#include <bits/stdc++.h>
using namespace std;

int findPath(vector<vector<int>>& grid, int row, int col) {
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, -1));

    dp[0][0] = 1;

    for(int i = 0; i <= row; i++) {
        for(int j = 0; j <= col; j++) {
            if(i == 0 && j == 0) dp[i][j] = 1;
            else if(grid[i][j] == -1) dp[i][j] = 0;
            else {
                int up = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;
                dp[i][j] = up + left;
            }
        }
    }
    return dp[row][col];
}

int main() {
    vector<vector<int>> grid = {
        {0, -1, -1, 0},
        {0, 0, -1, -1},
        {0, 0, 0, 0}
    };

    int result = findPath(grid, grid.size() - 1, grid[0].size() - 1);
    cout << result << endl;
    return 0;
}