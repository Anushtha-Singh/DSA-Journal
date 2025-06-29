#include <bits/stdc++.h>
using namespace std;

int frogJump(vector<int>& energy, int ind) {
    //base condition
    if(ind == 0) return 0;

    //logic
    int left = frogJump(energy, ind - 1) + abs(energy[ind] - energy[ ind - 1]);
    int right = INT_MAX;
    if(ind > 1) {
        right = frogJump(energy, ind - 2) + abs(energy[ind] - energy[ind - 2]);
    }
    return min(left, right);
}

int main() {
    vector<int> energy = { 3, 4, 5, 2, 1, 1 };

    int result = frogJump(energy, energy.size() - 1);
    cout << result << endl;
    return 0;
}