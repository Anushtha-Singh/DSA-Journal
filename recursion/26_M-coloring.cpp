#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>>& graph, int node, int i, vector<int>& color, int n) {
    for(int j = 0; j < n; j++) {
        if(graph[j][node] == 1 && color[j] == i) return false;
    }
    return true;
}

bool m_color(vector<vector<int>>& graph, int n, int m, vector<int>& color, int node) {
    //base condition
    if(node == n) return true;

    //logic 
    for(int i = 0; i < m; i++) {
        if(isValid(graph, node, i + 1, color, n)) {
            color[node] = i + 1;
            if(m_color(graph, n, m, color, node + 1)) return true;
            color[node] = 0;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> graph = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 1 },
        { 1, 1, 0, 0 },
        { 1, 1, 0, 0 }
    };

    int m = 3;
    vector<int> color(graph.size(), 0);

    if(m_color(graph, graph.size(), m, color, 0)) cout << true;
    else cout << false;
    return 0;
}