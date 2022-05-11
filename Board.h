#include <iostream>
#include <array>
#include <new>

class Board {
    public:
        Board(); //build a new tic tac toe board
        Board(char p1, char p2); //initialize a board with unique symbols
        bool isEmpty();
        bool winGame();
        char rowCombinations();
        char columnCombinations();
        char diagonalCombinations();
        char getPosition(int row, int column);
        char getWinnerSymbol();
        void placeLetter(int row, int column, char symbol);
        void printBoard();
        void clearBoard();
        void startGame();
    private:
        char board[3][3] = {{'/', '/', '/'}, {'/', '/', '/'}, {'/', '/', '/'}}; //[row][column]
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
    if(rowCombinations() != '/' || columnCombinations() != '/' || diagonalCombinations() != '/')
        return true;

    return false;
}


char Board::rowCombinations() {
    for(int i = 0; i < 3; i++) { //check all row combinations
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != '/')
            return board[i][1];
    }
    return '/';
}

char Board::columnCombinations() {
    for(int i = 0; i < 3; i++) { //check all column combinations
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != '/')
            return board[1][i];
    }
    return '/';
}

char Board::diagonalCombinations() {
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != '/') //check top-left to bottom-right diagonal
        return board[1][1];

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != '/') //check top-right to bottom-left diagonal
        return board[1][1];

    return '/';
}

char Board::getPosition(int r, int c) {
    return board[r][c];
}

char Board::getWinnerSymbol() {
    if(rowCombinations() != '/')
        return rowCombinations();
    else if(columnCombinations() != '/')
        return columnCombinations();
    else if(diagonalCombinations() != '/')
        return diagonalCombinations();
    
    return '/';
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

void Board::startGame() {
    bool playAgain = true;
    char yesNo = 'Y';

    do {
        do {
            int r = 0;
            int c = 0;
            std::cout << "It's player 1's turn!" << std::endl;
            printBoard();
            std::cout << "Which row and column would you like to insert your value?" << std::endl;
            do {
                std::cout << "Row: ";
                std::cin >> r;
                std::cout << "Column: ";
                std::cin >> c;
            } while(getPosition(r, c) != '/');
            placeLetter(r, c, player1Symbol);

            std::cout << "It's player 2's turn!" << std::endl;
            printBoard();
            std::cout << "Which row and column would you like to insert your value?" << std::endl;
            do {
                std::cout << "Row: ";
                std::cin >> r;
                std::cout << "Column: ";
                std::cin >> c;
            } while(getPosition(r, c) != '/');
            placeLetter(r, c, player2Symbol);

            if(!isEmpty()) {
                break;
            }
        } while(!winGame());

        if(getWinnerSymbol() == player1Symbol)
            std::cout << "Player 1 won!" << std::endl;
        else if(getWinnerSymbol() == player2Symbol)
            std::cout << "Player 2 won!" << std::endl;
        else    
            std::cout << "It was a tie!" << std::endl;

        clearBoard();
        std::cout << "Do you want to play again (Y/N)?" << std::endl;
        std::cin >> yesNo;
        tolower(yesNo) == 'y' ? playAgain = true : playAgain = false;

    } while(playAgain);
    std::cout << "The game has been terminated." << std::endl;
}