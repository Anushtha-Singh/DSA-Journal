#include <bits/stdc++.h>
using namespace std;

int min_diff(vector<int>& vec, int target, int dummy, vector<vector<int>>& dp, int ind) {
    //base condition
    if(ind < 0) {
         return abs((target - dummy) - dummy);
    }

    //dp logic
    if(dp[ind][dummy] != -1) return dp[ind][dummy];

    //logic
    //pick
    int left = min_diff(vec, target, dummy + vec[ind], dp, ind - 1);

    //not pick
    int right = min_diff(vec, target, dummy, dp, ind - 1);

    return dp[ind][dummy] = min(left,right);
}

int main() {
    vector<int> vec = {2, 2, 3, 4};

    int target = 0;
    for(int it : vec) target += it;
    vector<vector<int>> dp(vec.size(), vector<int>(target + 1, -1));
    int mini = INT_MAX;

    int result = min_diff(vec, target, 0,dp, vec.size() - 1);
    // for(int i = 0; i < dp[0].size(); i++) {
    //     result = min(result, (target - dp[vec.size() -1][i]) - dp[vec.size() - 1][i]);
    // }

    cout << result << endl;
    return 0;
}