#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vect = { 4, 3, 1, 3, 5, 7, 4, 2, 1};

    for(int i = 1; i < vect.size(); i++) {
        int j = i;
        while(j > 0 && vect[j] < vect[j - 1]) {
            swap(vect[j], vect[j - 1]);
            j--;
        }
    }

    for(int it : vect) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}