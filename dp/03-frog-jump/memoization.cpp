#include <bits/stdc++.h>
using namespace std;

int frogJump(vector<int>& energy, vector<int>& dp, int n) {
    //base condition
    if(n == 0) return 0;

    //dp condition
    if(dp[n] != -1) return dp[n];

    //logic
    int left = frogJump(energy, dp, n - 1) + abs(energy[n] - energy[n - 1]);
    int right = INT_MAX;
    if(n > 1) {
        right = frogJump(energy, dp, n - 2) + abs(energy[n] - energy[n - 2]);
    }
    return dp[n] = min(left, right);
}

int main() {
    vector<int> energy = {1, 3, 6, 3, 2, 1};
    vector<int> dp(energy.size() + 1, -1);
    int result = frogJump(energy, dp, energy.size() - 1);
    cout << result << endl;
    return 0;
}