#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 3, 3, 4, 5, 5, 3};

    map<int, int> mpp;

    for(int it : vec) {
        mpp[it]++;
    }

    for(auto it : mpp) {
        cout << it.first << "->"<< it.second << endl;
    }
    cout << endl;
    return 0;
}