#include <bits/stdc++.h>
using namespace std;

int paths(int row, int col) {
    //base condition
    if(row == 0 && col == 0) {
        return 1;
    }
    if(row < 0 || col < 0) return 0;

    //logic
    return paths(row - 1, col) + paths(row, col - 1);
}

int main() {
    int n = 2;
    int m = 2;

    int result = paths(n , m);
    cout << result << endl;
    return 0;
}