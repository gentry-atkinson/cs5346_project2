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
    int value = 0;
    switch (player) {
    case 1:
        //if holes
        break;
    case 2:
        break;
    default:
        cerr << "Bad player value passed to gentryValue()" << endl;
    }
    return value;
}

int Board::vishalValue(){;}
