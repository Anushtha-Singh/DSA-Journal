#include <bits/stdc++.h>
using namespace std;

int non_adjacent(vector<int>& vec, int n) {
    int prev = vec[0];
    int prev2 = 0;

    for(int i = 1; i <= n; i++) {
        int left = vec[i] + prev2;
        int right = prev;

        prev2 = prev;
        prev = max(left, right);
    }
    return prev;

}

int main() {
    vector<int> vec = { 1, 2, 3, 4, 5};
    int result = non_adjacent(vec, vec.size() - 1);
    cout << result << endl;
    return 0;
}