//not optimal with vis. vector and dummy vector
#include <bits/stdc++.h>
using namespace std;

void print_all_permutation(vector<int> vec, vector<int>& dummy, vector<vector<int>>& answer, vector<int>& vis, int index, int n) {
    //base condition
    if(index >= n) {
        answer.push_back(dummy);
        return;
    }

    //logic
    //iterator
    for(int i = 0; i < n; i++) {
        if(vis[i] == 0) {
            vis[i] = 1;
            dummy.push_back(vec[i]);
            print_all_permutation(vec, dummy, answer, vis, index + 1, n);
            vis[i] = 0;
            dummy.pop_back();
        }
    }
}

int main() {
    vector<int> vec = { 1, 2, 3 };
    vector<int> dummy;
    vector<int> vis(vec.size(), 0);
    vector<vector<int>> answer;

    print_all_permutation(vec, dummy, answer, vis, 0, vec.size());
    for(auto it : answer) {
        for(int elem : it) {
            cout << elem << " ";
        }
        cout << endl;
    }
}