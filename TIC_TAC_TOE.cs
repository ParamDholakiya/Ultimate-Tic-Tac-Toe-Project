// Name of author: Param Dholakia
// Topic: Tic Tac Toe Game
// Date: 15-04-2024


using System;
using System.Collections.Generic;

class Game
{
    private List<char> board;

    public Game()
    {
        board = new List<char>(new char[9] { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' });
    }

    public void PrintBoard()
    {
        Console.WriteLine();
        Console.WriteLine(" " + board[0] + " | " + board[1] + " | " + board[2]);
        Console.WriteLine("-----------");
        Console.WriteLine(" " + board[3] + " | " + board[4] + " | " + board[5]);
        Console.WriteLine("-----------");
        Console.WriteLine(" " + board[6] + " | " + board[7] + " | " + board[8]);
        Console.WriteLine();
    }

    public void PlayerMove(string playerName, char move)
    {
        int index;

        Console.Write("\nYour Move, " + playerName + "! Enter your index (1-9): ");
        do
        {
            if (!int.TryParse(Console.ReadLine(), out index) || index < 1 || index > 9 || board[index - 1] != ' ')
            {
                Console.Write("\nInvalid index! Please enter a valid index: ");
            }
            else
            {
                break;
            }
        } while (true);

        board[index - 1] = move;
    }

    public bool CheckWinner()
    {
        // Row Check
        for (int i = 0; i < 3; i++)
        {
            if (board[i] != ' ' && board[i] == board[i + 1] && board[i] == board[i + 2])
            {
                return true;
            }
        }

        // Column Check
        for (int i = 0; i < 3; i++)
        {
            if (board[i] != ' ' && board[i] == board[i + 3] && board[i] == board[i + 6])
            {
                return true;
            }
        }

        // Diagonal Check
        if (board[0] != ' ' && board[0] == board[4] && board[0] == board[8])
        {
            return true;
        }
        if (board[2] != ' ' && board[2] == board[4] && board[2] == board[6])
        {
            return true;
        }

        return false;
    }

    public bool CheckDraw()
    {
        foreach (char cell in board)
        {
            if (cell == ' ')
            {
                return false;
            }
        }
        return true;
    }
}

class TicTacToe
{
    static void Main(string[] args)
    {
        Game game = new Game();
        string player1, player2;

        Console.Write("\nEnter Player 1 (X) Name: ");
        player1 = Console.ReadLine();

        Console.Write("\nEnter Player 2 (O) Name: ");
        player2 = Console.ReadLine();

        bool runningStatus = true;

        while (runningStatus)
        {
            game.PrintBoard();
            game.PlayerMove(player1, 'X');

            if (game.CheckWinner())
            {
                game.PrintBoard();
                Console.WriteLine("Player 1 " + player1 + " Wins!");
                runningStatus = false;
                break;
            }

            if (game.CheckDraw())
            {
                game.PrintBoard();
                Console.WriteLine("Game Draw!");
                runningStatus = false;
                break;
            }

            game.PrintBoard();
            game.PlayerMove(player2, 'O');

            if (game.CheckWinner())
            {
                game.PrintBoard();
                Console.WriteLine("Player 2 " + player2 + " Wins!");
                runningStatus = false;
                break;
            }

            if (game.CheckDraw())
            {
                game.PrintBoard();
                Console.WriteLine("Game Draw!");
                runningStatus = false;
                break;
            }
        }
    }
}
