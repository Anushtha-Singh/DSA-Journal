//combination I

#include <bits/stdc++.h>
using namespace std;

void combination_I(vector<int>& vec, vector<int>& dummy, vector<vector<int>>& answer, int target, int index, int n) {
    //base condition
    if(index > n) {
        if(target == 0) {
            answer.push_back(dummy);
        }
        return;
    }

    //logic
    //pick
    if(target >= vec[index]) {
    dummy.push_back(vec[index]);
    combination_I(vec, dummy, answer, target - vec[index], index, n);
    
    //not-pick
    dummy.pop_back();
    }

    combination_I(vec, dummy, answer, target, index + 1, n);
}

int main() {
    vector<int> vec = {1 , 2, 3, 4, 5};
    int target = 9;
    vector<vector<int>> answer;
    vector<int> dummy;

    combination_I(vec, dummy, answer, target, 0, vec.size() - 1);
    for(auto it : answer) {
        for(int num : it) {
        cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}