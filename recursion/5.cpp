#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int>& vec, int n, int index) {
    //base condition
    if(index >= n - index - 1) return;

    //logic
    swap(vec[index], vec[n - index - 1]);
    reverse(vec, n, index + 1);
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    reverse(vec, vec.size(), 0);
    
    for(int it : vec) {
        cout << it << " ";
    }
    return 0;
}