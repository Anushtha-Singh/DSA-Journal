#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int>& vec, int i, int j) {
    int pivot = i;

    while(i < j) {
        while(vec[i] > vec[pivot]) i++;
        while(vec[j] <= vec[pivot]) j--;

        if(i < j) swap(vec[i], vec[j]);
    }

    swap(vec[i], vec[pivot]);
    return i;
}

void reverse_quickSort(vector<int>& vec, int low, int high) {
    //base condition
    if(low >= high) return;

    //logic
    int pivot = findPivot(vec, low, high);

    reverse_quickSort(vec, low, pivot);
    reverse_quickSort(vec, pivot + 1, high);
}

int main() {
    vector<int> vec = { 2, 3, 4, 8, 4, 3};
    
    reverse_quickSort(vec, 0, vec.size() - 1);
    for(int it : vec) {
        cout << it << " ";
    }
    cout << endl;
    return 1;
}