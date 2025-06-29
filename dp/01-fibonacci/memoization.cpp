#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n, vector<int>& dp) {
    //base condition
    if(n <= 1) return n;

    //dp condition
    if(dp[n] != -1) return dp[n];

    //logic
    return dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
}

int main() {
    int n = 5;
    vector<int> dp(n + 1, -1);

    int result = fibonacci(n, dp);
    cout << result << endl;
    return 0;
}