#include <bits/stdc++.h>
using namespace std;

void rat_in_maze(int row, int col, vector<vector<int>>& graph, string& dummy, vector<string>& answer, vector<vector<int>>& vis, int n) {
    //base condition
    if(row == n - 1 && col == n - 1) {
        answer.push_back(dummy);
        return;
    }

    //logic
    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};
    string moves = "DURL";

    for(int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if(nr >= 0 && nc >= 0 && nr < n && nc < n && graph[nr][nc] == 1 && vis[nr][nc] == 0) {
            vis[nr][nc] = 1;
            dummy.push_back(moves[i]);
            rat_in_maze(nr, nc, graph, dummy, answer, vis, n);
            vis[nr][nc] = 0;
            dummy.pop_back();
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {1, 0, 0, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1},
    };

    vector<vector<int>> vis(4, vector<int>(4, 0));
    string dummy;
    vector<string> answer;
    vis[0][0] = 1;

    rat_in_maze(0, 0, graph, dummy, answer, vis, 4);

    for(string str : answer) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}