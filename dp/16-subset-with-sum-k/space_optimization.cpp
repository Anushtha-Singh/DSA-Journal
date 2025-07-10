#include <bits/stdc++.h>
using namespace std;

int subset(vector<int>& vec, int target, int n) {
    //define prev
    vector<int> prev(target + 1, 0);

    prev[0] = 1;
    if(vec[0] <= target) prev[vec[0]] = 1;

    for(int i = 1; i < n; i++) {
        for(int j = target; j >= 0; j--) {
            int not_taken = prev[j];
            int taken = 0;
            if(vec[i] <= j) taken = prev[j - vec[i]];
            prev[j] = taken + not_taken;
        }
    }
    return prev[target];
}

int main() {
    vector<int> vec = {1, 2, 3, 4};
    int target = 5;

    int result = subset(vec, target, vec.size());
    cout << result << endl;
    return 0;
}