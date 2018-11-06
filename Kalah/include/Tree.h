#ifndef TREE_H
#define TREE_H

#include "Board.h"

//TODO: implement MinMaxAB
//TODO: implement ABSearch
//TODO: add MinMaxAB and ABSearch to buildTree
//TODO: implement play function

class Tree
{
    public:
        Tree();
        Tree(int value, int search, int depth, int player);
        ~Tree();
        int play(int lastMove, bool& finished, int& player);
        void drawRoot();

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
        int minMaxAB(int index, int depth, int player, int useThresh, int passThresh);
        void aBSearch();

};

#endif // TREE_H
