#include <bits/stdc++.h>
using namespace std;

bool subsequence(vector<int>& vec, int target, int index, vector<vector<int>>& dp) {
    //base condition
    if(target == 0) return true;
    if(index == 0) return target == vec[index];

    //dp logic
    if(dp[index][target] != -1) return dp[index][target];

    //logic
    //pick
    bool pick = false;
    if(target >= vec[index]) {
    pick = subsequence(vec, target - vec[index], index - 1, dp);
    }
    //not pick
    bool not_pick = subsequence(vec, target, index - 1, dp);

    return dp[index][target] = pick || not_pick;
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    int target = 5;
    vector<vector<int>> dp(vec.size(), vector<int>(target + 1, -1));

    if(subsequence(vec, target, vec.size() - 1, dp)) cout << true << endl;
    else cout << false << endl;
    return 0;
}