#include "Tree.h"

Tree::Tree()
{
    depth = 3;
    root = new boardNode;
    player = 1;
    valueAlgorithm = 1;
    searchAlgorithm = 1;

    buildTree();
}

Tree::~Tree()
{
   for(int i = 0; i < 7; i++ )delete root->children[i];
   delete root;
}

Tree::Tree(int value, int search, int depth, int player){
    this->depth = depth;
    root = new boardNode;
    valueAlgorithm = value;
    searchAlgorithm = search;
    this->player = player;

    buildTree();
}

//TODO: figure this shit out
void Tree::buildTree(){
    int currentDepth = 0;
    int currentChild = 0;
    boardNode * currentBoard = root;
    boardNode * pointerList[depth];
    pointerList[0] = root;

    while (currentDepth < depth){
        for (int i = 0; i < 6; i++){
            if (*currentBoard.board.isLegal(i, player);
                *currentBoard.board.children[i] = new Board(currentBoard.board);
                *currentBoard.board.children[i].move(i);
            }
            else {
                *currentBoard.board.children[i] = NULL;
            }
        }
        pointerList[depth] = currentBoard;
        currentBoard = *currentBoard.children[currentChild];
    }
}
