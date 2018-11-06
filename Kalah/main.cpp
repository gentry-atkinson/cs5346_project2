#include <iostream>
#include "Board.h"
#include "Tree.h"

using namespace std;

//void Board::setValue(int algorithm, int player)
//pass 1 for Gentry's algorithm
//pass 2 for Vishal's algorithm

//Player 1 is "bottom" player, Player 2 is the "top"

const int GentryAlgorithm = 1;
const int VishalAlgorithm = 2;
const int MinMaxAB = 1;
const int ABSearch = 2;
const int TopPlayer = 2;
const int BottomPlayer = 1;

int main()
{
    Tree playerOneTree;
    Tree playerTwoTree(1, 1, 3, 2);

    playerOneTree.drawRoot();
    playerTwoTree.drawRoot();

    int player = 1;
    bool finished = false;
    int lastMove = 99;

    while (!finished){
        if (player == 1){
            lastMove = playerOneTree.play(lastMove, finished, player);
            playerTwoTree.play(lastMove, finished, player);
        }
        else{
            lastMove = playerTwoTree.play(lastMove, finished, player);
            playerOneTree.play(lastMove, finished, player);
        }
    }
    playerOneTree.drawRoot();


    return 0;
}
