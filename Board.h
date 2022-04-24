#include <iostream>
#include <array>
#include <new>

class Board {
    public:
        Board(); //build a new tic tac toe board
        Board(char p1, char p2); //initialize a board with unique symbols
        char getPosition(int row, int column);
        bool isEmpty();
        void placeLetter(char letter);
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

void Board::placeLetter(char l) {
    
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
    while(j <= 3) {
        board[j][i] = '/';
        
        i++;
        if(i % 3 == 0) {
            j++;
            i = 0;
        }
    }
}