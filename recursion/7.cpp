#include <bits/stdc++.h>
using namespace std;

int fibonacci(int elem) {
    //base condition
    if(elem <= 1) return elem;

    //logic
    return fibonacci(elem - 1) + fibonacci(elem - 2);
}

int main() {
    int elem;
    cin >> elem;

    int result = fibonacci(elem);
    cout << result << endl;
    return 0;
}