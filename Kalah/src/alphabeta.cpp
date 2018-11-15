//#include "alphabeta.h"

#include "Tree.h"
#include<iostream>
using namespace std;
int alphabeta(Tree *node, int depth, int player, int alpha, int beta)
{
    //Initial Condition -> node is a leaf node
    if(node->IsitDeep(depth))
        return node->evaluation() ;
    if (player == 1 )
    {
        int bestVal = -100,value;
        for(int i=0;i < 6 ; i++ )
        {
            if(node->stones[i]== NULL)
                continue;
            value = alphabeta(node->stones[i], depth+1, node->player, alpha, beta);
            bestVal = ( bestVal > value) ? bestVal : value;
            alpha = ( alpha > bestVal) ? alpha : bestVal;
            if (beta <= alpha)
                break;
        }
        node->setValue(bestVal);
        return bestVal;
    }
    else
    {
        int bestVal = +100,value;
        for(int i=7; i < 14 ; i++ )
        {
            if(node->stones[i]== NULL)
                continue;
            value = alphabeta(node->stones[i], depth+1, node->player, alpha, beta);
            bestVal = ( bestVal < value) ? bestVal : value;
            beta = ( beta < bestVal) ? beta : bestVal;
            if (beta < alpha)
                break;
        }
        node->setValue(bestVal);
        return bestVal;
    }
}
