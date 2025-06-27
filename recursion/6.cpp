#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string& str, int index, int n) {
    //base condition
    if(index == n/2) return true;

    //logic
    if(str[index] != str[n - index -1]) return false;
    return checkPalindrome(str, index + 1, n);
}

int main() {
    string str;

    cin >> str;

    bool flag = checkPalindrome(str, 0, str.size());
    cout << flag << endl;

    return 0;
}