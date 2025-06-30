#include <bits/stdc++.h>
using namespace std;

int min_path(vector<vector<int>>& triangle, int n, int row, int col, vector<vector<int>>& dp) {
    //base condition
    if(row == n - 1) return triangle[row][col];

    //dp condition
    if(dp[row][col] != -1) return dp[row][col];

    //logic
    int down = triangle[row][col] + min_path(triangle, n, row + 1, col, dp);
    int diagonal = triangle[row][col] + min_path(triangle, n, row + 1, col + 1, dp);
    return dp[row][col] = min(down, diagonal);
}

int main() {
    vector<vector<int>> triangle = {
        {1},
        {1, 2},
        {2, 4, 1},
        {4, 5, 1, 4}
    };

    vector<vector<int>> dp;
    //this & is referencing the row of traingle with out it they'll take copy which will take more time
    for(auto& row : triangle) {
        dp.push_back(vector<int>(row.size(), -1));
    }
    int result = min_path(triangle, triangle.size(), 0, 0, dp);
    cout << result << endl;
    return 0;
}