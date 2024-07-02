#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to display the game board
void displayBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

// Function to check if a player has won
bool checkWin(vector<vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char currentPlayer = 'X';
    vector<vector<char>> board = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};

    while (true) {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column numbers, 0-2): ";
        int row, col;
        cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2) {
            cout << "Invalid move, try again.\n";
            continue;
        }

        if (board[row][col] != '-') {
            cout << "Cell is already occupied, try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Do you want to play again? (y/n): ";
    char playAgain;
    cin >> playAgain;

    if (playAgain == 'y') {
        main();
    }

    return 0;
}