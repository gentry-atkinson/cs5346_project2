#ifndef TREE_H
#define TREE_H

#include "Board.h"


class Tree
{
    public:
        Tree();
        Tree(int value, int search, int depth, int player);
        ~Tree();
        int play(int lastMove, bool * finished);

    private:

        int depth;
        int player;
        int valueAlgorithm;
        int searchAlgorithm;
        Board * boards;
        int totalBoards;

        int getChildIndex(int parentIndex, int childNumber);
        int getParentIndex(int childIndex);
        void buildTree();
        void minMaxAB();
        void aBSearch();

};

#endif // TREE_H
