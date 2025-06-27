#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int index, int end) {
    while(index < end) {
        if(str[index] != str[end]) return false;
        index++;
        end--;
    }
    return true;
}

void palindrome_partition(string str, vector<string>& dummy, vector<vector<string>>& answer, int n, int index) {
    //base condtion
    if(index >= n) {
        answer.push_back(dummy);
        return;
    }

    //logic 
    for(int i = index; i < n; i++) {
        if(isPalindrome(str, index, i)) {
            dummy.push_back(str.substr(index, i - index + 1));
            palindrome_partition(str, dummy, answer, n , i + 1);
            dummy.pop_back();
        }
    }
}

int main() {
    string str;
    cin >> str;

    vector<vector<string>> ans;
    vector<string> dummy;

    palindrome_partition(str, dummy, ans, str.size(), 0);
    for(auto st : ans) {
        for(string s : st) {
        cout << s << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}