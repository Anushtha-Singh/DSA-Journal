#include <bits/stdc++.h>
using namespace std;

int training(vector<vector<int>>& points, int day, int last, vector<vector<int>>& dp) {
    //base condition
    if(day == 0) {
        int maxi = 0;
        for(int i = 0; i < 3; i++) {
            if(i != last) {
                maxi = max(maxi, points[day][i]);
            }
        }
        return maxi;
    }

    //dp condition
    if(dp[day][last] != -1) return dp[day][last];

    //logic
    int maxi = 0;
    for(int i = 0; i < 3; i++) {
        if(i != last) {
            int point = points[day][i] + training(points, day - 1, i, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;;
}

int main() {
    vector<vector<int>> points = {
        {1, 2, 3},
        {4, 3, 6},
        {2, 4, 4}
    };

    vector<vector<int>> dp(points.size(), vector<int>(4 , -1));
    int result = training(points, points.size() - 1, points[0].size(), dp);
    cout << result << endl;
    return 0;
}