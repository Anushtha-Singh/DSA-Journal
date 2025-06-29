#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    vector<int> dp(n + 1, -1);

    dp[0] = 0;
    dp[1] = 1;

    //here we are making i equal to n as we want 5th index not 5th position
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
    return 0;
}