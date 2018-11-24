#include <iostream>

#include "Tree.h"

using namespace std;

int main()
{
    Tree * tree1, * tree2;
    char lastPlayer, currentPlayer;
    int lastMove, aScore, bScore, depth;

    //Case 1: Vishal vs. Gentry with MinMaxAB at depth 3
    depth = 2;
    tree1 = new Tree(Tree::MINMAXAB, Tree::GENTRY, depth, 'A');
    tree2 = new Tree(Tree::MINMAXAB, Tree::VISHAL, depth, 'B');
    currentPlayer = 'A';
    lastPlayer = Tree::FIRST_MOVE;
    lastMove = 0;

    while(! tree1->getFinished() && ! tree2->getFinished()){
        tree1->play(currentPlayer, lastPlayer, lastMove);
        tree2->play(currentPlayer, lastPlayer, lastMove);
    }

    aScore = tree1->getAScore();
    bScore = tree2->getBScore();

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

    return 0;
}
