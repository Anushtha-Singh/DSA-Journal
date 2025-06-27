#include <bits/stdc++.h>
using namespace std;

//brute force
// int main() {
//     vector<int> vec = {2, 2, 5, 6, 1, 2, 3, 4, 8};

//     int result = 0;

//     for(int i = 0; i < vec.size(); i++) {
//         for(int j = i; j <= vec.size(); j++) {
//             if(vec[i] > vec[j]) result++;
//         }
//     }
//     cout << result;
//     return 0;
// }
int merge(vector<int>& vec, int low, int mid, int high) {
    int count = 0;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> left(n1);
    vector<int> right(n2);

    for(int i = 0; i < n1; i++) {
        left[i] = vec[low + i];
    }

    for(int j = 0; j < n2; j++) {
        right[j] = vec[mid + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            vec[k] = left[i];
            i++;
            k++;
        }
        else {
            vec[k] = right[j];
            count += n1 - i;
            j++;
            k++;
        }
    }

    while(i < n1) {
        vec[k] = left[i];
        i++;
        k++;
    }

    while(j < n2)  {
        vec[k] = right[j];
        j++;
        k++;
    }
    return count;
}

int mergeSort(vector<int>& vec, int low, int high) {
    //base condition
    if(low >= high) return 0;

    int count = 0;

    //logic
    int mid = low + (high - low)/2;
    count += mergeSort(vec, low, mid);
    count += mergeSort(vec, mid + 1, high);
    count += merge(vec, low, mid, high);

    return count;
}

int main() {
    vector<int> vec = {2, 2, 5, 6, 1, 2, 3, 4, 8};

    int result = mergeSort(vec, 0, vec.size() - 1);
    cout << result;
    return 0;
}