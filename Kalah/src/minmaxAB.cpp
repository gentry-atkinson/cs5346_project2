#include <iostream>
#include "minmaxAB.h"
using namespace std;

int minMaxAB(Tree *index, int depth, char player, int useThresh, int passThresh) {
    cout << "MinMax called for depth " << depth << endl;
    int newValue;
    char resultSucc;
    int structure;
    
    if(index->IsitDeep(depth))
    {
        structure = index->evaluation();
        if(player=='B')
        {
            structure=-structure;
        }
        index->set_value(structure);
        return structure;
    }
    int structure1=0;
    
    for(int i = 0 ; i < 6; i++)
    {
        if(index->stones[i] == NULL)
            continue;
        if(player == 'A')
            resultSucc = 'B';
        else
            resultSucc = 'A';
        
        structure1 = minMaxAB(index->stones[i],depth+1,resultSucc,-passThresh,-useThresh);
        newValue = -structure1;
        
        if(newValue > passThresh)
        {
            index->set_value(i);
            passThresh = newValue;
        }
        if(passThresh >= useThresh)
        {
            structure1=passThresh;
            return structure1;
        }
    }
    structure1=passThresh;
    return structure1;
}
