#include "Board.h"
#include <iostream>
#include <iomanip>

using namespace std;

Board::Board()
{

    for(int i = 0 ; i < 6; i++)
    {
        playerAHoles[i] = 6;
        playerBHoles[i] = 6;
    }

    numberOfSlots = 5;
    playerAScore = 0,playerBScore = 0;
    playerPtr = NULL;

    //value = 0;
    finished = false;
}

Board::Board(const Board& toCopy){
    for (int i = 0; i < 14; i++)
        holes[i] = toCopy.holes[i];
    //    value = toCopy.value;
    finished = toCopy.finished;
}


Board::Board(int p1[],int p2[],int a, int b)
{

    for(int i=0;i<6;i++)
    {
        playerAHoles[i]=p1[i];
        playerBHoles[i]=p2[i];
    }
    playerAScore = a;
    playerBScore = b;
}

Board::~Board()
{
}

Board :: Board(const Board * b)
{

    for(int i=0;i<6;i++)
    {

        this->playerAHoles[i]=b->playerAHoles[i];
        this->playerBHoles[i]=b->playerBHoles[i];
    }
    this->playerAScore=b->playerAScore;
    this->playerBScore=b->playerBScore;

}


void Board::draw()
{
    cout << endl;
    cout << "\t\t     P1 or PLAYER A";
    cout << endl;
    cout << "Hole no: \t |";
    for(int i = 5 ; i >= 0 ; i--)
    {
        cout << i << setw(2) << "|";
        cout << " ";
    }
    cout<<endl;
    cout << "\t\t";
    for(int i = 0 ; i < 25; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << "\t\t" << "|";
    cout << setw(2);

    for(int i = 5 ; i >= 0 ; i--)
    {
        cout << playerAHoles[i] << setw(2) << "|";
        cout << " ";
    }
    cout<<endl;
    cout << "\t\t";
    for(int i = 0 ; i < 25; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << endl;
    cout <<"|" << setw(2) << playerAScore << setw(2)<<"|";
    cout <<"\t\t\t\t\t\t  |" << setw(2) << playerBScore <<setw(2)<< "|";
    cout << endl;
    cout << "\t\t";
    for(int i = 0 ; i < 25; i++)
    {
        cout << "-";
    }

    cout << endl;
    cout << "\t\t" << "|";
    cout << setw(2);

    for(int i = 0 ; i < 6; i++)
    {
        cout << playerBHoles[i] << setw(2) << "|";
        cout << " ";
    }

    cout<<endl;
    cout << "\t\t";
    for(int i = 0 ; i < 25; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << "Hole no: \t |";
    for(int i = 0 ; i < 6; i++)
    {
        cout << i << setw(2) << "|";
        cout << " ";
    }
    cout << endl;
    cout << "\t\t     P2 or PLAYER B";
    cout << endl << endl << endl << endl;
}


//int Board::move(int hole, int player){
//    int sum1 = 0, sum2 = 0;
//    int stones = holes[hole];
//
//    //empty moved cup
//    holes[hole] = 0;
//
//    //distribute stones
//    hole += 1;
//    while (stones > 0){
//        holes[hole]++;
//        hole = (hole + 1)%14;
//        //skip oponents kalah
//        if (player == 1 && hole == 0) hole++;
//        if (player == 2 && hole == 7) hole++;
//        stones--;
//    }
//
//    //if one player's holes are empty, game is over
//    for (int i = 1; i < 7; i++)
//        sum1 += holes[i];
//    for (int i = 8; i < 14; i++)
//        sum2 += holes[i];
//
//    if (sum1 == 0){
//        holes[0] += sum2;
//        for (int i = 8; i < 14; i++)
//            holes[i] = 0;
//        finished = true;
//    }
//    if (sum2 == 0){
//        holes[7] += sum2;
//        for (int i = 1; i < 7; i++)
//            holes[i] = 0;
//        finished = true;
//    }
//
//    //actually, if one player scores with half the stones, game is over
//    if (getScore1() > 36)
//        finished = true;
//    if (getScore2() > 36)
//        finished = true;
//
//    //check for repeat turn
//    if (player == 1 && hole == 7) return player;
//    if (player == 2 && hole == 0) return player;
//
//    //if no repeat turn, then switch player
//    return player==1?2:1;
//}



//Function to move for the P1 or A player
char Board::move_p1(int hole)
{
    int tempPos = hole;
    playerPtr = playerAHoles;
    int numberOfStones = playerPtr[tempPos];
    playerPtr[tempPos] = 0;
    int opponentPos, opponentStones;

    tempPos++;
    while(numberOfStones > 0)
    {
        if(tempPos >= 0 && tempPos <= 5)
        {
            if(numberOfStones == 1)
            {
                numberOfStones--;
                opponentPos = numberOfSlots - tempPos;
                if(playerPtr[tempPos] == 0 && playerBHoles[opponentPos] > 0)
                {
                    playerPtr = playerBHoles;
                    opponentStones = playerPtr[opponentPos];
                    playerPtr[opponentPos] = 0;
                    playerAScore += opponentStones + 1;
                    if(numberOfStones == 0)
                        return 'B';
                }
                else
                {
                    playerPtr[tempPos] += 1;
                    if(numberOfStones == 0)
                        return 'B';
                }
            }
            else if(numberOfStones > 1)
            {
                numberOfStones--;
                playerPtr[tempPos]+=1;
            }
        }
        else if(tempPos == 6 && numberOfStones >= 1)
        {
            numberOfStones--;
            playerAScore += 1;
            if(numberOfStones == 0)
                return 'A';
        }
        else if(tempPos > 6 && tempPos <= 12)
        {
            playerPtr = playerBHoles;
            numberOfStones--;
            playerPtr[tempPos-7] += 1;
            if(numberOfStones == 0)
                return 'B';
        }
        else if(tempPos >= 12)
        {
            tempPos = -1;
            playerPtr = playerAHoles;
        }
        tempPos++;
    }
    return 'B';
}

//Function to move for the P2 or B player
char Board::move_p2(int hole)
{
    int tempPos = hole;
    playerPtr = playerBHoles;
    int numberOfStones = playerPtr[tempPos];
    playerPtr[hole] = 0;
    int opponentPos, opponentStones;

    tempPos++;
    while(numberOfStones > 0)
    {
        if(tempPos >= 0 && tempPos <= 5)
        {
            if(numberOfStones == 1)
            {
                numberOfStones--;
                opponentPos = numberOfSlots - tempPos;
                if(playerPtr[tempPos] == 0)
                {
                    playerPtr = playerAHoles;
                    opponentStones = playerPtr[opponentPos];
                    playerPtr[opponentPos] = 0;
                    playerBScore += opponentStones + 1;
                    if(numberOfStones == 0)
                        return 'A';
                }
                else
                {
                    playerPtr[tempPos] += 1;
                    if(numberOfStones == 0)
                        return 'A';
                }
            }
            else if(numberOfStones > 1)
            {
                numberOfStones--;
                playerPtr[tempPos]+=1;
            }
        }
        else if(tempPos == 6 && numberOfStones >= 1)
        {
            numberOfStones--;
            playerBScore += 1;
            if(numberOfStones == 0)
                return 'B';
        }
        else if(tempPos > 6 && tempPos <= 12)
        {
            playerPtr = playerAHoles;
            numberOfStones--;
            playerPtr[tempPos-7] += 1;
            if(numberOfStones == 0)
                return 'A';
        }
        else if(tempPos >= 12)
        {
            tempPos = -1;
            playerPtr = playerBHoles;
        }
        tempPos++;
    }
    return 'A';
}



char Board::move(int hole,char player)
{
    char v;
    if(player == 'A')
        v = move_p1(hole);
    else
        v = move_p2(hole);
    return v;
}










//void Board::setValue(int algorithm, int player){
//    switch (algorithm) {
//        case 1:
////            value = gentryValue(player);
//            break;
//        case 2:
// //           value = vishalValue(player);
//            break;
//    }
//}


//void Board::setValue(int newValue){
//        value = newValue;
//}
//
//int Board::getValue() {return value;}

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

int Board::vishalValue(int player){

    int store1[5];
    int counter=0;
    int score=0;
    int GrabFromEmpty = 200;
    int MakeAscending = 100;
    int search =0;

    //So if i find an empty pit in my end and see how many stones are present in the opposite end,
    // grab all the stones in the next move;

    for(int i=1;i<7;i++)
    {
        if(holes[i]==0)
        {
            store1[counter]=i;
            counter++;
        }
    }
    cout<<"---------"<<endl;
    for(int i=0;i<counter;i++)
    {

        cout<<store1[i]<<" "; // found empty pits in my end;
    }
    cout<<endl<<"---------"<<endl;

    // int oppvalue=0;
    int high =8;
    for(int i=13; i>7 ; i--)
    {
        if(holes[i]>holes[high])
            high=i;
    }
    cout<<endl<<"Highest value in the opp end"<<endl<<high<<endl;
    int size = sizeof(store1)/store1[0];

    switch (player) {
        case 1:
            for(int i=0;i<size;i++)
            {
                score=0;
                search=store1[i];
                if(search ==0)
                {
                    if(holes[search+1]==12 || holes[search+2]==11 || holes[search+3]==10 || holes[search+4]==9||holes[search+5]==8)
                    {
                        score+=GrabFromEmpty;
                    }
                    return score;
                }
                else if(search ==1)
                {
                    if(holes[search+1]==12 || holes[search+2]==11 || holes[search+3]==10 || holes[search+4]==9 || holes[search-1]==1)
                    {
                        score+=GrabFromEmpty;
                    }
                    return score;
                }
                else if(search ==2)
                {
                    if(holes[search+1]==12 || holes[search+2]==11 || holes[search+3]==10||holes[search-1]==1||holes[search-2]==2)
                    {
                        score+=GrabFromEmpty;
                    }
                    return score;
                }
                else if(search ==3)
                {
                    if(holes[search+1]==12 || holes[search+2]==11||holes[search-1]==1||holes[search-2]==2||holes[search-3]==3)
                    {
                        score+=GrabFromEmpty;
                    }
                    return score;
                }
                else if(search ==4)
                {
                    if(holes[search+1]==12 || holes[search-1]==1|| holes[search-2]==2|| holes[search-3]==3|| holes[search-4]==4)
                    {
                        score+=GrabFromEmpty;
                    }
                    return score;
                }
                else if(search ==5)
                {
                    if(holes[search-1]==1|| holes[search-2]==2|| holes[search-3]==3|| holes[search-4]==4 || holes[search-5]==5)
                    {
                        score+=GrabFromEmpty;
                    }
                    return score;
                }
                //Will have to cover the other player's holes as well!

            }
            break;

        default:
            break;
    }




    //check for the opp end ascending order and try to attack!

    return score;


}

//bool Board::isLegal(int moveNumber, int player){
//    //players cannot play other player's cups
//    if (player == 1 && moveNumber > 6) return false;
//    if (player == 2 && moveNumber < 8) return false;
//    //neither player can move kalahs
//    if (moveNumber == 0 || moveNumber == 7) return false;
//    //player cannot move an empty hole
//    if (holes[moveNumber] == 0) return false;
//    //move is legal
//    return true;
//}


bool Board::isLegal(char player,int hole)
{
    if(hole >5 || hole < 0)
        return false;
    if(player == 'A' && playerAHoles[hole] == 0)
    {
        return false;
    }
    else  if(player == 'B' && playerBHoles[hole] == 0)
    {
        return false;
    }
    return true;
}
//bool Board::isFinished(){
//    return finished;
//}

char Board::isFinished()
{
    int p1=0,p2=0,p1Stones=0,p2Stones=0;
    for(int i =0 ;i<6 ;i++)
    {
        if(playerAHoles[i]==0)
        {
            p1++;
        }
        if(playerBHoles[i]==0)
        {
            p2++;
        }
        p1Stones += playerAHoles[i];
        p2Stones += playerBHoles[i];

    }
    if(p1 == 6)
    {
        playerBScore +=p2Stones;
        for(int i = 0 ; i < 6; i++)
        {
            playerBHoles[i] = 0;
        }
        cout<<"P1 has no stones left to play"<<endl;
    }
    if( p2 == 6)
    {
        playerAScore += p1Stones;
        for(int i = 0 ; i < 6 ; i++)
        {
            playerAHoles[i] = 0;
        }
        cout<<"P2 has no stones left to play"<<endl;
    }
    if(playerAScore > 36)//P1 wins
    {
        //cout<<"Player 1 WINS!!!"<<endl;
        return 'A';   // P1 wins
    }
    else if(playerBScore > 36)//P2 Wins
    {
        //cout<<"Player 2 WINS!!!"<<endl;
        return 'B';  // P2 wins
    }
    else if(p1 == 6 || p2 == 6)
    {
        return 'T'; // indicates that a tie occurred
    }
    else//No win
    {
        return 'N';
    }
}

int Board::getScore1(){
    return holes[7];
}

int Board::getScore2(){
    return holes[0];
}

//Board& Board::operator= (const Board& other){
//    if (this == &other) return *this;
//    for (int i = 0; i < 14; i++)
//        holes[i]= other.holes[i];
//   value = other.value;
//    finished = other.finished;
//    return *this;
//}


Board& Board::operator=(const Board& b)
{
    for(int i=0;i<6;i++)
    {
        playerAHoles[i]=b.playerAHoles[i];
        playerBHoles[i]=b.playerBHoles[i];

    }
    numberOfSlots = 5;
    playerAScore=b.playerAScore;
    playerBScore=b.playerBScore;
    playerPtr = NULL;
}

int Board::getAHoles(int i){
    return playerAHoles[i];
}

int Board::getBHoles(int i){
    return playerBHoles[i];
}
