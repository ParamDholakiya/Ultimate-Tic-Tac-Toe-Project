#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

class TicTacToe {
private:
    vector<char> board;

public:
    TicTacToe() : board(9, ' ') {}

    void printBoard() const {
        cout << "\n";
        cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
        cout << "-----------\n";
        cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
        cout << "-----------\n";
        cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
        cout << "\n";
    }

    void playerMove(const string &playerName, char move) {
        int index;
        cout << "\nYour Move, " << playerName << "! Enter your index (1-9): ";
        while (true) {
            try {
                cin >> index;
                index--;
                if (cin.fail() || index < 0 || index >= 9 || board[index] != ' ') {
                    cin.clear();                                         // Clear the input stream state
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                    cout << "\nInvalid input or index! Please enter a valid index (1-9): ";
                } else {
                    break;
                }
            } catch (...) {
                cout << "\nInvalid input or index! Please enter a valid index (1-9): ";
                cin.clear();                                         // Clear the input stream state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            }
        }
        board[index] = move;
    }

    bool checkWinner() const {
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

    bool checkDraw() const {
        for (char cell : board) {
            if (cell == ' ') {
                return false;
            }
        }
        return true;
    }

    void playGame(const string &player1, const string &player2) {
        bool runningStatus = true;
        char currentPlayer = 'X';

        while (runningStatus) {
            printBoard();

            if (currentPlayer == 'X') {
                playerMove(player1, 'X');
            } else {
                playerMove(player2, 'O');
            }

            if (checkWinner()) {
                printBoard();
                cout << "Player " << currentPlayer << " (" << (currentPlayer == 'X' ? player1 : player2) << ") Wins!\n";
                runningStatus = false;
            } else if (checkDraw()) {
                printBoard();
                cout << "Game Draw!\n";
                runningStatus = false;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
};

int main() {
    TicTacToe game;
    string player1, player2;

    cout << "Enter Player 1 (X) Name: ";
    getline(cin, player1);

    cout << "Enter Player 2 (O) Name: ";
    getline(cin, player2);

    game.playGame(player1, player2);

    return 0;
}
