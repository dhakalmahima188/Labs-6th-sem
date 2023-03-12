#include <stdio.h>

// Function to display the Tic Tac Toe board
void display_board(char board[3][3]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if a player has won
int check_win(char board[3][3], char player) {
    int i, j;

    // Check rows for a win
    for (i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns for a win
    for (j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    // Check diagonals for a win
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

// Function to check if the game is a tie
int check_tie(char board[3][3]) {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int row, col, turn = 0;
    char player = 'X';

    while (1) {
        display_board(board);

        // Get the row and column from the player
        printf("Player %c, enter row (1-3): ", player);
        scanf("%d", &row);
        printf("Player %c, enter column (1-3): ", player);
        scanf("%d", &col);

        // Convert the row and column to array indices
        row--;
        col--;

        // Check if the move is valid
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move!\n");
            continue;
        }

        // Make the move
        board[row][col] = player;

        // Check for a win
        if (check_win(board, player)) {
            display_board(board);
            printf("Player %c wins!\n", player);
            break;
        }

        // Check for a tie
