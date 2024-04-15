// Name of author: Param Dholakia
// Topic: Tic Tac Toe Game
// Date: 15-04-2024

import java.util.InputMismatchException;
import java.util.Scanner;

class Game {
    private char[] board = new char[9];

    public Game() {
        for (int i = 0; i < 9; i++) {
            board[i] = ' ';
        }
    }

    public void printBoard() {
        System.out.println();
        System.out.println(" " + board[0] + " | " + board[1] + " | " + board[2]);
        System.out.println("-----------");
        System.out.println(" " + board[3] + " | " + board[4] + " | " + board[5]);
        System.out.println("-----------");
        System.out.println(" " + board[6] + " | " + board[7] + " | " + board[8]);
        System.out.println();
    }

    public void playerMove(String playerName, char move) {
        Scanner scanner = new Scanner(System.in);
        int index;

        System.out.print("\n\nYour Move, " + playerName + "! Enter your index (1-9):");
        while (true) {
            try {
                index = scanner.nextInt();
                index--;

                if (index < 0 || index >= 9 || board[index] != ' ') {
                    System.out.print("\n\nInvalid index! Please enter a valid index:");
                } else {
                    break;
                }
            } catch (InputMismatchException e) {
                System.out.print("\n\nInvalid input! Please enter a number:");
                scanner.next(); // Clear the invalid input
            }
        }

        board[index] = move;
    }

    public boolean checkWinner() {
        // Row Check
        for (int i = 0; i < 3; i++) {
            if (board[i] != ' ' && board[i] == board[i + 1] && board[i] == board[i + 2]) {
                return true;
            }
        }

        // Column Check
        for (int i = 0; i < 3; i++) {
            if (board[i] != ' ' && board[i] == board[i + 3] && board[i] == board[i + 6]) {
                return true;
            }
        }

        // Diagonal Check
        if (board[0] != ' ' && board[0] == board[4] && board[0] == board[8]) {
            return true;
        }
        if (board[2] != ' ' && board[2] == board[4] && board[2] == board[6]) {
            return true;
        }

        return false;
    }

    public boolean checkDraw() {
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                return false;
            }
        }
        return true;
    }
}

public class TicTacToe {
    public static void main(String[] args) {
        Game game = new Game();
        Scanner scanner = new Scanner(System.in);

        System.out.print("\nEnter Player 1 (X) Name: ");
        String player1 = scanner.nextLine();

        System.out.print("\nEnter Player 2 (O) Name: ");
        String player2 = scanner.nextLine();

        boolean runningStatus = true;

        while (runningStatus) {
            game.printBoard();
            game.playerMove(player1, 'X');

            if (game.checkWinner()) {
                game.printBoard();
                System.out.println("Player 1 "+player1+" Wins!");
                runningStatus = false;
                break;
            }
            
            if (game.checkDraw()) {
                game.printBoard();
                System.out.println("Game Draw!");
                runningStatus = false;
                break;
            }
            
            game.printBoard();
            game.playerMove(player2, 'O');
            
            if (game.checkWinner()) {
                game.printBoard();
                System.out.println("Player 2 "+player2+" Wins!");
                runningStatus = false;
                break;
            }
            
            if (game.checkDraw()) {
                game.printBoard();
                System.out.println("Game Draw!");
                runningStatus = false;
                break;
            }
        }

        scanner.close();
    }
}
