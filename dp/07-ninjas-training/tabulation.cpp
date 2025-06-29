#include <bits/stdc++.h>
using namespace std;

int training(vector<vector<int>>& points, int n) {
    vector<vector<int>> dp(points.size() , vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int dayNo = 1; dayNo < n; dayNo++) {
        for(int last = 0; last < 4; last++) {
            dp[dayNo][last] = 0;
            for(int task = 0; task < 3; task++) {
                if(task != last) {
                int point = points[dayNo][task] + dp[dayNo - 1][task];
                 dp[dayNo][last] = max(dp[dayNo][last], point);
            }
            }
        }
    }
    return dp[n - 1][3];
}

int main() {
    vector<vector<int>> points = {
        {1, 2, 3},
        {4 ,3, 6},
        {2, 4, 4},
    };

    int result = training(points, points.size());
    cout << result << endl;
    return 0;
}