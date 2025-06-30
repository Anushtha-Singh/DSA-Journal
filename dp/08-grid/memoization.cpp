#include <bits/stdc++.h>
using namespace std;

int paths(int row, int col, vector<vector<int>>& dp) {
    //base condition
    if(row == 0 && col == 0) return 1;
    if(row < 0 || col < 0) return 0;

    //dp condition
    if(dp[row][col] != -1) return dp[row][col];
    //logic
    return dp[row][col] = paths(row - 1, col, dp) + paths(row, col - 1, dp);
}

int main() {
    int n = 2;
    int m = 2;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, - 1));

    int result = paths(n, m, dp);
    cout << result << endl;
    return 0;
}