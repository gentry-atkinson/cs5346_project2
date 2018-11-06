#include "Board.h"
#include <iostream>

using namespace std;

Board::Board()
{
    value = 0;
    finished = false;
}

Board::Board(const Board& toCopy){
    for (int i = 0; i < 14; i++)
        holes[i] = toCopy.holes[i];
    value = toCopy.value;
    finished = toCopy.finished;
}

Board::~Board()
{
}

void Board::draw(){
    //line 1
    cout << "P1 : ";
    for(int i=(2*6); i>6; i--)
    {
        if (i < 10) {
            cout <<i<<" |";
        } else {
            cout <<i<<"|";
        }
    }
    cout<<endl;


    //line 2
    cout << " ----";
    for(int i=6; i>0; i--)
    {
        cout << "---";
    }
    cout << "---" <<  endl;


    //line 3
    cout << " |  |";
    for(int i=(2*6); i>6; i--)
    {
        cout << holes[i];
        if (holes[i]<10)
        {
            cout << " |";
        }
        else
        {
            cout << "|";
        }
    }
    cout << "  |" << endl;


    //line 4
    cout << " |" << holes[(2*6+1)];
    if (holes[2*6+1] < 10)
    {
        cout << " |";
    } else {
        cout << "|";
    }
    for(int i=6; i>1; i--)
    {
        cout << "--+";
    }
    cout << "--|" << holes[6];
    if (holes[6]<10)
    {
        cout << " |";
    }
    else
    {
        cout << "|";
    }
    cout << endl;


    //line 5
    cout << " |  |";for(int i=0; i<6; i++)
    {
        cout << holes[i];
        if (holes[i]<10)
        {
            cout << " |";
        }
        else
        {
            cout << "|";
        }
    }
    cout << "  |" << endl;


    //line 6
    cout << " ----";
    for(int i=6; i>0; i--)
    {
        cout << "---";
    }
    cout << "---" << endl;


    //line 7
    cout << "P2 : ";
    for(int i=0; i<6; i++)
    {
        if (i < 10)
        {
            cout <<i<<" |";
        }
        else
        {
            cout <<i<<"|";
        }
    } cout<<endl;


    return;
}



int Board::move(int hole, int player){
    int sum1, sum2;
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

    //if one player's holes are empty, game is over
    for (int i = 1; i < 7; i++)
        sum1 += holes[i];
    for (int i = 8; i < 14; i++)
        sum2 += holes[i];
    if (sum1 == 0){
        holes[0] += sum2;
        for (int i = 8; i < 14; i++)
            holes[i] = 0;
        finished = true;
        return 0;
    }
    if (sum2 == 0){
        holes[7] += sum2;
        for (int i = 1; i < 7; i++)
            holes[i] = 0;
        finished = true;
        return 0;
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


void Board::setValue(int newValue){
    value = newValue;
}

int Board::getValue() {return value;}

int Board::gentryValue(int player){
    //Player 1 = bottom player
    //Player 2 = top player

    //Tuning Parameters
    int emptyRightScaling = 1;
    int emptyCupScaling = 1;
    int scoreScaling = 5;
    int moveAgainCupsScaling = 2;
    int moreStonesScaling = 1;

    int value = 0, sum1 = 0, sum2 = 0;
    switch (player) {
        case 1:
            //keeping right hand hole empty is good
            if (holes[6] == 0) value += emptyRightScaling;
            if (holes[13] == 0) value -= emptyRightScaling;
            //an empty cup should add the value of the oposite one
            for (int i = 1; i < 7; i++)
                if (holes[i] == 0) value += holes[14 - i] * emptyCupScaling;
            for (int i = 8; i < 14; i++)
                if (holes[i] == 0) value -= holes[14 - i] * emptyCupScaling;
            //scoring is good
            value += holes[7] * scoreScaling;
            value -= holes[0] * scoreScaling;
            //check for "move again" cups
            for (int i = 1; i < 7; i++)
                if (holes[i] == (7-i)) value += moveAgainCupsScaling;
            for (int i = 8; i < 14; i++)
                if (holes[i] == (i-7)) value -= moveAgainCupsScaling;
            //having more stones on my side is good-ish
            for (int i = 1; i < 7; i++) sum1 += holes[i];
            for (int i = 8; i < 14; i++) sum2 += holes [i];
            if (sum1 > sum2) value += moreStonesScaling;
            else if (sum2 > sum1) value -= moreStonesScaling;
            break;
        case 2:
            //keeping right hand hole empty is good
            if (holes[6] == 0) value -= emptyRightScaling;
            if (holes[13] == 0) value += emptyRightScaling;
            //an empty cup should add the value of the oposite one
            for (int i = 1; i < 7; i++)
                if (holes[i] == 0) value -= holes[14 - i] * emptyCupScaling;
            for (int i = 8; i < 14; i++)
                if (holes[i] == 0) value += holes[14 - i] * emptyCupScaling;
            //scoring is good
            value -= holes[7] * scoreScaling;
            value += holes[0] * scoreScaling;
            //check for "move again" cups
            for (int i = 1; i < 7; i++)
                if (holes[i] == (7-i)) value -= moveAgainCupsScaling;
            for (int i = 8; i < 14; i++)
                if (holes[i] == (i-7)) value += moveAgainCupsScaling;
            //having more stones on my side is good-ish
            for (int i = 1; i < 7; i++) sum1 += holes[i];
            for (int i = 8; i < 14; i++) sum2 += holes [i];
            if (sum1 > sum2) value -= moreStonesScaling;
            else if (sum2 > sum1) value += moreStonesScaling;
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

    return 0;


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

bool Board::isFinished(){
    return finished;
}

int Board::getScore1(){
    return holes[7];
}

int Board::getScore2(){
    return holes[0];
}

Board& Board::operator= (const Board& other){
    if (this == &other) return *this;
    for (int i = 0; i < 14; i++)
        holes[i]= other.holes[i];
    value = other.value;
    finished = other.finished;
    return *this;
}

