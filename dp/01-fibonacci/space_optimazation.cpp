#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    int prev = 1;
    int prev2 = 0;

    for(int i = 2; i <= n; i++) {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    cout << prev;
    return 0;
}