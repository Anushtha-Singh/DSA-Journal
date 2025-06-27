#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int>& vec, int low, int high) {
    int pivot = low;
    while(low < high) {
        while(vec[low] < vec[pivot]) low++;
        while(vec[high] > vec[pivot]) high--;
       //just swap them
       if(low < high) {
       swap(vec[low], vec[high]);
        low++;
        high--;
       } 
    }

    //put the pivot at it's correct position
    swap(vec[pivot], vec[high]);
    return high;
}

void quickSort(vector<int>& vec, int low, int high) {
    //base condition
    if(low >= high) return;
    int pivot = findPivot(vec, low, high);

    quickSort(vec, low, pivot - 1);
    quickSort(vec, pivot + 1, high);
}

int main() {
    vector<int> vec = { 7, 7, 3, 7, 5};
    quickSort(vec, 0, vec.size() - 1);

    for(int it : vec) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}