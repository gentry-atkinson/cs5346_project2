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

//TODO: print it more pretty
void Board::draw(){
    cout << "\t" << holes[13] << " " << holes[12] << " " << holes[11] << " " << holes[10] << " " << holes[9] << " " << holes[8] << endl;
    cout << holes[0] << "\t\t\t" << holes[7] << endl;
    cout << "\t" << holes[1] << " " << holes[2] << " " << holes[3] << " " << holes[4] << " " << holes[5] << " " << holes[6] << endl << endl;
    return;
}

//TODO: check for captures
int Board::move(int hole, int player){
    int stones = holes[hole];

    //empty moved cup
    holes[hole] = 0;

    //distribute stones
    hole += 1;
    while (stones > 0){
        holes[hole]++;
        hole = (hole + 1)%14;
        //skip oponents kalah
        if (player == 1 && hole == 0) hole++;
        if (player == 2 && hole == 7) hole++;
        stones--;
    }
    //check for repeat turn
    if (player == 1 && hole == 7) return player;
    if (player == 2 && hole == 0) return player;

    //if no repeat turn, then switch player
    return player==1?2:1;
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

int Board::vishalValue(){

    int store[5];
    int counter=0;

    //So if i find an empty pit in my end and see how many stones are present in the opposite end,
    // grab all the stones in the next move;

    for(int i=1;i<7;i++)
    {
        if(holes[i]==0)
        {
            store[counter]=i;
            counter++;
        }
    }
    cout<<"---------"<<endl;
    for(int i=0;i<counter;i++)
    {

        cout<<store[i]<<" "; // found empty pits in my end;
    }
    cout<<endl<<"---------"<<endl;

    int oppvalue=0;
    int high =8;
    for(int i=13; i>7 ; i--)
    {
        if(holes[i]>holes[high])
            high=i;
    }
    cout<<endl<<"Highest value in the opp end"<<endl<<high<<endl;

    //check for the opp end ascending order and try to attack!






}

bool Board::isLegal(int moveNumber, int player){
    //players cannot play other player's cups
    if (player == 1 && moveNumber > 7) return false;
    if (player == 2 && moveNumber < 7) return false;
    //neither player can move kalahs
    if (moveNumber == 0 || moveNumber == 7) return false;
    //player cannot move an empty hole
    if (holes[moveNumber] == 0) return false;
    //move is legal
    return true;
}
