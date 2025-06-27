#include <bits/stdc++.h>
using namespace std;

void rec(int n) {
    //base condition
    if(n == 10) return;

    //logic 
    rec(--n);
    
}

int main() {
    rec(1);
    return 0;
}