#include <bits/stdc++.h>
using namespace std;

int main()  {
    string str = "anushtha";

    vector<int> freq(26, 0);

    for(int i = 0; i < str.size(); i++) {
        freq[str[i] - 'a']++;
    }

    for(int it : freq) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}