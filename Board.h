#include <iostream>
#include <array>
#include <new>

class Board {
    public:
        Board(); //build a new tic tac toe board
        Board(char p1, char p2); //initialize a board with unique symbols
        char getPosition(int row, int column);
        bool isEmpty();
        bool winGame();
        void placeLetter(int row, int column, char symbol);
        void printBoard();
        void clearBoard();
    private:
        char board[3][3]; //[row][column]
        char player1Symbol;
        char player2Symbol;
};

Board::Board() {
    player1Symbol = 'X';
    player2Symbol = 'O';
    clearBoard();
}

Board::Board(char p1, char p2) {
    if(p1 == p2) {
        Board();
        return;
    } else {
        player1Symbol = p1;
        player2Symbol = p2;
        clearBoard();
    }
}

char Board::getPosition(int r, int c) {
    return board[r][c];
}

bool Board::isEmpty() {
    int i = 0;
    int j = 0;
    while(j < 3) {

        if(board[j][i] != '/')
            return false;

        i++;
        if(i % 3 == 0) {
            j++;
            i = 0;
        }
    }
    return true;
}

bool Board::winGame() {
    int row = 0;
    int col = 0;
    char playerSymbol = board[0][0];
    for(; row < 3; col++) { //check all row combinations
        if(col % 3 == 0) {
            row++;
            col = 0;
            playerSymbol = board[row][col];
        }

        if(playerSymbol != board[row][col]) {
            return false;
        }
    }

    row = 0;
    col = 0;
    playerSymbol = board[row][col];
    for(; col < 3; row++) { //check all column combinations
        if(row % 3 == 0) {
            col++;
            row = 0;
            playerSymbol = board[row][col];
        }

        if(playerSymbol != board[row][col]) {
            return false;
        }
    }

    row = 0;
    col = 0;
    playerSymbol = board[row][col];
    for(; col < 3; col++) { //check top-left to bottom-right diagonal

        if(playerSymbol != board[row][col]) {
            return false;
        }
        row++;
    }

    row = 0;
    col = 2;
    playerSymbol = board[row][col];
    for(; col >= 0; col--) { //check top-right to bottom-left diagonal

        if(playerSymbol != board[row][col]) {
            return false;
        }

        row++;
    }

    return true;
}

void Board::placeLetter(int row, int column, char symbol) {
    if(symbol == player1Symbol)
        board[row][column] = player1Symbol;
    else if(symbol == player2Symbol)
        board[row][column] = player2Symbol;
    else
        board[row][column] = '/';
}

void Board::printBoard() {
    int i = 0;
    int j = 0;
    while(j < 3) {
        std::cout << board[j][i] << " ";
        i++;
        if(i % 3 == 0) {
            j++;
            i = 0;
            std::cout << std::endl;
        }
    }
}

void Board::clearBoard() {
    int i = 0;
    int j = 0;
    while(j < 3) {
        board[j][i] = '/';
        
        i++;
        if(i % 3 == 0) {
            j++;
            i = 0;
        }
    }
}