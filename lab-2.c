//string matching using dfs
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ROWS 3
#define COLS 4

// Directions: up, down, left, right
int dirX[] = {-1, 1, 0, 0};
int dirY[] = {0, 0, -1, 1};

// DFS function to search word
bool dfs(char board[ROWS][COLS], int x, int y, const char* word, int index, bool visited[ROWS][COLS]) {
    if (word[index] == '\0') return true;

    // Check bounds
    if (x < 0 || y < 0 || x >= ROWS || y >= COLS) return false;

    // Check if visited or character mismatch
    if (visited[x][y] || board[x][y] != word[index]) return false;

    visited[x][y] = true;

    // Explore all 4 directions
    for (int d = 0; d < 4; d++) {
        int newX = x + dirX[d];
        int newY = y + dirY[d];

        if (dfs(board, newX, newY, word, index + 1, visited)) {
            return true;
        }
    }

    visited[x][y] = false; // Backtrack
    return false;
}

bool exist(char board[ROWS][COLS], const char* word) {
    bool visited[ROWS][COLS] = {false};

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == word[0]) {
                if (dfs(board, i, j, word, 0, visited))
                    return true;
            }
        }
    }
    return false;
}

// Main function
int main() {
    char board[ROWS][COLS] = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    const char* word = "ABCCED";

    if (exist(board, word)) {
        printf("Word '%s' exists in the board.\n", word);
    } else {
        printf("Word '%s' does NOT exist in the board.\n", word);
    }

    return 0;
}
