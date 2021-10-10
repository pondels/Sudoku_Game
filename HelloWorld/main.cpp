#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include <random>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

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

    bool cellCheckerReturnValue(int cellCatch[9][2], int num){
        for (int n=0; n<9; n++){
            if (solvedBoard[cellCatch[n][0]][cellCatch[n][1]] == num){
               return true;
            }
        }
        return false;
    }

    bool checkCell(int row, int column, int num){
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
            bool decider = cellCheckerReturnValue(cellCatch, num);
            return decider;
        }
        else if (cell == 2) {
            int cellCatch[9][2] = {{0,3},{0,4},{0,5},{1,3},{1,4},{1,5},{2,3},{2,4},{2,5}};
            bool decider = cellCheckerReturnValue(cellCatch, num);
            return decider;
        }
        else if (cell == 3){
            int cellCatch[9][2] = {{0,6},{0,7},{0,8},{1,6},{1,7},{1,8},{2,6},{2,7},{2,8}};
            bool decider = cellCheckerReturnValue(cellCatch, num);
            return decider;
        }
        else if (cell == 4){
            int cellCatch[9][2] = {{3,0},{3,1},{3,2},{4,0},{4,1},{4,2},{5,0},{5,1},{5,2}};
            bool decider = cellCheckerReturnValue(cellCatch, num);
            return decider;
        }
        else if (cell == 5){
            int cellCatch[9][2] = {{3,3},{3,4},{3,5},{4,3},{4,4},{4,5},{5,3},{5,4},{5,5}};
            bool decider = cellCheckerReturnValue(cellCatch, num);
            return decider;
        }
        else if (cell == 6){
            int cellCatch[9][2] = {{3,6},{3,7},{3,8},{4,6},{4,7},{4,8},{5,6},{5,7},{5,8}};
            bool decider = cellCheckerReturnValue(cellCatch, num);
            return decider;
        }
        else if (cell == 7){
            int cellCatch[9][2] = {{6,0},{6,1},{6,2},{7,0},{7,1},{7,2},{8,0},{8,1},{8,2}};
            bool decider = cellCheckerReturnValue(cellCatch, num);
            return decider;
        }
        else if (cell == 8){
            int cellCatch[9][2] = {{6,3},{6,4},{6,5},{7,3},{7,4},{7,5},{8,3},{8,4},{8,5}};
            bool decider = cellCheckerReturnValue(cellCatch, num);
            return decider;
        }
        else if (cell == 9){
            int cellCatch[9][2] = {{6,6},{6,7},{6,8},{7,6},{7,7},{7,8},{8,6},{8,7},{8,8}};
            bool decider = cellCheckerReturnValue(cellCatch, num);
            return decider;
        }
    }
    bool checkHorizontal(int row, int column, int num){

        for (int n=0; n < 10; n++){
            if (num == solvedBoard[row][n]){
                return true;
            }
        }
        return false;
    }
    bool checkVertical(int row, int column, int num){
        for (int n=0; n < 10; n++){
            if (num == solvedBoard[n][column]){
                return true;
            }
        }
        return false;
    }

    void generateBoard(){
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
                    bool checkC = checkCell(row, column, num);
                    bool checkH = checkHorizontal(row, column, num);
                    bool checkV = checkVertical(row, column, num);
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
        board[row - 1][column - 1] = number;
    }

    void removeNum(int row, int column)
    {
        board[row - 1][column - 1] = 0;
    }

    void printBoard(string item)
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
                if (solvedBoard[i][x] != 0){cout << "[" << solvedBoard[i][x] << "] ";}
                else{cout << "[ ] ";}
            }
            cout << endl;
        }
        cout << "\n" << endl;
    }

    bool checkValidBoard(){
        for (int x=0; x < 9; x++){
            for (int y=0; y < 9; y++){
                if (solvedBoard[x][y] == 0){
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    bool validBoard = false;
    while(not validBoard) {
        Board board;
        board.generateBoard();
        validBoard = board.checkValidBoard();
        board.printBoard("");
        //sleep_for(.05s);
        //sleep_until(system_clock::now());
        if (validBoard){
            board.printBoard("");

    bool playing = true;

    while(playing){
        int row, column;
        int number;
        int choice;
        bool validRow = false;
        bool validCol = false;
        bool validNum = false;

        cout << "PLEASE PICK AN OPTION: \n1) Add Number\n2) Remove Number\n3) Quit Game\n> ";
        cin >> choice;
        if (choice == 1){
            while(not validRow){
                board.printBoard("row");
                cout << "Enter A Row > ";
                cin >> row;
                if(1 <= row && row <= 9){validRow = true;}
                else{cout << "INVALID ROW" << endl;}
            }
            while(not validCol){
                board.printBoard("col");
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
            board.addNum(number, row, column);
            board.printBoard("");
        }
        else if (choice == 2){
            while(not validRow){
                board.printBoard("row");
                cout << "Enter A Row > ";
                cin >> row;
                if(1 <= row && row <= 9){validRow = true;}
                else{cout << "INVALID ROW" << endl;}
            }
            while(not validCol){
                board.printBoard("col");
                cout << "Enter A Column > ";
                cin >> column;
                if(1 <= column && column <= 9){validCol = true;}
                else{cout << "INVALID COLUMN" << endl;}
            }
            board.removeNum(row, column);
            board.printBoard("");
        }
        else if (choice == 3){
            playing = false;
            cout << "Thanks for playing!";
        }
        else{
            cout << "Please Enter A Valid Input!" << endl;
        }
    }
}}}
