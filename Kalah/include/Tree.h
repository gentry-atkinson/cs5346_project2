#ifndef TREE_H
#define TREE_H

#include "Board.h"

struct boardNode{
    Board* board;
    boardNode * children[6];
};


class Tree
{
    public:
        Tree();
        Tree(int value, int search, int depth, int player);
        ~Tree();
        int play(int lastMove, bool * finished);

    private:

        int depth;
        boardNode * root;
        int player;
        int valueAlgorithm;
        int searchAlgorithm;

        void buildTree();
        void minMaxAB();
        void aBSearch();

};

#endif // TREE_H
