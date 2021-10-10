#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

class Board
{
private:
    int solvedBoard[9][9] = {
                            {0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0}
                            };
public:
    int board[9][9] = {
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}
                      };

    bool cellCheckerReturnValue(int cellCatch[9][2], int num, string boardType){
        // Used for checkCell, just more compressed code for checking
        // If a value is in their 3x3 cell they pertain to.
        for (int n=0; n<9; n++){
            if (boardType == "solvedBoard"){
                if (solvedBoard[cellCatch[n][0]][cellCatch[n][1]] == num){
                   return true;
                }
            }
            else {
                if (board[cellCatch[n][0]][cellCatch[n][1]] == num){
                    return true;
                }
            }
        }
        return false;
    }

    bool checkCell(int row, int column, int num, string boardType){
        // Checks if a number is already in the 3x3 cell
        int cell;
        if (row == 0 || row == 1 || row == 2){
            if (column == 0 || column == 1 || column == 2){cell = 1;}
            else if (column == 3 || column == 4 || column == 5){cell = 2;}
            else {cell = 3;}
        }
        else if (row == 3 || row == 4 || row == 5){
            if (column == 0 || column == 1 || column == 2){cell = 4;}
            else if (column == 3 || column == 4 || column == 5){cell = 5;}
            else {cell = 6;}
        }
        else {
            if (column == 0 || column == 1 || column == 2){cell = 7;}
            else if (column == 3 || column == 4 || column == 5){cell = 8;}
            else {cell = 9;}
        }
        if (cell == 1){
            int cellCatch[9][2] = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
            bool decider = cellCheckerReturnValue(cellCatch, num, boardType);
            return decider;
        }
        else if (cell == 2) {
            int cellCatch[9][2] = {{0,3},{0,4},{0,5},{1,3},{1,4},{1,5},{2,3},{2,4},{2,5}};
            bool decider = cellCheckerReturnValue(cellCatch, num, boardType);
            return decider;
        }
        else if (cell == 3){
            int cellCatch[9][2] = {{0,6},{0,7},{0,8},{1,6},{1,7},{1,8},{2,6},{2,7},{2,8}};
            bool decider = cellCheckerReturnValue(cellCatch, num, boardType);
            return decider;
        }
        else if (cell == 4){
            int cellCatch[9][2] = {{3,0},{3,1},{3,2},{4,0},{4,1},{4,2},{5,0},{5,1},{5,2}};
            bool decider = cellCheckerReturnValue(cellCatch, num, boardType);
            return decider;
        }
        else if (cell == 5){
            int cellCatch[9][2] = {{3,3},{3,4},{3,5},{4,3},{4,4},{4,5},{5,3},{5,4},{5,5}};
            bool decider = cellCheckerReturnValue(cellCatch, num, boardType);
            return decider;
        }
        else if (cell == 6){
            int cellCatch[9][2] = {{3,6},{3,7},{3,8},{4,6},{4,7},{4,8},{5,6},{5,7},{5,8}};
            bool decider = cellCheckerReturnValue(cellCatch, num, boardType);
            return decider;
        }
        else if (cell == 7){
            int cellCatch[9][2] = {{6,0},{6,1},{6,2},{7,0},{7,1},{7,2},{8,0},{8,1},{8,2}};
            bool decider = cellCheckerReturnValue(cellCatch, num, boardType);
            return decider;
        }
        else if (cell == 8){
            int cellCatch[9][2] = {{6,3},{6,4},{6,5},{7,3},{7,4},{7,5},{8,3},{8,4},{8,5}};
            bool decider = cellCheckerReturnValue(cellCatch, num, boardType);
            return decider;
        }
        else if (cell == 9){
            int cellCatch[9][2] = {{6,6},{6,7},{6,8},{7,6},{7,7},{7,8},{8,6},{8,7},{8,8}};
            bool decider = cellCheckerReturnValue(cellCatch, num, boardType);
            return decider;
        }
    }
    bool checkHorizontal(int row, int column, int num, string boardType){
        // Checks if a number is already in the horizontal
        for (int n=0; n < 10; n++){
            if (boardType == "solvedBoard"){
                if (num == solvedBoard[row][n]){
                    return true;
                }
            }
            else {
                if (num == board[row][n]){
                    return true;
                }
            }
        }
        return false;
    }
    bool checkVertical(int row, int column, int num, string boardType){
        // Checks if a number is already in the vertical
        for (int n=0; n < 10; n++){
            if (boardType == "solvedBoard"){
                if (num == solvedBoard[n][column]){
                    return true;
                }
            }
            else {
                if (num == board[n][column]){
                    return true;
                }
            }
        }
        return false;
    }

    void generateBoard(){
        // Generates a solvable sudoku board
        bool validNum = false;
        bool swapped = false;
        int num;
        std::array<int,9> yourMom {1,2,3,4,5,6,7,8,9};
        for (int row = 0; row < 10; row++){
            for (int column = 0; column < 10; column++){
                int n = 0;
                do {
                    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
                    shuffle(yourMom.begin(), yourMom.end(), std::default_random_engine(seed));
                    num = yourMom[0];
                    bool checkC = checkCell(row, column, num, "solvedBoard");
                    bool checkH = checkHorizontal(row, column, num, "solvedBoard");
                    bool checkV = checkVertical(row, column, num, "solvedBoard");
                    if (not checkC && not checkH && not checkV){
                        solvedBoard[row][column] = num;
                        break;
                    }
                    num = 1+std::rand()%9;
                    n++;
                } while (n < 255);
            }
        }
    }

    void addNum(int number, int row, int column)
    {
        // Adds a number to the board
        board[row - 1][column - 1] = number;
    }

    void removeNum(int row, int column)
    {
        // Removes a number from the board
        board[row - 1][column - 1] = 0;
    }

    void printBoard(string item, string boardType)
    // Prints the board to the player
    {
        if (item == "col"){cout << "    1   2   3     4   5   6     7   8   9\n    v   v   v     v   v   v     v   v   v\n";}
        else {cout << "\n\n";}
        for(int i = 0; i < 9; i++)
        {
            if(i == 3 || i == 6){
                cout << "   ---------------------------------------\n";
            }
            if(item == "row"){cout << i+1 << " > ";}
            else{cout << "   ";}
            for(int x = 0; x < 9; x++)
            {
                if (x == 3 || x == 6){cout << ": ";}
                if (boardType == "solvedBoard"){
                    if (solvedBoard[i][x] != 0){cout << "[" << solvedBoard[i][x] << "] ";}
                    else{cout << "[ ] ";}
                }
                else {
                    if (board[i][x] != 0){cout << "[" << board[i][x] << "] ";}
                    else{cout << "[ ] ";}3
                }
            }
            cout << endl;
        }
        cout << "\n" << endl;
    }

    int findRowColumn (int cellNumber, string type){
        // With a given cell, that cell is found and replaced with the
        // given number on the solved board
        int rowFound, columnFound;
        if (cellNumber < 10){
            rowFound = 0;
            columnFound = cellNumber - 1;
        }
        else if (cellNumber < 19){
            rowFound = 1;
            columnFound = cellNumber - 10;
        }
        else if (cellNumber < 28){
            rowFound = 2;
            columnFound = cellNumber - 19;
        }
        else if (cellNumber < 37){
            rowFound = 3;
            columnFound = cellNumber - 28;
        }
        else if (cellNumber < 46){
            rowFound = 4;
            columnFound = cellNumber - 37;
        }
        else if (cellNumber < 55){
            rowFound = 5;
            columnFound = cellNumber - 46;
        }
        else if (cellNumber < 64){
            rowFound = 6;
            columnFound = cellNumber - 55;
        }
        else if (cellNumber < 73){
            rowFound = 7;
            columnFound = cellNumber - 64;
        }
        else{
            rowFound = 8;
            columnFound = cellNumber - 73;
        }
        if (type == "row"){
            return rowFound;
        }
        else {
            return columnFound;
        }
    }

    void visualBoard(int start, int end){
        // Used for boardSetup()
        // Sets up the physical board
        std::array<int,81> boardMap {};
        for (int var=0; var < 81; var++){
            boardMap[var] = var;
        }
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(boardMap.begin(), boardMap.end(), std::default_random_engine(seed));
        for (int var=0; var < start; var++){
            int rowFound = findRowColumn(boardMap[var], "row");
            int columnFound = findRowColumn(boardMap[var], "column");
            board[rowFound][columnFound] = solvedBoard[rowFound][columnFound];
        }
    }

    void boardSetup(int difficulty){
        // Checks what difficulty the player wants and
        // runs visualBoard to setup the board.
        if (difficulty == 1){
            // Baby
            int amountShown[2] = {47, 55};
            visualBoard(amountShown[0], amountShown[1]);
        }
        else if (difficulty == 2){
            // Easy
            int amountShown[2] = {36, 46};
            visualBoard(amountShown[0], amountShown[1]);
        }
        else if (difficulty == 3){
            // Medium
            int amountShown[2] = {32, 35};
            visualBoard(amountShown[0], amountShown[1]);
        }
        else if (difficulty == 4){
            // Hard
            int amountShown[2] = {28, 31};
            visualBoard(amountShown[0], amountShown[1]);
        }
        else if (difficulty == 5){
            // Expert
            int amountShown[2] = {17, 27};
            visualBoard(amountShown[0], amountShown[1]);
        }
        else if (difficulty == 6){
            // Impossible
            int amountShown[2] = {13, 16};
            visualBoard(amountShown[0], amountShown[1]);
        }
        return;
    }

    bool checkValidBoard(){
        // Checks if the board generated is a solvable board
        for (int x=0; x < 9; x++){
            for (int y=0; y < 9; y++){
                if (solvedBoard[x][y] == 0){
                    return false;
                }
            }
        }
        return true;
    }
    bool checkValidMove(int row, int column, int number){
        bool invalidC = checkCell(row-1, column-1, number, "board");
        bool invalidH = checkHorizontal(row-1, column-1, number, "board");
        bool invalidV = checkVertical(row-1, column-1, number, "board");
        if (not invalidC && not invalidH && not invalidV){
            solvedBoard[row][column] = number;
            return true;
        }
        else{
            cout << invalidC << invalidH << invalidV << endl;
            return false;
        }
    }
    bool winningBoardChecker(){
        if (board == solvedBoard){
            return true;
        }
        return false;
    }
};

