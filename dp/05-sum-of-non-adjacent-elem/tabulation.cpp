#include <bits/stdc++.h>
using namespace std;

int non_adjacent(vector<int>& vec, int n) {
    vector<int> dp(n + 1, -1);

    dp[0] = vec[0];
    for(int i = 1; i <= n; i++) {
        int left = vec[i];
        if(i > 1) {
        left += dp[i - 2];
        }
        int right = dp[i - 1];

        dp[i] = max(left, right);
    }
    return dp[n];
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    int result = non_adjacent(vec, vec.size() - 1);
    cout << result << endl;
    return 0;
}