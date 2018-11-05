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
    int nextChild = 0;
    boardNode * currentBoard = root;
    boardNode * pointerList[depth];
    pointerList[0] = root;
    /*
    while (currentDepth < depth){
        for (int i = 0; i < 6; i++){
            if (currentBoard->board.isLegal(i, player));
                currentBoard->children[i].board = new Board(currentBoard->board);
                currentBoard->children[i].board.move(i);
            }
            else {
                currentBoard->board.children[i] = NULL;
            }
        }
        switch(nextChild){
        case 0:
            pointerList[currentDepth] = currentBoard;
            currentBoard = *currentBoard.children[nextChild];
            currentDepth += 1;
            nextChild += 1;
            break;
        }
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            currentBoard = pointerList[depth-1];
            currentBoard = *currentBoard.children[nextChild];
            if (currentBoard == NULL) continue;
            nextChild += 1;
            break;
        case 6:
            break;
        default:
            cerr << "Bad child in buildTree" << endl;
    }
    */
}
