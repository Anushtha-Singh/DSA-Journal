#include <bits/stdc++.h>
using namespace std;

int non_adjacent_elem(vector<int>& vec, int index) {
    //base condition
    if(index == 0) return vec[0];
    if(index < 0) return 0;

    //logic
    int left = vec[index] + non_adjacent_elem(vec, index -2);
    int right = non_adjacent_elem(vec, index - 1);

    return max(left, right);
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6};

    int result = non_adjacent_elem(vec, vec.size() - 1);
    cout << result;
    return 0;
}