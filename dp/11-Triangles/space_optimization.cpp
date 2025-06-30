#include <bits/stdc++.h>
using namespace std;

int min_path(vector<vector<int>>& triangle, int n) {
    //define prev vector
    vector<int> prev(n, -1);
    for(int i = 0; i < n; i++) {
        prev[i] = triangle[n - 1][i];
    }

    for(int row = n - 2; row >= 0; row--) {
        vector<int> curr(row + 1, -1);
        for(int col = row; col >= 0; col--) {
            int down = triangle[row][col] + prev[col];
            int diagonal = triangle[row][col] + prev[col + 1];
            curr[col] = min(down, diagonal);
        }
        prev = curr;
    }
    return prev[0];
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