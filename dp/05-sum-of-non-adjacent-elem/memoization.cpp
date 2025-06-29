#include <bits/stdc++.h>
using namespace std;

int non_adjacent(vector<int>& vec, int index, vector<int>& dp) {
    //base condition
    if(index == 0) return vec[index];
    if(index < 0) return 0;

    //dp condition
    if(dp[index] != -1) return dp[index];

    //logic
    int left = vec[index] + non_adjacent(vec, index - 2, dp);
    int right = non_adjacent(vec, index - 1, dp);
    return dp[index]= max(left, right);
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    vector<int> dp(vec.size(), -1);
    int result = non_adjacent(vec, vec.size() - 1, dp);
    cout << result << endl;
    return 0;
}