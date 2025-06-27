#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 2, 2, 3, 4, 5, 6};

    vector<int> hash(vec.size(), 0);

    for(int i = 0; i < vec.size(); i++) {
        hash[vec[i]]++;
    }

    for(int it : hash) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}