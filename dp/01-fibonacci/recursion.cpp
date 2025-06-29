#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
    //base condition
    if(n <= 1) return n;

    //logic
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 5;

    int result = fibonacci(n);
    cout << result;
    return 0;
}
