#include "Tree.h"
#include <iostream>
#include <math.h>

using namespace std;

Tree::Tree()
{
    depth = 3;
    player = 1;
    valueAlgorithm = 1;
    searchAlgorithm = 1;
    totalBoards = 259;

    boards = new Board[totalBoards];

    buildTree();
}

Tree::~Tree()
{
    //cout << "Deleting tree for player " << player << endl;
    delete[] boards;
}

Tree::Tree(int value, int search, int depth, int player){
    this->depth = depth;
    valueAlgorithm = value;
    searchAlgorithm = search;
    this->player = player;

    totalBoards = 1;
    for (int i = 1; i <= depth; i++)
        totalBoards += pow(6, i);
    boards = new Board[totalBoards];
    //cout << "Player " << player << " has " << totalBoards << " boards in tree." << endl;

    buildTree();
}

int Tree::getChildIndex(int parentIndex, int childNumber){
    return (6*parentIndex + childNumber);
}

int Tree::getParentIndex(int childIndex){
    return ((childIndex-1)/6);
}

void Tree::drawRoot(){
    boards[0].draw();
}

//An illegal move creates a child with the same value as the parent.
void Tree::buildTree(){
    //cout << "Building tree for Player " << player << endl;
    int child;

    for (int i = 0; i < depth; i++){
        for (int j = 1; j <= 6; j++){
            child = 6*i+j;
            boards[child] = boards[getParentIndex(child)];
            if (boards[child].isLegal(j, player))
                boards[child].move(j, player);
        }
    }
    //cout << "Tree done." << endl;
    return;
}

void Tree::minMaxAB() {
//Algorithm: MINIMAX-A-B( Position, Depth, Player, Use-Thresh, Pass-Thresh )
//1. If DEEP-ENOUGH(Position, Depth), then return the structure
//VALUE = STATlC (Position, Player);
//PATH = nil
//2. Otherwise, generate one more ply of the tree by calling the function MOVE- 	GEN(Position, Player) and setting SUCCESSORS to the list it returns.
//3.If SUCCESSORS is empty, there are no moves to be made; return the same structure that 	would have been returned if DEEP-ENOUGH had returned TRUE.
//4. If SUCCESSORS is not empty, then go through it, examining each element and keeping 	track of the best one. This is done as follows.
//For each clement SUCC of SUCCESSORS:
//(a) Set RESULT-SUCC to
//MINIMAX-A-B(SUCC, Depth + 1, OPPOSlTE (Player),
//- Pass-Thresh, - Use-Thresh).
//(b) Set NEW-VALUE to - VALUE(RESULT-SUCC).
//(c) If NEW-VALUE> Pass-Thresh, then we have found a successor that is better than any that have
//been examined so far. Record this by doing the following.
//(i) Set Pass-Thresh to NEW-VALUE.
//(ii) The best known path is now from CURRENT to SUCC and then on to the appropriate path
//from SUCC as determined by the recursive call to MINIMAX-A-B. So set BEST-PATH to
//the result of attaching SUCC to the front of PATH(RESULT-SUCC).
//(d) If Pass-Thresh (reflecting the current best value) is not better than Use-Thresh, then we should
//stop examining this branch. But both thresholds and values have been inverted. So if Pass-Thresh
//>= Use-Thresh, then return immediately with the value
// VALUE = Pass-Thresh
// PATH = BEST-PATH
//5. Return the structure
//VALUE = Pass-Thresh
//PATH = BEST-PATH

}
