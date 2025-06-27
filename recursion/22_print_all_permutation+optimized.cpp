#include <bits/stdc++.h>
using namespace std;

//optimized with out the use of storing the permutation temperary and without need to storing the visited status of elements
void print_all_permutation(vector<int>& vec, vector<vector<int>>& answer, int index, int n) {
    //base condition
    if(index >= n) {
        answer.push_back(vec);
        return;
    }

    //logic
    //iterate and swap
    for(int i = index; i < n; i++) {
        swap(vec[i], vec[index]);
        print_all_permutation(vec, answer, index + 1, n);
        swap(vec[i], vec[index]);
    }
}

int main() {
    vector<int> vec = {1, 2, 3};
    vector<vector<int>> answer;

    print_all_permutation(vec, answer, 0, vec.size());

    for(int i = 0; i < answer.size(); i++) {
        for(int j = 0; j < vec.size(); j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    return 1;
}