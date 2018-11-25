#include <iostream>
#include <cstdio>

#include "Tree.h"

using namespace std;

int main()
{
    Tree * tree1, * tree2;
    char lastPlayer, currentPlayer;
    int lastMove, aScore, bScore, depth, turn;

    //Case 1: Vishal vs. Gentry with MinMaxAB at depth 3
    depth = 2;
    tree1 = new Tree(Tree::MINMAXAB, Tree::GENTRY, depth, 'A');
    tree2 = new Tree(Tree::MINMAXAB, Tree::VISHAL, depth, 'B');
    currentPlayer = 'A';
    lastPlayer = Tree::FIRST_MOVE;
    lastMove = 0;
    turn = 0;

    while(! tree1->getFinished() && ! tree2->getFinished()){
        tree1->play(currentPlayer, lastPlayer, lastMove);
        tree2->play(currentPlayer, lastPlayer, lastMove);
        turn++;
        //tree1->draw();
        //tree2->draw();
        //getchar();
    }

    aScore = tree1->getAScore();
    bScore = tree2->getBScore();

    cout << turn << " turns played" << endl;

    if (aScore > bScore){
        cout << "Gentry wins " << aScore << " to " << bScore << endl;
    }
    else if (bScore > aScore){
        cout << "Vishal wins " << bScore << " to " << aScore << endl;
    }
    else {
        cout << "Tie game." << endl;
    }

    delete tree1;
    delete tree2;
    //Case 2: Vishal vs. Gentry with AlphaBeta at depth 3
    //Case 3: MinMax vs. AlphaBeta with Vishal at depth 3
    //Case 4: MinMax vs. AlphaBeta with Gentry at depth 3

    //Case 5: Vishal vs. Gentry with MinMaxAB at depth 5
    //Case 6: Vishal vs. Gentry with AlphaBeta at depth 5
    //Case 7: MinMax vs. AlphaBeta with Vishal at depth 5
    //Case 8: MinMax vs. AlphaBeta with Gentry at depth 5

    //Case 9: Vishal vs. Gentry with MinMaxAB at depth 10
    //Case 10: Vishal vs. Gentry with AlphaBeta at depth 10
    //Case 11: MinMax vs. AlphaBeta with Vishal at depth 10
    //Case 12: MinMax vs. AlphaBeta with Gentry at depth 10

    return 0;
}
