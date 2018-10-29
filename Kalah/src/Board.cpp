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

void Board::move(int hole){
    int stones = holes[hole];
    holes[hole] = 0;
    hole += 1;
    while (stones > 0){
        holes[hole]++;
        hole = (hole + 1)%14;
        stones--;
    }
    return;
}
