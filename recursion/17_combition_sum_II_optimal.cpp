//combination sum optimal
#include <bits/stdc++.h>
using namespace std;

void combination_II(vector<int>& vec, vector<int>& dummy, vector<vector<int>>& answer, int target, int index, int n) {
    //base condition
    if(target == 0) {
        answer.push_back(dummy);
        return;
    }

    //logic
    //using itrator
    for(int i = index; i < n; i++) {
        if(i > index && vec[i] == vec[i - 1]) continue;
        if(vec[i] > target) break;

            dummy.push_back(vec[i]);
            combination_II(vec, dummy, answer, target - vec[i], i + 1, n);
            dummy.pop_back();
    }
}

int main() {
    vector<int> vec = { 1, 2, 3, 4, 5};
    int target = 9;
    vector<int> dummy;
    vector<vector<int>> answer;
    sort(vec.begin(), vec.end());
    combination_II(vec, dummy, answer, target, 0, vec.size());

    for(auto it : answer) {
        for(int elem : it) {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 1;
}