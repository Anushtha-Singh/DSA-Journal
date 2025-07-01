#include <bits/stdc++.h>
using namespace std;

bool sequence(vector<int>& vec, int target) {
    //define dp
    vector<vector<int>> dp(vec.size(), vector<int>(target + 1, 0));

    //initialize the first row of this dp
    //base cases
    for(int i = 0; i < vec.size(); i++) dp[i][0] = 1;
    if(vec[0] <= target) dp[0][vec[0]] = 1;

    //logic
    for(int i = 1; i < vec.size(); i++) {
        for(int j = 0; j <= target; j++) {
            bool not_take = dp[i - 1][j];
            bool take = false;
            if(vec[i] <= j) {
                take = dp[i - 1][j - vec[i]];
            }
            dp[i][j] = take || not_take;
        }
    }
    return dp[vec.size() - 1][target];
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5}; 
    int target = 5;
    if(sequence(vec, target)) cout << true << endl;
    else cout << false << endl;
    return 0;
}