#include <stdio.h>

int board[4];

// Check if position is safe
int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col ||                // same column
            board[i] - i == col - row ||      // \ diagonal
            board[i] + i == col + row)        // / diagonal
            return 0;
    }
    return 1;
}

// Solve the board
int solve(int row) {
    // If all 4 queens are placed
    if (row == 4) {
        // Print the board
        int i, j;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (board[i] == j)
                    printf("Q ");
                else
                    printf(". ");
            }
            printf("\n");
        }
        return 1; // Stop after first solution
    }

    // Try placing queen in all columns
    int col;
    for (col = 0; col < 4; col++) {
        if (isSafe(row, col)) {
            board[row] = col; // Place queen
            if (solve(row + 1)) // Recur for next row
                return 1;
        }
    }

    return 0; // No safe position found
}

// Main
int main() {
    solve(0);
    return 0;
}
