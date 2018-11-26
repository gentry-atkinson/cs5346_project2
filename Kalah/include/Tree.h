#ifndef TREE_H
#define TREE_H

#include "Board.h"


class Tree
{
    public:
        //constructors and destructors
        Tree();
        Tree(int, int, int, char);
        virtual ~Tree();

        //getters and setters
        bool getFinished();
        int getAScore();
        int getBScore();
        int getTotalBoards();
        long int getNodesVisited();

        //play function updates tree
        void play(char&, char&, int&);
        //draw the root board in tree
        void draw();

        static const int MINMAXAB = 1;
        static const int ALPHABETA = 2;
        static const int GENTRY = 1;
        static const int VISHAL = 2;
        static const int FIRST_MOVE = 'F';


    private:
        int searchAlg;
        int valueAlg;
        int maxDepth;
        int totalBoards;
        char player;
        Board * boards;
        long int nodesVisited;

        static const int NUM_HOLES = 6;

        int getChild(int, int);
        int getParent(int);
        int getTier(int);

        void buildTree();
        int alphabeta(int, int, char, int, int);
        int minMaxAB(int, int , char , int , int);

        int chooseBestMove();
};

#endif // TREE_H
