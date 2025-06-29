#include <bits/stdc++.h>
using namespace std;

int frogJump(vector<int>& energy, int n) {
    vector<int> dp(n + 1, -1);

    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        int left = dp[i - 1] + abs(energy[i] - energy[i - 1]);
        int right = INT_MAX;
        if(i > 1) {
            right = dp[i - 2] + abs(energy[i] - energy[i - 2]);
        }
        dp[i] = min(left, right);
    }
    return dp[n];
}

int main() {
    vector<int> energy = {1, 2, 3, 4, 1};
    int result = frogJump(energy, energy.size() - 1);
    cout << result << endl;
    return 0;
}