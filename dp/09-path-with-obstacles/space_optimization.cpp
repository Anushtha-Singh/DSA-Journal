#include <bits/stdc++.h>
using namespace std;

int findPath(vector<vector<int>>& grid, int row, int col) {
    vector<int> prev(col + 1, 0);
    prev[0] = 1;

    for(int i = 0; i <= row; i++) {
        vector<int> temp(col + 1, 0);
        for(int j = 0; j <= col; j++) {
            if(i == 0 && j == 0) temp[j] = 1;
            else if(grid[i][j] == -1) temp[j] = 0;
            else {
                int up = (i > 0) ? prev[j] : 0;
                int left = (j > 0) ? temp[j - 1] : 0;
                temp[j] = up + left;
            }
        }
        prev = temp;
    }
    return prev[col];
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