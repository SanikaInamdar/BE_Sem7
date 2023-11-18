#include <iostream>
using namespace std;

// Define the size of the chessboard
#define N 8

// Define the initial placement of the queen
pair<int, int> placed = {0, 2};

// Function to check if it's safe to place a queen at a given position
bool isSafe(int board[N][N], int row, int col) {
  // Check the row on the left side
  for (int i = 0; i < col; ++i) {
    if (board[row][i] == 1) {
      return false;
    }
  }

  // Check upper diagonal on the left side
  for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
    if (board[i][j] == 1) {
      return false;
    }
  }

  // Check lower diagonal on the left side
  for (int i = row, j = col; i < N && j >= 0; ++i, --j) {
    if (board[i][j] == 1) {
      return false;
    }
  }

  // Check upper diagonal on the right side
  for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
    if (board[i][j] == 1) {
      return false;
    }
  }

  return true;
}

// Recursive function to solve the N-Queens problem
bool NQueens(int board[N][N], int col) {
  // If all queens are placed, return true
  if (col >= N) {
    return true;
  }

  // Skip the column where the queen is already placed
  if (col == placed.second) {
    return NQueens(board, col + 1);
  }

  // Try placing the queen in each row of the current column
  for (int i = 0; i < N; ++i) {
    // Skip the row where the queen is already placed
    if (i == placed.first) {
      continue;
    }

    // Check if it's safe to place the queen at the current position
    if (isSafe(board, i, col)) {
      // Place the queen
      board[i][col] = 1;

      // Recur to place queens in the remaining columns
      if (NQueens(board, col + 1)) {
        return true;  // If successful, return true
      }

      // If placing queen in the current position doesn't lead to a solution, BACKTRACK
      board[i][col] = 0;
    }
  }

  // If no row is found to place the queen in the current column, return false
  return false;
}

// Function to print the chessboard
void printBoard(int board[N][N]) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (board[i][j] == 0) {
        cout << '.';  // Empty cell
      } else if (board[i][j] == 1) {
        cout << 'Q';  // Cell with a queen
      } else {
        cout << 'P';  // Cell where the initial queen was placed
      }

      cout << ' ';
    }

    cout << endl;
  }
}

int main() {
  // Initialize the chessboard
  int board[N][N] = {{0}};

  // Place the initial queen on the board
  board[placed.first][placed.second] = 1;

  // Print the initial board
  cout << "Initial Board" << endl;
  printBoard(board);
  cout << "****************" << endl;

  // Solve the N-Queens problem
  if (NQueens(board, 0)) {
    // If a solution is found, print the board
    cout << "Solution" << endl;
    printBoard(board);
    cout << "****************" << endl;
  } else {
    // If no solution is found, print a message
    cout << "No Solution" << endl;
  }

  return 0;
}
// Best Case Time Complexity: O(N)

// Average Case Time Complexity: O(2^(N/2))

// Worst Case Time Complexity: O(2^N)

// Space Complexity: O(N^2) -> matrix of size N x N + recursion stack of size N 
