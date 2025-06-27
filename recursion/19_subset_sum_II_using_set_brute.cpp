#include <bits/stdc++.h>
using namespace std;

void subset_sum(set<vector<int>> dummy, vector<int>& answer, int sum, int index, int n) {
    for(auto it : dummy) {
        sum = 0;
        for(int elem : it) {
            sum += elem;
        }
        answer.push_back(sum);
    }
}


void subset(vector<int>& vec, set<vector<int>>& dummy, vector<int>& answer, int index, int n) {
    //base condition
    if(index > n) {
        dummy.insert(answer);
        return;
    }

    //logic
    //pick
    answer.push_back(vec[index]);
    subset(vec, dummy, answer, index + 1, n);

    //not-pick
    answer.pop_back();
    subset(vec, dummy, answer, index + 1, n);
}

int main() {
    vector<int> vec = { 1, 2, 3, 4, 5};
    set<vector<int>> dummy;
    vector<int> answer;
    int sum = 0;

    subset(vec, dummy, answer, 0, vec.size() - 1);
    answer = {};
    subset_sum(dummy, answer, sum, 0, vec.size() - 1);
    sort(answer.begin(), answer.end());

    for(int it : answer) {
        cout << it << " ";
    }
    cout << endl;
    return 1;
}