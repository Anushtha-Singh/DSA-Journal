#include <bits/stdc++.h>
using namespace std;

int climb_stair(int n) {
    //base condition
    if(n <= 1) return 0;

    //logic
    int prev = 1;
    int prev2 = 1;

    for(int i = 2; i <= n; i++) {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main() {
    int n = 6;
    int result = climb_stair(n);
    cout << result;
    return 0;
}