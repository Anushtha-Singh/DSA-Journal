#include <bits/stdc++.h>
using namespace std;

int climbing_stair(int n, vector<int>& dp) {
    //base condition
    if(n <= 1) return 1;

    //dp condition
    if(dp[n] != -1) return dp[n];

    //logic
    return dp[n] = climbing_stair(n - 1, dp) + climbing_stair(n - 2, dp);
}

int main() {
    int n = 6;
    vector<int> dp(n + 1, -1);
    int result = climbing_stair(n, dp);
    cout << result;
    return 0;
}