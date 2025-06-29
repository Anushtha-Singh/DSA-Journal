#include <bits/stdc++.h>
using namespace std;

int non_adjacent(vector<int>& house, int n) {
    int prev = house[0];
    int prev2 = 0;

    for(int i = 1; i <= n; i++) {
        int left = house[i] + prev2;
        int right = prev;
        prev2 = prev;
        prev = max(left, right);
    }
    return prev;
}

int main() {
    vector<int> house = {1, 2, 3, 4, 5, 6};
    vector<int> house_1;
    vector<int> house_n;
    for(int i = 0; i < house.size(); i++) {
        if(i != house.size() - 1) house_1.push_back(house[i]);
        if(i != 0) house_n.push_back(house[i]);
    }

    int withFirstHouse = non_adjacent(house_1, house_1.size() - 1);
    int withLastHouse = non_adjacent(house_n, house_n.size() -1);
    int result = max(withFirstHouse, withLastHouse);
    cout << result << endl;
    return 0;
}