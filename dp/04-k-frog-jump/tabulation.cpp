#include <bits/stdc++.h>
using namespace std;

int k_frogJump(vector<int>& energy, int k, int n) {
    vector<int> dp(n + 1, -1);

    dp[0] = 0;   
    for(int i = 1; i <= n; i++) {
        int mini = INT_MAX;
        for(int j = 1; j <= k; j++) {
            if(i - j >= 0) {
                int curr = dp[i - j] + abs(energy[i] - energy[i - j]);
                mini = min(mini, curr);
            }
        }
        dp[i] = mini;
    }
    return dp[n];
}

int main() {
    vector<int> energy = { 1, 2, 3, 2, 5};
    int k = 4;
    int result = k_frogJump(energy, k, energy.size() - 1);
    cout << result << endl;
    return 0;
}