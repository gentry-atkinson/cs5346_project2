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
    int value,stone;
    Tree();
    Tree(int);
    Tree(int value, int search, int depth, int player);
    ~Tree();
    int play(int lastMove, bool& finished, int& player);
    void drawRoot();
    Tree *stones[14];
    Board bx;
    void grab_all_stones();

    int getHole();
    void print(Tree *,int );


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
    //int minMaxAB(int index, int depth, int player, int useThresh, int passThresh);
    int minMaxAB(Tree *index, int depth, int player, int useThresh, int passThresh);
    void setValue(int );
    bool IsitDeep(int );
    int evaluation();
    int alphabeta(Tree *node, int depth, int player, int alpha, int beta);
    void copyBoardStatus(Board b);


};

#endif // TREE_H
