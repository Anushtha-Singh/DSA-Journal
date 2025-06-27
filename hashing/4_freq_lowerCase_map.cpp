#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "Anushtha";
    unordered_map<char, int> mpp;

    for(char ch : str) {
        mpp[ch]++;
    }

    for(auto it : mpp) {
        cout << it.first << "->" << it.second << endl;
    }
    return 0;
}