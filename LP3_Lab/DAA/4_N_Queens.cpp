#include <iostream>
#include <vector>
using namespace std;
// Size of the chessboard
const int N = 8;

// Function to print the chessboard
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Function to check if it's safe to place a Queen at board[row][col]
bool isSafe(const vector<vector<int>>& board, int row, int col) {
    // Check the left side of the current row
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check upper diagonal on the left
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check lower diagonal on the left
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Function to solve N-Queens using backtracking
bool solveNQueens(vector<vector<int>>& board, int col) {
    if (col >= N) {
        // All Queens have been successfully placed
        printBoard(board);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;  // Place the Queen
            res = solveNQueens(board, col + 1) || res;
            board[i][col] = 0;  // Backtrack
        }
    }

    return res;
}

int main() {
    vector<vector<int>> board(N, vector<int>(N, 0));

    // Place the first Queen in the first row (row 0)
    board[0][0] = 1;

    if (!solveNQueens(board, 1)) {
        cout << "No solution exists." << endl;
    }

    return 0;
}
