#include <bits/stdc++.h>
using namespace std;

int min_diff(vector<int>& vec, int ind, int& result, int target, int sum) {
    //base condition
    if(ind < 0) {
        return min(result, abs((target - sum) - sum));
    }

    //logic
    //pick
    int left = min_diff(vec, ind - 1, result, target, sum + vec[ind]);

    //not pick
    int right = min_diff(vec, ind - 1, result, target, sum);
    return min(left, right);
}

int main() {
    vector<int> vec = {1, 2, 3, 4};
    int target = 0;
    for(int it  : vec) {
        target += it;
    }

    int result = min_diff(vec, vec.size() - 1, result, target, 0);

    cout << result << endl;
    return 0;
}