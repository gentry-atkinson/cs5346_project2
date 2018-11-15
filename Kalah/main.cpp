#include <iostream>
#include <stdio.h>
#include "Board.h"
#include "Tree.h"

using namespace std;

////void Board::setValue(int algorithm, int player)
////pass 1 for Gentry's algorithm
////pass 2 for Vishal's algorithm
//
////Player 1 is "bottom" player, Player 2 is the "top"
//
//const int GentryAlgorithm = 1;
//const int VishalAlgorithm = 2;
//const int MinMaxAB = 1;
//const int ABSearch = 2;
//const int TopPlayer = 2;
//const int BottomPlayer = 1;
//
//int main()
//{
//    Tree playerOneTree;
//    Tree playerTwoTree(1, 1, 3, 2);
//
//    playerOneTree.drawRoot();
//    playerTwoTree.drawRoot();
//
//    int player = 1;
//    bool finished = false;
//    int lastMove = 99;
//
//    while (!finished){
//        if (player == 1){
//            lastMove = playerOneTree.play(lastMove, finished, player);
//            playerTwoTree.play(lastMove, finished, player);
//        }
//        else{
//            lastMove = playerTwoTree.play(lastMove, finished, player);
//            playerOneTree.play(lastMove, finished, player);
//        }
//
//        getchar();
//    }
//    playerOneTree.drawRoot();

int main()
{
    int count=0;
    Tree T;
    Board *kb = new Board();
    cout << "Initial board " << endl;
    kb->draw();
    char win = kb->isFinished();
    char player = 'A';
    //int start_s = clock();
    while(win == 'N')
    {
        count++;
        Tree *head = new Tree(player);
        head->copyBoardStatus(*kb);
        cout << "Player" << player <<" Turn :"<< endl;
        T.alphabeta(head,0,1,1000,-1000);
        int hole = head->getHole();
        player = kb->move(hole,player);
        kb->draw();
        win = kb->isFinished();
    }
    kb->draw();
    return 0;
}
//    return 0;
//}
