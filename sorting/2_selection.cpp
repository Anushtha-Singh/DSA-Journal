#include <bits/stdc++.h> 
using namespace std;

int main() {
    vector<int> vec = { 2, 3, 1, 6, 4, 8, 2, 1};
    int maxi = 0;

    for(int i = 0; i < vec.size(); i++) {
        maxi = 0;
        for(int j = 0; j <= vec.size() - i - 1; j++) {
            if(vec[maxi] < vec[j]) maxi = j;
        }
        swap(vec[maxi], vec[vec.size() - 1 - i]);
    }

    for(int it : vec) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}