#include <bits/stdc++.h>
using namespace std;

bool subsequence(vector<int>& vec, int target, int index) {
    //base condition
    if(target == 0) return true;
    if(index == 0) return target == vec[index];

    //logic
    //pick
    if(target >= vec[index]) {
    if(subsequence(vec, target - vec[index], index - 1)) return true;
    }
    //not pick
    if(subsequence(vec, target, index - 1)) return true;

    return false;
}

int main() {
    vector<int> vec = { 1, 2, 3, 4, 5 };
    int target = 5;

    if(subsequence(vec, target, vec.size() - 1)) {
        cout << true << endl;
    }
    else cout << false << endl;
    return 0;
}