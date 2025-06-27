#include <bits/stdc++.h>
using namespace std;

int number_of_subsequences(vector<int>& vec, vector<int>& dummy, int target, int n, int index) {
    //base condition
    if(index > n - 1) {
        if(target == 0) return 1; 
        return 0;
    }

    //logic
    //pick
    dummy.push_back(vec[index]);
    int pick = number_of_subsequences(vec, dummy, target - vec[index], n, index + 1);

    //not-pick
    dummy.pop_back();
    int not_pick = number_of_subsequences(vec, dummy, target, n, index + 1);
    return (pick + not_pick);
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    int target = 5;
    vector<int> dummy;

    int answer = number_of_subsequences(vec, dummy, target, vec.size(), 0);
    cout << answer;
    return 0;
}