#include <iostream>
#include "minmaxAB.h"
using namespace std;

int minMaxAB(Tree *index, int depth, int player, int useThresh, int passThresh) {
    cout << "MinMax called for depth " << depth << endl;
    int newValue;
    int resultSucc;
    int structure;

    if(index->IsitDeep(depth))
    {
        structure = index->evaluation();
        if(player==2)
        {
            structure=-structure;
        }
        index->setValue(structure);
        return structure;
    }
    int structure1=0;

    for(int i = 0 ; i < 14; i++)
    {
        if(index->stones[i] == NULL)
            continue;
        if(player == 1)
            resultSucc = 2;
        else
            resultSucc = 1;

        structure1 = minMaxAB(index->stones[i],depth+1,resultSucc,-passThresh,-useThresh);
        newValue = -structure1;

        if(newValue > passThresh)
        {
            index->setValue(i);
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
