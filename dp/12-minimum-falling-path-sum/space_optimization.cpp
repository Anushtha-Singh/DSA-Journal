#include <bits/stdc++.h>
using namespace std;

int min_path_sum(vector<vector<int>>& grid) {
    //define the prev
    vector<int> prev(grid[0].size(), -1);
    vector<int> curr(grid[0].size(), -1);

    for(int i = 0; i < grid[0].size(); i++) {
        prev[i] = grid[0][i];
    }

    for(int i = 1; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            int straight = prev[j];
            int leftDiagonal = 1e9;
            int rightDiagonal = 1e9;
            if(j > 0) leftDiagonal = prev[j - 1];
            if(j < grid[0].size() - 1) rightDiagonal = prev[j + 1];
            curr[j] = grid[i][j] + min(straight, min(leftDiagonal, rightDiagonal));
        }
        prev = curr;
    }

    int mini = INT_MAX;
    for(int it : prev) {
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