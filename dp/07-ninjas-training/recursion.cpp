#include <bits/stdc++.h>
using namespace std;

int training(vector<vector<int>>& points, int day, int last) {
    //base condition
    int maxi = 0;
    if(day == 0) {
        for(int i = 0; i < 3; i++) {
            if(i != last) {
                maxi = max(maxi, points[day][i]);
            }
        }
        return maxi;
    }

    //logic
    maxi = 0;
    for(int i = 0; i < 3; i++) {
        if(i != last) {
            int point = points[day][i] + training(points, day - 1, i);
            maxi = max(maxi, point);
        }
    }
    return maxi;
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