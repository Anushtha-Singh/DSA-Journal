//optimized using 3 array for 3 condition
#include <bits/stdc++.h>
using namespace std;

void n_queen(int n, int col, vector<vector<char>>& board, vector<vector<vector<char>>>& answer, vector<int>& leftHorizontal, vector<int>& upperLeftDiagonal, vector<int>& lowerLeftDiagonal) {
    //base condition
    if(col == n) {
        answer.push_back(board);
        return;
    }

    //logic
    for(int row = 0; row < n; row++) {
        if(leftHorizontal[row] == 0 && upperLeftDiagonal[n - 1 + col - row] == 0 && lowerLeftDiagonal[row + col] == 0) {
            //pick
            board[row][col] = 'Q';
            leftHorizontal[row] = 1;
            upperLeftDiagonal[(n - 1) + (col - row)] = 1;
            lowerLeftDiagonal[row + col] = 1; 
            n_queen(n, col + 1, board, answer, leftHorizontal, upperLeftDiagonal, lowerLeftDiagonal);
            //not-pick
            board[row][col] = '.';
            leftHorizontal[row] = 0;
            upperLeftDiagonal[(n -  1) + (col - row)] = 0;
            lowerLeftDiagonal[row + col] = 0;
        }
    }


}

int main() {
    int n = 5;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    vector<vector<vector<char>>> answer;

    vector<int> leftHorizontal(n, 0);
    vector<int> upperLeftDiagonal(2*n-1, 0);
    vector<int> lowerLeftDiagonal(2*n-1, 0);

    n_queen(n, 0, board, answer, leftHorizontal, upperLeftDiagonal, lowerLeftDiagonal);
    
    for(int i = 0; i < answer.size(); i++) {
        for(int j = 0; j < n; j++) {
            for(int l = 0; l < n; l++) {
            cout << answer[i][j][l] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}