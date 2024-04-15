#-------------------------------------------------------------
"""
| Name of author: Param Dholakia
| Topic: TIC-TAC-TOE
| Date: 15-04-2024
 """ 
#-------------------------------------------------------------


class TicTacToe:
    def __init__(self):
        # we will use a single list to represent the 3x3 board
        # For every empty cell we will use ' '.
        self.board = [' ' for _ in range(9)]        

    def printBoard(self):
        print()
        print(f" {self.board[0]} | {self.board[1]} | {self.board[2]} ")
        print("-----------")
        print(f" {self.board[3]} | {self.board[4]} | {self.board[5]} ")
        print("-----------")
        print(f" {self.board[6]} | {self.board[7]} | {self.board[8]} ")
        print()

    def playerMove(self, move, playerName):
        while True:
            try:
                index = int(input(f"\nYour Move, {playerName}! Enter your index (1-9): ")) - 1
                if 0 <= index < 9 and self.board[index] == ' ':
                    self.board[index] = move
                    break
                else:
                    print("Invalid index! Please enter a valid index.")
            except ValueError:
                print("Invalid input! Please enter a number.")
            
    def winnerCheck(self):
        for i in range(0, 9, 3):
            if self.board[i] != ' ' and self.board[i] == self.board[i + 1] == self.board[i + 2]:
                return True

        # Column Check
        for i in range(3):
            if self.board[i] != ' ' and self.board[i] == self.board[i + 3] == self.board[i + 6]:
                return True

        # Diagonal Check
        if self.board[0] != ' ' and self.board[0] == self.board[4] == self.board[8]:
            return True
        if self.board[2] != ' ' and self.board[2] == self.board[4] == self.board[6]:
            return True

        return False
    
    def check_draw(self):
        return ' ' not in self.board
    


if __name__ == '__main__':
    # Initialize the game
    TicTacToe = TicTacToe()
    
    print("Welcome to Tic-Tac-Toe!")
    player1 = input("Enter Player 1 (X) name: ")
    player2 = input("Enter Player 2 (O) name: ")

    runningCondition = True

    while runningCondition:
        TicTacToe.printBoard()
        TicTacToe.playerMove('X', player1)
        TicTacToe.printBoard()
        if TicTacToe.winnerCheck():
            print(f"Congratulations! {player1} wins!")
            runningCondition = False
            break
        if TicTacToe.check_draw():
            print("It's a draw!")
            runningCondition = False
            break

        TicTacToe.playerMove('O', player2)
        if TicTacToe.winnerCheck():
            TicTacToe.printBoard()
            print(f"Congratulations! {player2} wins!")
            runningCondition = False
            break
        if TicTacToe.check_draw():
            print("It's a draw!")
            runningCondition = False
            break
        