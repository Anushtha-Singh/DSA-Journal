#include <bits/stdc++.h>
using namespace std;


void merge(vector<int>& sort_it, int low,  int mid, int high) {

    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> left(n1);
    vector<int> right(n2);

    //store elems of left
    for(int i = 0; i < n1; i++) {
        left[i] = sort_it[low + i];
    }

    //store elems of right
    for(int i = 0; i < n2; i++) {
        right[i] = sort_it[mid + i + 1];
    }

    //define the two pointer for sorting
    int i = 0;
    int j = 0;
    int k = low;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            sort_it[k++] = left[i];
            i++;
        }
        else if(left[i] > right[j]) {
            sort_it[k++] = right[j];
            j++;
        }
    }

    while(i < n1) {
        sort_it[k++] = left[i];
        i++;
    }

    while(j < n2) {
        sort_it[k++] = right[j];
        j++;
    }
}

void merge_sort(vector<int>& sort_it, int low, int high) {
    //base condition
    if(low >= high) return;
    
    int mid = low + ( high - low ) / 2;

    //left side
    merge_sort(sort_it, low, mid);
    //right side
    merge_sort(sort_it, mid + 1, high);
    //merge it
    merge(sort_it, low, mid, high);
}

int main() {
    vector<int> sort_it = { 8, 5,9, 3, 5, 1 };

    merge_sort(sort_it, 0, sort_it.size() - 1);
    for(int it : sort_it) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}