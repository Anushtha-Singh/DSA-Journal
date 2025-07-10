#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec = { 11, 2, 3, 4};

    int target = 0;
    for(int it : vec) {
        target += it;
    }
    vector<vector<int>> dp(vec.size(), vector<int>(target + 1, 0));

    for(int i = 0; i < vec.size(); i++) dp[i][0] = 1;
    if(vec[0] <= target) dp[0][vec[0]] = 1;

    for(int i = 1; i < vec.size(); i++) {
        for(int j = 1; j < target; j++) {
            int not_taken = dp[i - 1][j];
            int taken = 0;
            if(vec[i] <= j) {
                taken = dp[i - 1][j - vec[i]];
            }

            dp[i][j] = taken || not_taken;
        }
    }

    int mini = INT_MAX;
    for(int i = 0; i  < target; i++) {
        if(dp[vec.size() - 1][i] == 1) {
            mini = min(mini, abs(target - 2*i));
        }
    }

    cout << mini << endl;
    return 0;
}