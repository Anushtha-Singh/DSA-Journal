#include <bits/stdc++.h>
using namespace std;

int climb_stairs(int n) {
    //base condition
    if( n == 1 ) return 1;
    if( n == 0 ) return 1;

    //logic
    return climb_stairs(n - 1) + climb_stairs(n - 2);
}

int main() {
    int n = 6;

    int result = climb_stairs(n);
    cout << result;
    return 0;
}