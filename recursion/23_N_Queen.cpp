#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<char>>& board) {
    //looping to check
    
    int dupRow = row;
    int dupCol = col;

    //for left horizontal side
    while(col >= 0) {
        if(board[row][col] == 'Q') return false;
        col--;
    }

    row = dupRow;
    col = dupCol;

    //for upper left diagonal
    while(row >= 0 && col >= 0) {
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    row = dupRow;
    col = dupCol;

    //for lower left diagonal
    while(row < board.size() && col >= 0) {
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }

    return true;
}

void n_queen(int n, int col, vector<vector<char>>& board, vector<vector<vector<char>>>& answer) {
    //base condition
    if(col == n) {
        answer.push_back(board);
        return;
    }

    //logic
    for(int row = 0; row < n; row++) {
        if(isSafe(row, col, board)) {
            board[row][col] = 'Q';
            n_queen(n, col + 1, board, answer);
            board[row][col] = '.';
        }
    }
}

int main() {
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    vector<vector<vector<char>>> answer;
    n_queen(n, 0, board, answer);

    for(auto it : answer) {
        for(auto it_1 : it) { 
            for(char ch : it_1) {
            cout << ch << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 1;
}