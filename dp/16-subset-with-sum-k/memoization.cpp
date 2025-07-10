#include <bits/stdc++.h>
using namespace std;

int subset(vector<int>& vec, int target, vector<vector<int>>& dp, int ind) {
    //base condition
    if(ind == 0) {
        if(target == 0 && vec[0] == 0) return 2;
        if(target == 0 || vec[0] == target) return 1;
        return 0;
    }

    //dp logic
    if(dp[ind][target] != -1) return dp[ind][target];

    //logic
    //pick
    int pick = 0;
    if(vec[ind] <= target) {
        pick = subset(vec, target - vec[ind], dp, ind - 1);
    }

    //not pick
    int not_pick = subset(vec, target, dp, ind - 1);

    return dp[ind][target] = pick + not_pick;
}

int main() {
    vector<int> vec = {3, 2, 3, 4};
    int target = 5;

    int n = vec.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    int result = subset(vec, target, dp, n - 1);
    cout << result << endl;
    return 0;
}