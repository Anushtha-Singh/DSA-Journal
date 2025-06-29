#include <bits/stdc++.h>
using namespace std;

int k_frogJump(vector<int>& energy, int n, int k) {
    //base condition
    if(n == 0) return 0;

    //logic
    int mini = INT_MAX;
    for(int i = 1; i <= k; i++) {
        if(n - i >= 0) {
            int reduction = k_frogJump(energy, n - i, k) + abs(energy[n] - energy[n - i]);
            mini = min(mini, reduction); 
        }
    }
    return mini;
}

int main() {
    vector<int> energy = {1, 2, 3, 2, 5};
    int k = 4;
    int result = k_frogJump(energy, energy.size() -1, k);
    cout << result << endl;
    return 0;
}