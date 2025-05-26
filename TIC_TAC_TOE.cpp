#include <iostream>
using namespace std;

char board[3][3]; // 3x3 board
char currentPlayer = 'X';

// Function to initialize the board with numbers 1-9
void initializeBoard() {
    char cell = '1';
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = cell++;
}

// Function to display the current board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Function to check if the current player has won
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == currentPlayer &&
             board[i][1] == currentPlayer &&
             board[i][2] == currentPlayer) ||

            (board[0][i] == currentPlayer &&
             board[1][i] == currentPlayer &&
             board[2][i] == currentPlayer))
            return true;
    }

    // Check diagonals
    if ((board[0][0] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][2] == currentPlayer) ||

        (board[0][2] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][0] == currentPlayer))
        return true;

    return false;
}

// Function to check for a draw
bool checkDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

// Function to switch the current player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to handle the player move
bool makeMove(int cell) {
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    } else {
        return false;
    }
}

int main() {
    int cell;
    bool gameEnd = false;

    initializeBoard();

    cout << "==== TIC-TAC-TOE GAME ====\n";
    cout << "Player 1: X | Player 2: O\n";

    while (!gameEnd) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> cell;

        if (cell < 1 || cell > 9) {
            cout << "Invalid input. Please choose between 1 and 9.\n";
            continue;
        }

        if (!makeMove(cell)) {
            cout << "Cell already taken. Choose another one.\n";
            continue;
        }

        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            gameEnd = true;
        } else if (checkDraw()) {
            displayBoard();
            cout << "The game is a draw!\n";
            gameEnd = true;
        } else {
            switchPlayer();
        }
    }

    return 0;
}

