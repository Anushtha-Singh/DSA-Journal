#include <bits/stdc++.h>
using namespace std;

int subset(vector<int>& vec, int target, int ind) {
    //base condition
    if(ind == 0) {
        if(target == 0 && vec[0] == 0) return 2;
        if(target == 0 || vec[0] == target) return 1;
        return 0;
    }

    //logic
    //pick
    int left = 0;
    if(vec[ind] <= target) {
        left = subset(vec, target - vec[ind], ind - 1);
    }

    //not pick
    int right = subset(vec, target, ind - 1);

    return left + right;
}

int main() {
    vector<int> vec = {1, 2, 3, 4};
    int target = 5;

    int result = subset(vec, target, vec.size() - 1);
    cout << result << endl;
    return 0;
}