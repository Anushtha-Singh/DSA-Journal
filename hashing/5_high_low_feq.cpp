#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec = {1, 1, 2 ,3,3, 3, 3, 4, 4, 5, 3,2 , 3};
    map<int, int> mpp;
    for(int it : vec) {
        mpp[it]++;
    }

    int high = INT_MIN;
    int low = INT_MAX;
    int highVar;
    int lowVar;

    for(auto it : mpp) {
        if(it.second >  high) {
            high = it.second;
            highVar = it.first;
        }
        if(it.second < low) {
            low = it.second;
            lowVar = it.first;
        }
    }

    cout << "high " << highVar << "\n" << "low " << lowVar; 
    return 0;
}