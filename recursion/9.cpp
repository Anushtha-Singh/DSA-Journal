#include <bits/stdc++.h>
using namespace std;

void print(vector<int> answer) {
    for(int it : answer) {
        cout << it << " ";
    }
    cout << endl;
}

void subsequence_k(vector<int> vec, int target, vector<int>& answer, int n, int index) {
    //base conditions
    if(index > n - 1) {
        if(target == 0) {
        print(answer);
        }
        return;
    }

    if(target < 0) return;

    //logic
    //pick
    answer.push_back(vec[index]);
    subsequence_k(vec, target - vec[index], answer, n, index + 1);

    //not-pick
    answer.pop_back();
    subsequence_k(vec, target, answer, n, index + 1);
}

int main() {
    vector<int> vec = { 1, 2, 3, 4, 5};
    int target = 9;
    vector<int> answer;

    subsequence_k(vec, target, answer, vec.size(), 0);
    return 0;
}