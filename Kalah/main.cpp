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
    return 0;
}
