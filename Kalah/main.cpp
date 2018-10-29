#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
    Board board;
    board.draw();
    board.move(1);
    board.draw();
    board.move(10);
    board.draw();
    board.move(3);
    board.draw();
    board.move(11);
    board.draw();
    board.move(4);
    board.draw();
    return 0;
}
