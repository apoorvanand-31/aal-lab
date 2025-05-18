//n queen using backtracking
#include <stdio.h>
#include <stdbool.h>

#define N 8  // You can change N to any value

// Function to print the chessboard
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check this column on all previous rows
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Backtracking function to solve N-Queens problem
bool solveNQueens(int board[N][N], int row) {
    // If all queens are placed
    if (row >= N) {
        return true;
    }

    // Try placing a queen in all columns one by one
    for (int col = 0; col < N; col++) {
        // Check if placing queen on board[row][col] is safe
        if (isSafe(board, row, col)) {
            // Place queen
            board[row][col] = 1;

            // Recur to place the next queen
            if (solveNQueens(board, row + 1)) {
                return true;
            }

            // If placing queen in board[row][col] doesn't lead to a solution, backtrack
            board[row][col] = 0;
        }
    }

    // If the queen can not be placed in any column in this row
    return false;
}

// Driver function to solve the N-Queens problem
int main() {
    int board[N][N] = {0};  // Initialize the board with 0 (no queen)

    if (solveNQueens(board, 0)) {
        printSolution(board);
    } else {
        printf("Solution does not exist\n");
    }

    return 0;
}
