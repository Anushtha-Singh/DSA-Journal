#include <bits/stdc++.h>
using namespace std;

void subset_sum_I(vector<int>& vec, vector<int>& answer, int sum, int index, int n) {
    //base condition
    if(index > n) {
        answer.push_back(sum);
        return;
    }

    //logic
    //pick
    sum += vec[index];
    subset_sum_I(vec, answer, sum, index + 1, n);

    //not-pick
    sum -= vec[index];
    subset_sum_I(vec, answer, sum, index + 1, n);
}

int main() {
    vector<int> vec = {1, 2, 3};
    vector<int> answer;
    int sum = 0;

    subset_sum_I(vec, answer, sum, 0, vec.size() - 1);
    sort(answer.begin(), answer.end());
    for(int it : answer) {
        cout << it << " ";
    }
    cout << endl;

    return 1;
}