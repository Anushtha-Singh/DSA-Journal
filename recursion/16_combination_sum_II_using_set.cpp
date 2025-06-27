//combination II
#include <bits/stdc++.h>
using namespace std;

void combination_II(vector<int>& vec, vector<int>& dummy, set<vector<int>>& answer, int target, int index, int n) {
    //base condition
    if(index > n) {
        if(target == 0) {
            answer.insert(dummy);
        }
        return;
    }

    //logic
    //pick
    if(target >= vec[index]) {
        dummy.push_back(vec[index]);
        combination_II(vec, dummy, answer, target - vec[index], index + 1, n);
        dummy.pop_back();
    }

    //non-pick
    combination_II(vec, dummy, answer, target, index + 1, n);
}

int main() {
    vector<int> vec = { 1, 2, 3, 4, 5};
    int target = 9;

    vector<int> dummy;
    set<vector<int>> answer;

    combination_II(vec, dummy, answer, target, 0, vec.size() - 1);

    for(auto i = answer.begin(); i != answer.end(); i++) {
        for(int num : *i) {
            cout << num << " ";
        }
        cout << endl;
    }
}