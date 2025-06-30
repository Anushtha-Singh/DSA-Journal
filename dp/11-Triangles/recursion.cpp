//triangle with minimum path sum
#include <bits/stdc++.h>
using namespace std;

int min_path(vector<vector<int>>& triangle, int n, int row, int col) {
    //base condition
    if(row == n - 1) return triangle[row][col];

    //we can either go down or diagonal right
    //in diagonal there is always gonna be an element until we reach n - 1 row for which we already wrote the condition

    //logic
    int down = triangle[row][col] + min_path(triangle, n, row + 1, col);
    int diagonal = triangle[row][col] + min_path(triangle, n, row + 1, col + 1);
    return min(down, diagonal);
}

int main() {
    vector<vector<int>> triangle = {
        {1},
        {1, 2},
        {2, 4, 1},
        {2, 5, 1, 4}
    };

    int result = min_path(triangle, triangle.size(), 0, 0);
    cout << result << endl;
    return 0;
}