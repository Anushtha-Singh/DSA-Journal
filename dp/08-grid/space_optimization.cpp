#include <bits/stdc++.h>
using namespace std;

int paths(int row, int col) {
    vector<int> prev(col + 1, 0);

    for(int i = 0; i <= row; i++) {
        vector<int> temp(col + 1, 0);
        for(int j = 0; j <= col; j++) {
            if(i == 0 && j == 0) temp[j] = 1;
            else {
                int up = ( i > 0 ) ? prev[j] : 0;
                int left = ( j > 0 ) ? temp[j - 1] : 0;
                temp[j] = up + left;
            }
        }
        prev = temp;
    }
    return prev[col];
}

int main() {
    int n = 2;
    int m = 2;

    int result = paths(n, m);
    cout << result << endl;
    return 0;
}