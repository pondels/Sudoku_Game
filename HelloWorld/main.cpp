#include <iostream>

using namespace std;

class Board
{
public:
    string board[9][9] = {
                      {"[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]"},
                      {"[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]"},
                      {"[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]"},
                      {"[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]"},
                      {"[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]"},
                      {"[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]"},
                      {"[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]"},
                      {"[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]"},
                      {"[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]", "[]"}
                        };

    void addNum(string number, int row, int column)
    {
        board[row - 1][column - 1] = number;
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

    int row;
    int column;
    string number;

    for(int y = 0; y < 10; y++)
        {
            cout << "Enter A Row > ";
            cin >> row;
            cout << "Enter A Column > ";
            cin >> column;
            cout << "Enter A Number > ";
            cin >> number;

            board.addNum(number, row, column);
            board.printBoard();
        }
    return 0;
}
