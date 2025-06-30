#include <bits/stdc++.h>
using namespace std;

int paths(int n, int m) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    dp[0][0] = 1;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0 && j == 0) dp[0][0] = 1;
            else {
            int up = (i > 0) ? dp[i - 1][j] : 0;
            int left = (j > 0) ? dp[i][j - 1] : 0;
            dp[i][j] = up + left;
            }
        }
    }
    return dp[n][m];
}

int main() {
    int n = 2;
    int m = 2;
    int result = paths(n, m);
    cout << result << endl;
    return 0;
}