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
    // Initializing A Solved State of the Board
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
    // Initializing The Board the Player will be working with
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

    // Function Called when a cell is needing to be checked
    bool cellCheckerReturnValue(int cellCatch[9][2], int num, string boardType){
        // Used for checkCell, just more compressed code for checking
        // If a value is in their 3x3 cell they pertain to.

        // Iterates through the 9 cells given via cellCatch
        for (int n=0; n<9; n++){

            // Boardtype is checking whether or not the board being checked is
            // the solved one or not
            if (boardType == "solvedBoard"){
                if (solvedBoard[cellCatch[n][0]][cellCatch[n][1]] == num){
                   // Returns true if a duplicate was found
                   return true;
                }
            }
            else {
                if (board[cellCatch[n][0]][cellCatch[n][1]] == num){
                    // Returns true if a duplicate was found
                    return true;
                }
            }
        }
        // Returns false if no duplicate values were found
        return false;
    }

    // Called when a cell is needing checked for duplicate values
    bool checkCell(int row, int column, int num, string boardType){
        // Checks if a number is already in the 3x3 cell
        int cell;

        // Checks for the row number that was thrown to the function
        if (row == 0 || row == 1 || row == 2){
            // Checks the column that was thrown to the function
            // and then returns which cell the number is in
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

        // Finds which cell the number was found in
        if (cell == 1){
            // Based on the cell number it returns every possible value in the
            // 3x3 grid to be checked
            int cellCatch[9][2] = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
            // passes through the cells to be checked with the number to be searched
            // for duplicates
            bool decider = cellCheckerReturnValue(cellCatch, num, boardType);
            // returns a true of false value depending on whether a duplicate was found or not
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

    // Checks if a number is found in the horizontal position of the grid
    bool checkHorizontal(int row, int column, int num, string boardType){

        // Iterates through the 9 cells horizontally on the board
        for (int n=0; n < 9; n++){
            // Checks the board type to be determined
            if (boardType == "solvedBoard"){
                // Checks the row and the n which is the column being checked by
                // the system to a dynamic number
                if (num == solvedBoard[row][n]){
                    // returns true if the number was found in the cells
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

    // Checks if a number is found in the vertical position of the grid
    bool checkVertical(int row, int column, int num, string boardType){
        // Iterates through the 9 cells vertically on the board
        for (int n=0; n < 9; n++){
            // Checks the board type to be checked
            if (boardType == "solvedBoard"){
                // Dynamically updates the row to be searched
                // with a fixed column for vertical checking
                if (num == solvedBoard[n][column]){
                    // Returns true if the number was found in the cells
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

    // Generates the solved board
    void generateBoard(){
        // num is updated for each cell generated
        int num;

        // Iterates through the rows in the grid
        for (int row = 0; row < 9; row++){
            // Iterates through the columns in the grid
            for (int column = 0; column < 9; column++){
                // Does a while loop using n to make sure every possible value has been checked
                // for a valid int to get passed through
                int n = 0;
                do {
                    // Randomizes a number from 1 - 9
                    num = 1+std::rand()%9;
                    // Runs the checker functions to see if duplicates of the number were found
                    bool checkC = checkCell(row, column, num, "solvedBoard");
                    bool checkH = checkHorizontal(row, column, num, "solvedBoard");
                    bool checkV = checkVertical(row, column, num, "solvedBoard");
                    // If nothing was found, the item in placed in the cell and the while loop is broken
                    if (not checkC && not checkH && not checkV){
                        solvedBoard[row][column] = num;
                        break;
                    }
                    n++;
                } while (n < 45);
            }
        }
    }

    // Called when the user wants to input a number
    void addNum(int number, int row, int column)
    {
        // Adds a number to the board
        board[row - 1][column - 1] = number;
    }
    // Called when the user wants to remove a number
    void removeNum(int row, int column)
    {
        // Removes a number from the board
        board[row - 1][column - 1] = 0;
    }

    void printBoard(string item, string boardType)
    // Prints the board to the player
    {
        // if col is called, it means the columns are being displayed for input
        if (item == "col"){cout << "    1   2   3     4   5   6     7   8   9\n    v   v   v     v   v   v     v   v   v\n";}
        else {cout << "\n\n";}
        // iterates through each cell in the grid and formats it to print it out
        for(int i = 0; i < 9; i++)
        {
            if(i == 3 || i == 6){
                cout << "   ---------------------------------------\n";
            }
            // Called if the rows are being inputted
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
                    else{cout << "[ ] ";}
                }
            }
            cout << endl;
        }
        cout << "\n" << endl;
    }

    // Called to find the row and column of a given cell
    int findRowColumn (int cellNumber, string type){
        // With a given cell, that cell is found and replaced with the
        // given number on the solved board
        int rowFound, columnFound;

        // cell number can range from 0 - 81
        if (cellNumber < 9){
            // Each row corresponds to a column, so it takes the cellNumber and
            // subtracts the previous offset to get an index of 0 - 8
            rowFound = 0;
            columnFound = cellNumber;
        }
        else if (cellNumber < 18){
            rowFound = 1;
            columnFound = cellNumber - 9;
        }
        else if (cellNumber < 27){
            rowFound = 2;
            columnFound = cellNumber - 18;
        }
        else if (cellNumber < 36){
            rowFound = 3;
            columnFound = cellNumber - 27;
        }
        else if (cellNumber < 45){
            rowFound = 4;
            columnFound = cellNumber - 36;
        }
        else if (cellNumber < 54){
            rowFound = 5;
            columnFound = cellNumber - 45;
        }
        else if (cellNumber < 63){
            rowFound = 6;
            columnFound = cellNumber - 54;
        }
        else if (cellNumber < 72){
            rowFound = 7;
            columnFound = cellNumber - 63;
        }
        else{
            rowFound = 8;
            columnFound = cellNumber - 72;
        }

        // If the row is needing found, it runs this
        if (type == "row"){
            return rowFound;
        }
        // If the column is needing found, it runs this
        else {
            return columnFound;
        }
    }

    // Called when the difficulty of the board is being setup
    void visualBoard(int start, int end){
        // Used for boardSetup()
        // Sets up the physical board

        // Sets up a list of 81 items
        std::array<int,81> boardMap {};
        // Adds 0 - 80 to the array
        for (int var=0; var < 81; var++){
            boardMap[var] = var;
        }
        // Randomizes the array to get a shuffled list
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(boardMap.begin(), boardMap.end(), std::default_random_engine(seed));

        // Goes through the array for the amount of times the system chooses
        // based on the difficulty and the amount of cells are given
        // for said difficulty
        for (int var=0; var < start; var++){
            // returns the row and column of the cell in the array
            int rowFound = findRowColumn(boardMap[var], "row");
            int columnFound = findRowColumn(boardMap[var], "column");
            // sets the value of the cell on the player's board equal to the cell
            // on the solved board.
            board[rowFound][columnFound] = solvedBoard[rowFound][columnFound];
        }
    }

    // Used to initialize the board setup for the user
    void boardSetup(int difficulty){
        // Checks what difficulty the player wants and
        // runs visualBoard to setup the board.
        if (difficulty == 1){
            // Baby
            // amountShown is a value of a randomized range of 47 - 55
            // The amount of numbers to appear on the board for the user
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
                    // returns false if a 0 is found
                    // aka, the program made an unsolvable board
                    return false;
                }
            }
        }
        // returns true if all elements are filled
        return true;
    }

    // Runs whenever the user tried to make a move
    bool checkValidMove(int row, int column, int number){

        // Same syntax as the generateBoard function, except it's for the user's board
        bool invalidC = checkCell(row-1, column-1, number, "board");
        bool invalidH = checkHorizontal(row-1, column-1, number, "board");
        bool invalidV = checkVertical(row-1, column-1, number, "board");
        if (not invalidC && not invalidH && not invalidV){
            return true;
        }
        return false;
    }

    // Checks if the player has completed the game
    bool winningBoardChecker(){
        // Iterates through the board's rows and columns
        for (int x=0; x<9; x++){
            for (int y=0; y<9; y++){
                // checks if all the elements are filled
                if (board[x][y] == 0){
                    return false;
                }
            }
        }
        // If all elements are filled, the game is complete
        return true;
    }
};

int main()
{
    // Errors not yet implemented
    int errors = 0;
    // Difficulty set before user defines it
    int difficulty;
    // validBoard set to false until the board has generated a valid board
    bool validBoard = false;
    cout << "Generating A New Board . . . " << endl;

    // Begins a while loop for the validBoard
    while(not validBoard) {
        // Initiates the Board class as board
        Board board;

        // Generates a new board
        board.generateBoard();
        // Checks if the board generated is valid
        validBoard = board.checkValidBoard();
        // If the board is valid, it breaks the while loop and starts a new if loop
        if (validBoard){
            // Asks the player for a difficulty and then sets the board up according to the difficulty chosen
            cout << "Choose a Difficulty\n\n1) Baby\n2) Easy\n3) Medium\n4) Hard\n5) Expert\n6) Impossible\n > ";
            cin >> difficulty;
            board.boardSetup(difficulty);
            board.printBoard("", "board");
            // Initiates a new while loop until the user is no longer playing the game
            bool playing = true;

            while(playing){
                // row, column, number, and choice are all values set by the player
                // row, column, and number are the rows, column, and number inputs for the grid
                int row, column;
                int number;
                int choice;
                // These Bool values are to see if the number or move the user entered is valid
                bool validMove = false;
                bool validRow = false;
                bool validCol = false;
                bool validNum = false;

                // prompts the user what to do
                cout << "PLEASE PICK AN OPTION: \n1) Add Number\n2) Remove Number\n3) Quit Game\n> ";
                cin >> choice;
                if (choice == 1){
                    // Keeps asking the user to input a row until valid
                    while(not validRow){
                        board.printBoard("row", "board");
                        cout << "Enter A Row > ";
                        cin >> row;
                        if(1 <= row && row <= 9){validRow = true;}
                        else{cout << "INVALID ROW" << endl;}
                    }
                    // Keeps asking the user to input a column until valid
                    while(not validCol){
                        board.printBoard("col", "board");
                        cout << "Enter A Column > ";
                        cin >> column;
                        if(1 <= column && column <= 9){validCol = true;}
                        else{cout << "INVALID COLUMN" << endl;}
                    }
                    // Keeps asking the user to input a number until valid
                    while(not validNum){
                        cout << "Enter A Number > ";
                        cin >> number;
                        if(1 <= number && number <= 9){validNum = true;}
                        else{cout << "INVALID NUMBER" << endl;}
                    }
                    // Checks if the move the user tried making was valid
                    validMove = board.checkValidMove(row, column, number);
                    if (validMove){
                        // If valid, it prints the board and adds the number to the board
                        board.addNum(number, row, column);
                        board.printBoard("", "board");
                    }
                    else {
                        cout << "Invalid Move!" << endl;
                        errors++;
                    }
                    // Checks if the user won the game
                    bool wonGame = board.winningBoardChecker();
                    if (wonGame){
                        // If the game is completed, the loop is broken
                        // along with the others and the game terminates
                        cout << "You Win!!!" << endl;
                        break;
                    }
                }
                else if (choice == 2){
                    // Same concept as choice 1 but it doesn't add a number, it removes it
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
                    // Quits the game if the user does not wish to play anymore
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
