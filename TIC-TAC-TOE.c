/*
 * @file tic_tac_toe.c
 * @brief A simple command-line Tic Tac Toe game implementation in C with player vs computer and player vs player modes.
 * @author Param Dholakia
 * @date 15-04-2024
 */

#include <stdio.h> // Standard Input/Output library
#include <stdlib.h> // Standard General Utilities library
#include <stdbool.h> // Standard Boolean library
#include <string.h> // String library
#include <ctype.h> // Character handling functions
#include <math.h> // Mathematical functions
#include <time.h> // Time functions

#define MAX_SIZE 100

// Function prototypes
void printBoard(char board[]);
bool checkWin(char board[]);
bool checkTie(char board[]);
void playerMove(char board[], char move, const char *playerName);
void playerVsComputer(char board[], const char *playerName);
void playerVsPlayer(char board[], const char *player1, const char *player2);

/**
 * @brief Main program function.
 * @returns 0 on clean exit.
 */
int main(int argc, char const *argv[]) {
    char board[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    char Player1[MAX_SIZE];

    int choice;
    printf("\nChoose Game Mode:\n");
    printf("1. Player vs Computer\n");
    printf("2. Player vs Player\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    printf("\nEnter Player 1's Name: ");
    scanf("%s", Player1);
    
    if (choice == 1) {
        playerVsComputer(board, Player1);
    } else if (choice == 2) {
        char Player2[MAX_SIZE];
        printf("\nEnter Player 2's Name: ");
        scanf("%s", Player2);
        playerVsPlayer(board, Player1, Player2);
    } else {
        printf("\nInvalid choice! Exiting...\n");
    }

    return 0; // Return 0 indicating successful execution
}

/**
 * @brief Prints the Tic Tac Toe game board.
 * @param board The array representing the game board.
 */
void printBoard(char board[]) {
    printf("\n %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
}

/**
 * @brief Checks if a player has won the game.
 * @param board The array representing the game board.
 * @return true if a player has won, false otherwise.
 */
bool checkWin(char board[]) {
    // Check Rows, Columns, and Diagonals for winning combinations
    // Return true if any combination is found and false otherwise

    // Check Rows
    for (int i = 0; i < 3; i++) {
        if (board[i] == board[i + 1] && board[i + 1] == board[i + 2] && board[i] != ' ') {
            return true;
        }
    }

    // Check Columns
    for (int i = 0; i < 3; i++) {
        if (board[i] == board[i + 3] && board[i + 3] == board[i + 6] && board[i] != ' ') {
            return true;
        }
    }

    // Check Diagonals
    if ((board[0] == board[4] && board[4] == board[8] && board[0] != ' ') ||
        (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')) {
        return true;
    }

    return false;
}

/**
 * @brief Checks if the game is tied (no more moves possible).
 * @param board The array representing the game board.
 * @return true if the game is tied, false otherwise.
 */
bool checkTie(char board[]) {
    // Check if there are any empty spaces left on the board
    // Return true if no empty space is found
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return false;
        }
    }
    return true;
}

/**
 * @brief Handles a player's move.
 * @param board The array representing the game board.
 * @param move The marker ('X' or 'O') for the current player.
 * @param playerName The name of the current player.
 */
void playerMove(char board[], char move, const char *playerName) {
    // Prompt the player for their move and update the board accordingly
    int index;

    printf("\n%s's move!\n", playerName);

    printf("Enter a position to place the marker (1-9): ");
    scanf("%d", &index);
    index--;

    while (index < 0 || index > 8 || board[index] != ' ') {
        printf("\nInvalid input or place already taken! Enter a valid space to assign (1-9): ");
        scanf("%d", &index);
        index--;
    }

    board[index] = move;
}

/**
 * @brief Executes the Player vs Computer game mode.
 * @param board The array representing the game board.
 * @param playerName The name of the player.
 */
void playerVsComputer(char board[], const char *playerName) {
    char currentPlayer = 'X';
    bool runningStatus = true;

    while (runningStatus) {
        printBoard(board);

        if (currentPlayer == 'X') {
            playerMove(board, currentPlayer, playerName);
        } else {
            // Computer's move (random position)
            int index;
            do {
                index = rand() % 9;
            } while (board[index] != ' ');
            board[index] = currentPlayer;
        }

        if (checkWin(board)) {
            printf("PLAYER %c %s WINS!!\n", currentPlayer, playerName);
            runningStatus = false;
            break;
        }

        if (checkTie(board)) {
            printf("Game is Tied!!\n");
            runningStatus = false;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    printBoard(board);
}

/**
 * @brief Executes the Player vs Player game mode.
 * @param board The array representing the game board.
 * @param player1 The name of the first player.
 * @param player2 The name of the second player.
 */
void playerVsPlayer(char board[], const char *player1, const char *player2) {
    char currentPlayer = 'X';
    bool runningStatus = true;

    while (runningStatus) {
        printBoard(board);

        playerMove(board, currentPlayer, (currentPlayer == 'X') ? player1 : player2);

        if (checkWin(board)) {
            printf("PLAYER %c %s WINS!!\n", currentPlayer, (currentPlayer == 'X') ? player1 : player2);
            runningStatus = false;
            break;
        }

        if (checkTie(board)) {
            printf("Game is Tied!!\n");
            runningStatus = false;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    printBoard(board);
}
