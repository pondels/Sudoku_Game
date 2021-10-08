#include <iostream>
#include <algorithm>

using namespace std;

class Board
{
private:
    string solvedBoard[9][9] = {
                                {},
                                {},
                                {},
                                {},
                                {},
                                {},
                                {},
                                {},
                                {}
                                }
public:
    string board[9][9] = {
                      {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"},
                      {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"},
                      {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"},
                      {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"},
                      {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"},
                      {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"},
                      {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"},
                      {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"},
                      {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]"}
                        };

    void addNum(string number, int row, int column)
    {
        string open = "[";
        string close = "]";
        board[row - 1][column - 1] = open += number += close;
    }

    void removeNum(int row, int column)
    {
        board[row - 1][column - 1] = "[ ]";
    }

    bool checkCells(){
        // Check for duplicates in an array both vertical and horizontal
        // Horizontal
         for (int i = 0; i < 9; i++){
            for (int x = 0; x < 9; x++){
                int * p;
                // p = find (std::begin(board[i]), std::end(board[i]), board[i][x]);
                //if (p != board[i]+9){
                //    cout << "Element found in row: " << p << '\n';}
                //else{
                //    cout << "Element not found in row\n";}
            }
        }
        return false;
    }

    bool checkWin(){
        bool variable = checkCells();
        if (variable){

        }
        else{
            return false;
        }
    }

    void printBoard(string item)
    {
        if (item == "col"){cout << "     1    2    3     4    5    6     7    8    9\n     v    v    v     v    v    v     v    v    v\n";}
        else {cout << "\n\n";}
        for(int i = 0; i < 9; i++)
        {
            if(i == 3 || i == 6){
                cout << "    ---------------------------------------------\n";
            }
            if(item == "row"){cout << i+1 << " >";}
            else{cout << "   ";}
            for(int x = 0; x < 9; x++)
            {
                if (x == 3 || x == 6){cout << ":";}
                if (board[i][x] != "[]"){cout << " " << board[i][x] << " ";}
                else{cout << board[i][x] << " ";}
            }
            cout << endl;
        }
    }
};

int main()
{
    Board board;

    board.printBoard("");

    bool playing = true;

        while(playing){
            int row, column;
            string number;
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
                    if(number == "1" || number == "2" || number == "3" || number == "4" || number == "5" || number == "6" || number == "7" || number == "8" || number == "9"){validNum = true;}
                    else{cout << "INVALID NUMBER" << endl;}
                }
                board.addNum(number, row, column);
                bool duplicateValue = board.checkCells();
                if (duplicateValue){cout << "Duplicate Variable!";}
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
        }
    return 0;
}
