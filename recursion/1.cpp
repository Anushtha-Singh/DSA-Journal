#include <bits/stdc++.h>
using namespace std;


void rec(int n) {
    //base
    if(n > 10) return;

    //logic
    cout << n << " ";
    rec(n + 1);
}

int main() {
    // your code
    rec(1);
    return 0;
}
