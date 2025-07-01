#include <bits/stdc++.h>
using namespace std;

int min_path_sum(vector<vector<int>>& grid) {
    //define dp
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));

    for(int i = 0; i < grid[0].size(); i++) {
        dp[0][i] = grid[0][i];
    }

    for(int i = 1; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            int straight = dp[i - 1][j];
            int leftDiagonal = 1e9;
            int RightDiagonal = 1e9;
            if(j > 0) leftDiagonal = dp[i - 1][j - 1];
            if(j < grid[0].size() - 1) RightDiagonal = dp[i - 1][j + 1];
            dp[i][j] = grid[i][j] + min(straight, min(leftDiagonal, RightDiagonal)); 
        }
    }

    int mini = INT_MAX;
    for(int it : dp[grid.size() - 1]) {
        mini = min(mini, it);
    }
    return mini;
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3, 4},
        {2, 1, 3, 4},
        {1, 2, 3, 4},
        {2 , 1, 3, 4}
    };

    int result = min_path_sum(grid);
    cout << result << endl;
    return 0;
}