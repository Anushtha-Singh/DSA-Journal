#include <bits/stdc++.h>
using namespace std;

int training(vector<vector<int>>& points, int n) {
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day = 1; day < n; day++) {
        vector<int> temp(4, 0);
        for(int last = 0; last < 4; last++) {
            for(int task = 0; task < 3; task++) {
                if(task != last) {
                    int point = points[day][task] + prev[task];
                    temp[last] = max(temp[last], point);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
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