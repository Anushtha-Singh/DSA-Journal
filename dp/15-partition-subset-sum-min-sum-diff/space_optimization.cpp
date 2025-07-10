#include <bits/stdc++.h>
using namespace std;

void min_diff(vector<int>& vec, vector<int>& prev, int n, int target) {
    //define curr
    vector<int> curr(target + 1, 0);

    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= target; j++) {
             int not_taken = prev[j];
            int taken = 0;
            if(vec[i] <= j) taken = prev[j - vec[i]];
            curr[j] = not_taken || taken;
        }
        prev = curr;
    }
}

int main() {
    vector<int> vec = { 11, 2, 3, 4};

    int target = 0;
    for(int it : vec) target += it;
    vector<int> prev(target + 1, 0);
    
    prev[0] = 1;
    if(vec[0] <= target) prev[vec[0]] = 1;

    min_diff(vec, prev, vec.size(), target);

    int mini = INT_MAX;
    for(int i = 0; i < target; i++) {
        if(prev[i] == 1) {
            mini = min(mini, abs(target - 2*i));
        }
    }

    cout << mini << endl;
    return 0;
}