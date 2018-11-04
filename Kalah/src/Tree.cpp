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
   //for(int i = 0; i < 7; i++ )delete root.children[i];
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
