#include <bits/stdc++.h>
using namespace std;

int training(vector<vector<int>>& points, int day, int last) {
    vector<vector<int>> dp(points.size() , vector<int>(4, -1));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][1]);
    dp[0][2] = max(points[0][0], points[0][2]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int dayNo = 1; dayNo <= day; dayNo++) {
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
    return dp[day][3];
}

int main() {
    vector<vector<int>> points = {
        {1, 2, 3},
        {4 ,3, 6},
        {2, 4, 4},
    };

    int result = training(points, points.size() - 1, points[0].size());
    cout << result << endl;
    return 0;
}