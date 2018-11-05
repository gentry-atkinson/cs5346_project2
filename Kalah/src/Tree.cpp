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
