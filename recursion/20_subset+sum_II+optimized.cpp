#include <bits/stdc++.h>
using namespace std;

void subset_sum_II(vector<int>& vec, vector<int>& answer, int sum, int index, int n) {
    //base condition
        answer.push_back(sum);

    //logic
    for(int i = index; i < n; i++) {
        if(i > index && vec[i] == vec[i - 1]) continue;

        sum += vec[i];
        subset_sum_II(vec, answer, sum, i + 1, n);
        sum -= vec[i];
    }
}

int main() {
    vector<int> vec = {1, 2, 3};
    vector<int> answer;
    int sum = 0;

    subset_sum_II(vec, answer, sum, 0, vec.size());
    sort(answer.begin(), answer.end());

    for(int it : answer) {
        cout << it << " ";
    }
    cout << endl;
    return 1;
}