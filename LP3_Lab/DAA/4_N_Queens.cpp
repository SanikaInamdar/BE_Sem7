#include <iostream>
#include <vector>

// Size of the chessboard
const int N = 8;

// Function to print the chessboard
void printBoard(const std::vector<std::vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j])
                std::cout << "Q ";
            else
                std::cout << ". ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

// Function to check if it's safe to place a Queen at board[row][col]
bool isSafe(const std::vector<std::vector<int>>& board, int row, int col) {
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
bool solveNQueens(std::vector<std::vector<int>>& board, int col) {
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
    std::vector<std::vector<int>> board(N, std::vector<int>(N, 0));

    // Place the first Queen in the first row (row 0)
    board[0][0] = 1;

    if (!solveNQueens(board, 1)) {
        std::cout << "No solution exists." << std::endl;
    }

    return 0;
}
