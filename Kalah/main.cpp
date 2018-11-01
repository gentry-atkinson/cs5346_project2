#include <iostream>
#include "Board.h"

using namespace std;

//void Board::setValue(int algorithm, int player)
//pass 1 for Gentry's algorithm
//pass 2 for Vishal's algorithm

//Player 1 is "bottom" player, Player 2 is the "top"

int main()
{
    int player = 1;
    Board board;
    board.draw();
    board.setValue(1, player);
    cout << "This board is worth " << board.getValue() << " to Player " << player << endl;
    player = board.move(1, player);
    board.draw();
    board.setValue(1, player);
    cout << "This board is worth " << board.getValue() << " to Player " << player << endl;
    player = board.move(6, player);
    board.draw();
    board.setValue(1, player);
    cout << "This board is worth " << board.getValue() << " to Player " << player << endl;
    player = board.move(13, player);
    board.draw();
    board.setValue(1, player);
    cout << "This board is worth " << board.getValue() << " to Player " << player << endl;
    player = board.move(5, player);
    board.draw();
    board.setValue(1, player);
    cout << "This board is worth " << board.getValue() << " to Player " << player << endl;
    return 0;
}
