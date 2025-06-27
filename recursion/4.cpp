#include <bits/stdc++.h>
using namespace std;

int multiplication(vector<int>& arr, int n, int index) {
    //base condition 
    if(index >= n - 1) return arr[index];

    //logic
    return arr[index]*multiplication(arr, n, index+1);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = multiplication(arr, arr.size(), 0);
    cout << result;
    return 0; 
}