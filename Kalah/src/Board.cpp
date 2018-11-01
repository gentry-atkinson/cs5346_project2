#include "Board.h"
#include <iostream>

using namespace std;

Board::Board()
{

}

Board::~Board()
{
    //dtor
}

void Board::draw(){
    cout << "\t" << holes[13] << " " << holes[12] << " " << holes[11] << " " << holes[10] << " " << holes[9] << " " << holes[8] << endl;
    cout << holes[0] << "\t\t\t" << holes[7] << endl;
    cout << "\t" << holes[1] << " " << holes[2] << " " << holes[3] << " " << holes[4] << " " << holes[5] << " " << holes[6] << endl << endl;
    return;
}

void Board::move(int hole, int player){
    int stones = holes[hole];
    holes[hole] = 0;
    hole += 1;
    while (stones > 0){
        holes[hole]++;
        hole = (hole + 1)%14;
        if (player == 1 && hole == 0) hole++;
        if (player == 2 && hole == 7) hole++;
        stones--;
    }
    return;
}

void Board::setValue(int algorithm, int player){
    switch (algorithm) {
    case 1:
        value = gentryValue(player);
        break;
    case 2:
        value = vishalValue();
        break;
    }
}

int Board::getValue() {return value;}

int Board::gentryValue(int player){
    //Player 1 = bottom player
    //Player 2 = top player
    int value = 0, sum1 = 0, sum2 = 0;
    switch (player) {
    case 1:
        //keeping right hand hole empty is good
        if (holes[6] == 0) value += 1;
        if (holes[13] == 0) value -= 1;
        //an empty cup should add the value of the oposite one
        for (int i = 1; i < 7; i++)
            if (holes[i] == 0) value += holes[14 - i];
        for (int i = 8; i < 14; i++)
            if (holes[i] == 0) value -= holes[14 - i];
        //scoring is good
        value += holes[7];
        value -= holes[0];
        //check for "move again" cups
        for (int i = 1; i < 7; i++)
            if (holes[i] == (7-i)) value += 1;
        for (int i = 8; i < 14; i++)
            if (holes[i] == (i-7)) value -= 1;
        //having more stones on my side is good-ish
        for (int i = 1; i < 7; i++) sum1 += holes[i];
        for (int i = 8; i < 14; i++) sum2 += holes [i];
        if (sum1 > sum2) value +=1;
        else if (sum2 > sum1) value -= 1;
        break;
    case 2:
        //keeping right hand hole empty is good
        if (holes[6] == 0) value -= 1;
        if (holes[13] == 0) value += 1;
        //an empty cup should add the value of the oposite one
        for (int i = 1; i < 7; i++)
            if (holes[i] == 0) value -= holes[14 - i];
        for (int i = 8; i < 14; i++)
            if (holes[i] == 0) value += holes[14 - i];
        //scoring is good
        value -= holes[7];
        value += holes[0];
        //check for "move again" cups
        for (int i = 1; i < 7; i++)
            if (holes[i] == (7-i)) value -= 1;
        for (int i = 8; i < 14; i++)
            if (holes[i] == (i-7)) value += 1;
        //having more stones on my side is good-ish
        for (int i = 1; i < 7; i++) sum1 += holes[i];
        for (int i = 8; i < 14; i++) sum2 += holes [i];
        if (sum1 > sum2) value -= 1;
        else if (sum2 > sum1) value += 1;
        break;
    default:
        cerr << "Bad player value passed to gentryValue()" << endl;
    }
    return value;
}

int Board::vishalValue(){;}
