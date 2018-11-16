//#include "alphabeta.h"


#include<iostream>
#include "Tree.h"
using namespace std;
int alphabeta(Tree *node, int depth, char player, int alpha, int beta)
{
    //Initial Condition -> node is a leaf node
    if(node->IsitDeep(depth))
        return node->evaluation() ;
    if (player == 'A' )
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
        node->set_value(bestVal);
        return bestVal;
    }
    else
    {
        int bestVal = +100,value;
        for(int i=0; i < 6 ; i++ )
        {
            if(node->stones[i]== NULL)
                continue;
            value = alphabeta(node->stones[i], depth+1, node->player, alpha, beta);
            bestVal = ( bestVal < value) ? bestVal : value;
            beta = ( beta < bestVal) ? beta : bestVal;
            if (beta < alpha)
                break;
        }
        node->set_value(bestVal);
        return bestVal;
    }
}