int main()
{
    int errors = 0;
    int difficulty;
    bool validBoard = false;
    cout << "Generating A New Board . . . " << endl;
    while(not validBoard) {
        Board board;
        board.generateBoard();
        validBoard = board.checkValidBoard();
        if (validBoard){
            cout << "Choose a Difficulty\n\n1) Baby\n2) Easy\n3) Medium\n4) Hard\n5) Expert\n6) Impossible\n > ";
            cin >> difficulty;
            board.boardSetup(difficulty);
            board.printBoard("", "solvedBoard");
            board.printBoard("", "board");
            bool playing = true;

            while(playing){
                int row, column;
                int number;
                int choice;
                bool validMove = false;
                bool validRow = false;
                bool validCol = false;
                bool validNum = false;

                cout << "PLEASE PICK AN OPTION: \n1) Add Number\n2) Remove Number\n3) Quit Game\n> ";
                cin >> choice;
                if (choice == 1){
                    while(not validRow){
                        board.printBoard("row", "board");
                        cout << "Enter A Row > ";
                        cin >> row;
                        if(1 <= row && row <= 9){validRow = true;}
                        else{cout << "INVALID ROW" << endl;}
                    }
                    while(not validCol){
                        board.printBoard("col", "board");
                        cout << "Enter A Column > ";
                        cin >> column;
                        if(1 <= column && column <= 9){validCol = true;}
                        else{cout << "INVALID COLUMN" << endl;}
                    }
                    while(not validNum){
                        cout << "Enter A Number > ";
                        cin >> number;
                        if(1 <= number && number <= 9){validNum = true;}
                        else{cout << "INVALID NUMBER" << endl;}
                    }
                    validMove = board.checkValidMove(row, column, number);
                    if (validMove){
                        board.addNum(number, row, column);
                        board.printBoard("", "board");
                    }
                    else {
                        cout << "Invalid Move!";
                        errors++;
                    }
                    bool wonGame = board.winningBoardChecker();
                    if (wonGame){
                        cout << "You Win!!!" << endl;
                        break;
                    }
                }
                else if (choice == 2){
                    while(not validRow){
                        board.printBoard("row", "board");
                        cout << "Enter A Row > ";
                        cin >> row;
                        if(1 <= row && row <= 9){validRow = true;}
                        else{cout << "INVALID ROW" << endl;}
                    }
                    while(not validCol){
                        board.printBoard("col", "board");
                        cout << "Enter A Column > ";
                        cin >> column;
                        if(1 <= column && column <= 9){validCol = true;}
                        else{cout << "INVALID COLUMN" << endl;}
                    }
                    board.removeNum(row, column);
                    board.printBoard("", "board");
                }
                else if (choice == 3){
                    playing = false;
                    cout << "Thanks for playing!";
                }
                else{
                    cout << "Please Enter A Valid Input!" << endl;
                }
            }
        }
    }
}
