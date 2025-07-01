#include <bits/stdc++.h>
using namespace std;

bool sequence(vector<int>& vec, int target) {
    //define prev
    vector<int> prev(target + 1, 0);
    vector<int> curr(target + 1, 0);

    //base case : when target is 0
    prev[0] = 1;
    //base case : first element base case
    if(vec[0] <= target) prev[vec[0]] = 1;

    //logic
    for(int i = 1; i < vec.size(); i++) {
        for(int j = 0; j <= target; j++) {
            bool not_take = prev[j];
            bool take = false;
            if(vec[i] <= j) take = prev[j - vec[i]];
            curr[j] = not_take || take;
        }
        prev = curr;
    }
    
    return prev[target];
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    int target = 5;

    if(sequence(vec, target)) cout << true << endl;
    else cout << false << endl;
    return 0;
}