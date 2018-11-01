#include <iostream>
#include "Board.h"

using namespace std;

//void Board::setValue(int algorithm, int player)
//pass 1 for Gentry's algorithm
//pass 2 for Vishal's algorithm

//Player 1 is "bottom" player, Player 2 is the "top"

int main()
{
    Board board;
    board.draw();
    board.setValue(1, 1);
    cout << "This board is worth " << board.getValue() << " to Player 1" << endl;
    board.move(1, 1);
    board.draw();
    board.setValue(1, 2);
    cout << "This board is worth " << board.getValue() << " to Player 2" << endl;
    board.move(6, 1);
    board.draw();
    board.setValue(1, 1);
    cout << "This board is worth " << board.getValue() << " to Player 1" << endl;
    board.move(13, 1);
    board.draw();
    board.setValue(1, 2);
    cout << "This board is worth " << board.getValue() << " to Player 2" << endl;
    board.move(5, 1);
    board.draw();
    board.setValue(1, 1);
    cout << "This board is worth " << board.getValue() << " to Player 1" << endl;
    return 0;
}
