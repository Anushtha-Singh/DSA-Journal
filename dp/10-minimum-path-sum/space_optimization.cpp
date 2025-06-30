#include <bits/stdc++.h>
using namespace std;

int min_path(vector<vector<int>>& grid, int row, int col) {
    vector<int> prev(col + 1, 0);
    prev[0] = grid[0][0];

    for(int i = 0; i <= row; i++) {
        vector<int> temp(col + 1, 0);
        for(int j = 0; j <= col; j++) {
            if(i == 0 && j == 0) temp[0] = grid[i][j];
            else{
                int up = (i > 0) ? prev[j] : INT_MAX;
                int left = (j > 0) ? temp[j - 1] : INT_MAX;
                temp[j] = grid[i][j] + min(up, left);
            }
        }
        prev = temp;
    }
    return prev[col];
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