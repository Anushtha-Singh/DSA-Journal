#include <bits/stdc++.h>
using namespace std;

bool subsequence_k(vector<int> vec, vector<int>& result, int target, int n, int index) {
    //base condition
    if(index > n - 1) {
        if(target == 0) return true;
        return false;
    }

    //logic
    //pick
    result.push_back(vec[index]);
    if(subsequence_k(vec, result, target - vec[index], n, index + 1)) return true;

    //not-pick
    result.pop_back();
    if(subsequence_k(vec, result, target, n, index + 1)) return true;
    return false;
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    int target = 5;
    vector<int> result;

    subsequence_k(vec, result, target, vec.size(), 0);

    for(int it : result) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}