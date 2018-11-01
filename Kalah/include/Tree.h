#ifndef TREE_H
#define TREE_H

#include "Board.h"

struct boardNode{
    Board board;
    Board * children[];
};


class Tree
{
    public:
        Tree();
        virtual ~Tree();

    protected:

    private:

    int depth;
    boardNode * root;

};

#endif // TREE_H
