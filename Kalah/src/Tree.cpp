#include "Tree.h"

Tree::Tree()
{
    depth = 3;
    player = 1;
    valueAlgorithm = 1;
    searchAlgorithm = 1;
    boards[259];
    totalBoards = 259;

    buildTree();
}

Tree::~Tree()
{
   delete[] boards;
}

Tree::Tree(int value, int search, int depth, int player){
    this->depth = depth;
    valueAlgorithm = value;
    searchAlgorithm = search;
    this->player = player;

    totalBoards = 1;
    for (int i = 1; i <= depth; i++)
        totalBoards += 6^i;
    boards = new Board[totalBoards];

    buildTree();
}

int Tree::getChildIndex(int parentIndex, int childNumber){
    return (6*parentIndex + childNumber);
}

int Tree::getParentIndex(int childIndex){
    return ((childIndex-1)/6);
}

//TODO: figure this shit out
void Tree::buildTree(){
    int child;
    for (int i = 0; i < depth; i++){
        for (int j = 1; j <= 6; j++){
            child = 6*i+j;
            boards[child] = boards[getParentIndex(child)];
            if (boards[child].isLegal(j, player))
                boards[child].move(j, player);
        }
    }
    return;
}
