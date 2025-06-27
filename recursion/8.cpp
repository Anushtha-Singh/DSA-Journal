#include <bits/stdc++.h>
using namespace std;

void print(vector<int> ans, int n) {
    for(int it : ans) {
        cout << it << " ";
    }
}

void subsequence(vector<int>& vec, vector<int>& ans, int n, int index) {
    //base condition
    if(index >= n) {
        print(ans, n);
        cout << endl;
        return;
    }

    //logic
    ans.push_back(vec[index]);
    subsequence(vec, ans, n, index + 1);

    ans.pop_back();
    subsequence(vec, ans, n, index + 1);
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    vector<int> ans;

    subsequence(vec, ans, vec.size(), 0);
    return 0;
}