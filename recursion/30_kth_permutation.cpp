#include <bits/stdc++.h>
using namespace std;

void kth_permutation(vector<int>& vec, int k, int fact, string& answer, int n) {
    //base condition
    if(vec.empty()) return;

    //logic
    int index = k/fact;
    answer += to_string(vec[index]);
    vec.erase(vec.begin() + index);
    if(!vec.empty()) {
    kth_permutation(vec, k%fact, fact/vec.size(), answer, n);
    }
}

int main() {
    vector<int> vec = {1, 2, 3, 4};
    int k = 17;

    int fact = 1;
    for(int i = 1; i < vec.size(); i++) {
        fact *= i;
    }

    string answer;
    kth_permutation(vec, k, fact, answer, vec.size());
    cout << answer;

}