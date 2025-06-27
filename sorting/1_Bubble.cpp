#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec = {8, 2, 3, 4, 5, 6, 2};
    bool swapped = false;
    int swaps = 0;

    for(int i = 0; i < vec.size(); i++) {
        swapped = false;
        for(int j = 1; j < vec.size() - i; j++) {
            if(vec[j] < vec[j - 1]) {
                swap(vec[j], vec[j - 1]);
                swapped = true;
                swaps++;
            }
        }
        if(!swapped) break;
    }

    for(int it : vec) {
        cout << it << " ";
    }
    cout << endl;
    cout << swaps;
    return 0;
}