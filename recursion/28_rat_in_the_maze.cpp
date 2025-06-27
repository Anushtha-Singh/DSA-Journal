#include <bits/stdc++.h>
using namespace std;

void rat_in_maze(int row, int col, vector<vector<int>>& graph, string& dummy, vector<string>& answer, vector<vector<int>>& vis, int n) {
    //base condition
    if(row == n - 1 && col == n - 1) {
        answer.push_back(dummy);
        return;
    }

    //logic -- upward
    if(row - 1 >= 0 && graph[row - 1][col] == 1 && vis[row - 1][col] != 1) {
        dummy = dummy + 'U';
        vis[row - 1][col] = 1;
        rat_in_maze(row - 1, col, graph, dummy, answer, vis, n);
        dummy.pop_back();
        vis[row- 1][col] = 0;
    }

    //--downward
    if(row + 1 < n && graph[row + 1][col] == 1 && vis[row + 1][col] != 1) {
        dummy = dummy + 'D';
        vis[row + 1][col] = 1;
        rat_in_maze(row + 1, col, graph, dummy, answer, vis, n);
        dummy.pop_back();
        vis[row + 1][col] = 0;
    }

    //--left
    if(col - 1 >= 0 && graph[row][col - 1] == 1 && vis[row][col - 1] != 1) {
        dummy = dummy + 'L';
        vis[row][col - 1] = 1;
        rat_in_maze(row, col - 1, graph, dummy, answer, vis, n);
        dummy.pop_back();
        vis[row][col - 1] = 0;
    }

    //--right
    if(col + 1 < n && graph[row][col + 1] == 1 && vis[row][col + 1] != 1) {
        dummy = dummy + 'R';
        vis[row][col + 1] = 1; 
        rat_in_maze(row, col + 1, graph, dummy, answer, vis, n);
        dummy.pop_back();
        vis[row][col + 1] = 0;
    }
}

int main() {
    vector<vector<int>> graph(4, vector<int>(4));

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> graph[i][j];
        }
    }

    string dummy;
    vector<string> answer;
    vector<vector<int>> vis(4, vector<int>(4, 0));
    vis[0][0] = 1;

    rat_in_maze(0, 0, graph, dummy, answer, vis, 4);

    for(auto str : answer) {
        cout << str << " ";
    }
    return 0;
}