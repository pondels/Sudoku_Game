#include <iostream>

using namespace std;

class Board
{
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
        string space = " ";
        board[row - 1][column - 1] = space += number += space;
    }

    void removeNum(int row, int column)
    {
        board[row - 1][column - 1] = "[ ]";
    }

    void printBoard()
    {
        cout << "\n\n";
        for(int i = 0; i < 9; i++)
        {
            if(i == 3 || i == 6){
                cout << "   ------------------------------\n";
            }
            cout << "   ";
            for(int x = 0; x < 9; x++)
            {
                if (x == 3 || x == 6){
                    cout << ": ";;
                }
                if (board[i][x] != "[]"){
                    cout << " " << board[i][x] << " ";
                }
                else{
                    cout << board[i][x] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    Board board;

    board.printBoard();

    bool playing = true;

        while(playing){
            int row;
            int column;
            string number;
            int choice;

            cout << "PLEASE PICK AN OPTION: \n1) Add Number\n2) Remove Number\n3) Quit Game\n> ";
            cin >> choice;
            if (choice == 1){
                cout << "Enter A Row > ";
                cin >> row;
                cout << "Enter A Column > ";
                cin >> column;
                cout << "Enter A Number > ";
                cin >> number;
                board.addNum(number, row, column);
                board.printBoard();
            }
            else if (choice == 2){
                cout << "Enter A Row > ";
                cin >> row;
                cout << "Enter A Column > ";
                cin >> column;
                board.removeNum(row, column);
                board.printBoard();
            }
            else if (choice == 3){
                playing = false;
                cout << "Thanks for playing!";
            }
        }
    return 0;
}
