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
    char player;
    Board bx;
    Tree *stones[6];
    
    Tree();
    Tree(char);
    
    // Tree(int value, int search, int depth, int player);
    // ~Tree();
    // int play(int lastMove, bool& finished, int& player);
    //void drawRoot();
    
    void create_node(char);
    void set_value(int);
    void grab_all_stones();//add all children
    bool IsitDeep(int );
    void print(Tree *,int );
    int evaluation();
    int getHole();
    void copyBoardStatus(Board b);
    
    
    //private:
    
    int depth;
    
    int valueAlgorithm;
    int searchAlgorithm;
    Board * boards;
    int totalBoards;
    int getChildIndex(int parentIndex, int childNumber);
    int getParentIndex(int childIndex);
    void buildTree();
    //int minMaxAB(int index, int depth, int player, int useThresh, int passThresh);
    //int minMaxAB(Tree *index, int depth, int player, int useThresh, int passThresh);
    //void setValue(int );
    
    
    //int alphabeta(Tree *node, int depth, int player, int alpha, int beta);
    
    
    
};

#endif // TREE_H
