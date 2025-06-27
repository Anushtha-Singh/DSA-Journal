#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char num) {
    for(int i = 0; i < 4; i++) {
        if(board[i][col] == num) return false;
        if(board[row][i] == num) return false;
        if(board[2*(row/2) + i/2][2*(col/2) + i%2] == num) return false;
    }
    return true;
}

bool solve_sudoku(vector<vector<char>>& board, int n) {
    //direct logic no need for base condition it will return when we the for loop get's completed
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == '.') {
                for(int l = '1'; l <= '4'; l++) {
                    if(isValid(board, i, j, l)) {
                        board[i][j] = l;
                        if(solve_sudoku(board, n)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }        
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = {
        {'1', '.', '3', '4' },
        {'3', '4', '.', '.'},
        {'4', '.', '.', '1'},
        {'2', '1', '4', '.'}
    };

    solve_sudoku(board, board.size());

    for(auto it : board) {
        for(int elem : it) {
            cout << elem - '0'<< " ";
        }
        cout << endl;
    }

    return 1;
}