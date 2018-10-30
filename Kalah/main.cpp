#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
    Board board;
    board.draw();
    board.move(1, 1);
    board.draw();
    board.move(6, 1);
    board.draw();
    board.move(13, 1);
    board.draw();
    board.move(5, 1);
    board.draw();
    return 0;
}
