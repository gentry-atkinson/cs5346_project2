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
    int value;
    Tree();
    Tree(int value, int search, int depth, int player);
    ~Tree();
    int play(int lastMove, bool& finished, int& player);
    void drawRoot();
    Tree *children[14];
    Board bx;
    
    
    //private:
    
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
    void setValue(int );
    bool IsitDeep(int );
    int evaluation();
    int alphabeta(Tree *node, int depth, int player, int alpha, int beta);
    
    
};

#endif // TREE_H
