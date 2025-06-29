#include <bits/stdc++.h>
using namespace std;

int frogJump(vector<int>& energy, int n) {
    int prev = 0;
    int prev2 = 0;

    for(int i = 1; i <= n; i++) {
        //single jump
        int left = prev + abs(energy[i] - energy[i - 1]);
        
        //double jump
        int right = INT_MAX;
        if(i > 1) {
            right = prev2 + abs(energy[i] - energy[i - 2]);
        }
        prev2 = prev;
        prev = min(left, right);
    }
    return prev;
}

int main() {
    vector<int> energy = { 1, 2, 3, 2, 1};
    int result = frogJump(energy, energy.size() - 1);
    cout << result << endl;
    return 0;
}