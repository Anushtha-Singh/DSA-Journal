#include <bits/stdc++.h>
using namespace std;

int min_path(vector<vector<int>>& triangle, int n) {
    //define dp
    vector<vector<int>> dp;
    for(auto& r : triangle) {
        dp.push_back(vector<int>(r.size(), -1));
    }
    for(int i = 0; i < n; i++) {
        dp[n - 1][i] = (triangle[n - 1][i]);
    }

    //logic
    for(int row = n - 2; row >= 0; row--) {
        for(int col = row; col >= 0; col--) {
            int down = triangle[row][col] + dp[row + 1][col];
            int diagonal = triangle[row][col] + dp[row + 1][col + 1];
            dp[row][col] = min(down, diagonal);
        }
    }
    return dp[0][0];
}

int main() {
    vector<vector<int>> triangle = {
        {1},
        {1, 2},
        {2, 4, 1},
        {4, 5, 1, 4}
    };

    int result = min_path(triangle, triangle.size());
    cout << result << endl;
    return 0;
}