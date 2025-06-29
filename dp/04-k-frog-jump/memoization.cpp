#include <bits/stdc++.h>
using namespace std;

int k_frogJump(vector<int>& energy, vector<int>& dp, int n, int k) {
    //base condition
    if(n == 0) return 0;

    //dp condition
    if(dp[n] != -1) return dp[n];

    //logic
    int mini = INT_MAX;
    for(int i = 1; i <= k; i++) {
        if(n - i >= 0) {
            int curr = k_frogJump(energy, dp, n - i, k) + abs(energy[n] - energy[n - i]);
            mini = min(mini, curr);
        }
    }
    dp[n] = mini;
    return dp[n];
}

int main() {
    vector<int> energy = {1, 2, 3, 2, 5};
    int k = 4;
    vector<int> dp(energy.size(), -1);
    int result = k_frogJump(energy, dp, energy.size() - 1, k);
    cout << result << endl;
    return 0;
}