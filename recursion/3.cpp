#include <bits/stdc++.h>
using namespace std;


int rec(vector<int>& vec,int n, int ind) {
    //base condition
    if(ind >= n - 1) return vec[ind];
     
    //logic
    return vec[ind] + rec(vec, n, ind + 1);
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    int result = rec(vec , vec.size(), 0);
    cout << result;
    return 0;
}