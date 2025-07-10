#include <bits/stdc++.h>
using namespace std;

int subset(vector<int>& vec, int target, int n) {
    //define dp
    vector<vector<int>> dp(n, vector<int>(target+ 1, 0));

    for(int i = 0; i < n; i++) dp[i][0] = 1;
    if(vec[0] <= target) dp[0][vec[0]] = 1;

    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= target; j++) {
            int not_taken = dp[i - 1][j];
            int taken = 0;
            if(vec[i] <= j) {
                taken = dp[i - 1][j - vec[i]];
            }

            dp[i][j] = taken + not_taken;
        }
    }
    return dp[n - 1][target];
}

int main() {
    vector<int> vec = {1, 2, 3, 4};
    int target = 5;

    int result = subset(vec, target, vec.size());
    cout << result << endl;
    return 0;
}