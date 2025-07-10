#include <bits/stdc++.h>
using namespace std;

bool subsequence(vector<int>& vec, int target) {
    //define prev
    vector<int> prev(target + 1, 0);
    vector<int> curr(target + 1, 0);

    //base condition : when target is 0
    prev[0] = 1;
    //base condition : for 0th index element
    if(target >= vec[0]) prev[vec[0]] = 1;

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
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    int sum = 0;

    for(int it : vec) sum += it;

    if(sum % 2 != 0) {
        cout << false << endl;
        return 0;
    }
    sum = sum/2; 

    if(subsequence(vec, sum)) cout << true << endl;
    else cout << false << endl;
    return 0;
}