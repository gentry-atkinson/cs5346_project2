#include "Board.h"
#include <iostream>

using namespace std;

//Default Constructor
//Every hole should have the starting number of stones
Board::Board(){
    for(int i = 0; i < NUM_HOLES; i++){
        playerAHoles[i] = NUM_STONES;
        playerBHoles[i] = NUM_STONES;
    }

    playerAScore = 0;
    playerBScore = 0;

    value = -9999;
    finished = false;
}

//Copy Constructor
//The new board should have all the values of the old
Board::Board(const Board& toCopy){
    for(int i = 0; i < NUM_HOLES; i++){
        playerAHoles[i] = toCopy.playerAHoles[i];
        playerBHoles[i] = toCopy.playerBHoles[i];
    }

    playerAScore = toCopy.playerAScore;
    playerBScore = toCopy.playerBScore;

    value = toCopy.value;
    finished = toCopy.finished;
}


Board::~Board(){return;}

char Board::switchPlayer(char oldPlayer){
    if (oldPlayer == 'A') return 'B';
    else if (oldPlayer == 'B') return 'A';
    else
        cerr << "Bad player value passed to switchPlayer" << endl;
        return 'C';
}

//Use Gentry's algorithm to set the value of the board for a player
void Board::gentryValue(char player){
    //Player A = bottom player
    //Player B = top player

    //Tuning Parameters
    int emptyRightScaling = 1;
    int emptyCupScaling = 1;
    int scoreScaling = 3;
    int moveAgainCupsScaling = 2;
    int moreStonesScaling = 1;

    int sumA = 0, sumB = 0;
    value = 0;

    //calculate a score for Player A

    //keeping right hand hole empty is good
    if (playerAHoles[0] == 0) value += emptyRightScaling;
    if (playerBHoles[0] == 0) value -= emptyRightScaling;

    //an empty cup should add the value of the oposite one
    for (int i = 0; i < NUM_HOLES; i++){
        if (playerAHoles[i] == 0) value += playerBHoles[NUM_HOLES - i] * emptyCupScaling;
        if (playerBHoles[i] == 0) value -= playerBHoles[NUM_HOLES - i] * emptyCupScaling;
    }

    //scoring is good
    value += playerAScore * scoreScaling;
    value -= playerBScore * scoreScaling;

    //check for "move again" cups
    for (int i = 0; i < NUM_HOLES; i++){
        if (playerAHoles[i] == (i +1))
            value += moveAgainCupsScaling;
        if (playerBHoles[i] == (i + 1))
            value -= moveAgainCupsScaling;
    }

    //having more stones on my side is good-ish
    for (int i = 0; i < NUM_HOLES; i++){
        sumA += playerAHoles[i];
        sumB += playerBHoles[i];
    }
    if (sumA > sumB) value += moreStonesScaling;
    else if (sumB > sumA) value -= moreStonesScaling;

    //negate the score if the player is B
    if (player == 'A') return;
    else if (player == 'B'){
        value = -1 * value;
        return;
    }
    else {
        cerr << "Bad player value passed to gentryValue()" << endl;
        return;
    }
}

//Use Vishal's algorithm to set the value of the board for a player
void Board::vishalValue(char player){
    int store1[5] = {0};
    int counter=0;
    int score=0;
    int GrabFromEmpty = 200;
    int MakeAscending = 100;
    int search =0;
    int playerNum;

    //So if i find an empty pit in my end and see how many stones are present in the opposite end,
    // grab all the stones in the next move;

    for(int i=0;i<NUM_HOLES;i++)
    {
        if(playerAHoles[i]==0)
        {
            store1[counter]=i;
            counter++;
        }
    }
    //cout<<"---------"<<endl;
    for(int i=0;i<counter;i++)
    {

        //cout<<store1[i]<<" "; // found empty pits in my end;
    }
    //cout<<endl<<"---------"<<endl;

    // int oppvalue=0;
    int high =0;
//    for(int i=NUM_HOLES-1; i>0 ; i--)
//    {
//        if(playerAHoles[i]>playerAHoles[high])
//            high=i;
//    }
//    //cout<<endl<<"Highest value in the opp end"<<endl<<high<<endl;
//    int size = sizeof(store1)/store1[0];
//
//    if (player == 'A') playerNum = 1;
//    else playerNum = 2;
//
//    switch (playerNum) {
//        case 1:
//            for(int i=0;i<size;i++)
//            {
//                score=0;
//                search=store1[i];
//                if(search ==0)
//                {
//                    if(playerAHoles[search+1]==12 || playerAHoles[search+2]==11 || playerAHoles[search+3]==10 || playerAHoles[search+4]==9||playerAHoles[search+5]==8)
//                    {
//                        score+=GrabFromEmpty;
//                    }
//                    value = score;
//                    return;
//                }
//                else if(search ==1)
//                {
//                    if(playerAHoles[search+1]==12 || playerAHoles[search+2]==11 || playerAHoles[search+3]==10 || playerAHoles[search+4]==9 || playerAHoles[search-1]==1)
//                    {
//                        score+=GrabFromEmpty;
//                    }
//                    value = score;
//                    return;
//                }
//                else if(search ==2)
//                {
//                    if(playerAHoles[search+1]==12 || playerAHoles[search+2]==11 || playerAHoles[search+3]==10||playerAHoles[search-1]==1||playerAHoles[search-2]==2)
//                    {
//                        score+=GrabFromEmpty;
//                    }
//                    value = score;
//                    return;
//                }
//                else if(search ==3)
//                {
//                    if(playerAHoles[search+1]==12 || playerAHoles[search+2]==11||playerAHoles[search-1]==1||playerAHoles[search-2]==2||playerAHoles[search-3]==3)
//                    {
//                        score+=GrabFromEmpty;
//                    }
//                    value = score;
//                    return;
//                }
//                else if(search ==4)
//                {
//                    if(playerAHoles[search+1]==12 || playerAHoles[search-1]==1|| playerAHoles[search-2]==2|| playerAHoles[search-3]==3|| playerAHoles[search-4]==4)
//                    {
//                        score+=GrabFromEmpty;
//                    }
//                    value = score;
//                    return;
//                }
//                else if(search ==5)
//                {
//                    if(playerAHoles[search-1]==1|| playerAHoles[search-2]==2|| playerAHoles[search-3]==3|| playerAHoles[search-4]==4 || playerAHoles[search-5]==5)
//                    {
//                        score+=GrabFromEmpty;
//                    }
//                    value = score;
//                    return;
//                }
//                //Will have to cover the other player's holes as well!
//
//            }
//            break;
//
//        default:
//            break;
//    }
//
//
//    //check for the opp end ascending order and try to attack!
    value = score;
    return;
}

int Board::getNumHoles() {return NUM_HOLES;}

int Board::getAScore() {return playerAScore;}

int Board::getBScore() {return playerBScore;}

int Board::getValue() {return value;}

void Board::setValue(int newValue){
    value = newValue;
    return;
}

void Board::setValue(char player, int valueAlgorithm){
    switch(valueAlgorithm){
        case 1:
            gentryValue(player);
            break;
        case 2:
            vishalValue(player);
            break;
        default:
            cerr << "Bad value alg choice sent to setValue" << endl;
            value = 0;
            break;

        break;
    }
}

bool Board::getFinished() {return finished;}

Board& Board::operator=(const Board& toCopy){
    if (this == &toCopy) return *this;

    for (int i = 0; i < NUM_HOLES; i++){
        playerAHoles[i] = toCopy.playerAHoles[i];
        playerBHoles[i] = toCopy.playerBHoles[i];
    }

    playerAScore = toCopy.playerAScore;
    playerBScore = toCopy.playerBScore;

    value = toCopy.value;

    finished = toCopy.finished;

    return *this;
}

bool Board::operator==(const Board& toCompare){
    if (this == &toCompare) return true;

    for(int i = 0; i < NUM_HOLES; i++){
        if (playerAHoles[i] != toCompare.playerAHoles[i]) return false;
        if (playerBHoles[i] != toCompare.playerBHoles[i]) return false;
    }

    if (playerAScore != toCompare.playerAScore) return false;
    if (playerBScore != toCompare.playerBScore) return false;

    if (value != toCompare.value) return false;

    if (finished != toCompare.finished) return false;

    return true;
}

bool Board::isLegal(char player, int hole){
    //cannot move if the game is over
    if (finished) {
        //cerr << "isLegal called for finished board" << endl;
        return false;
    }

    if (player != 'A' && player != 'B'){
        //cerr << "Bad player value passed to isLegal" << endl;
        return false;
    }

    //hole must be in range
    if (hole < 0 || hole >= NUM_HOLES){
        //cerr << hole << " hole value outside of range in isLegal" << endl;
        return false;
    }

    //moving an empty hole is not legal
    if (player == 'A' && playerAHoles[hole] == 0) {
        //cerr << hole << " hole is empty in isLegal" << endl;
        return false;
    }
    if (player == 'B' && playerBHoles[hole] == 0) {
        //cerr << hole << " hole is empty in isLegal" << endl;
        return false;
    }
    return true;
}

char Board::makeMove(char player, int hole){
    int numberStones;
    int sumA = 0, sumB = 0;
    int winningScore = (NUM_HOLES * NUM_STONES);
    char oldPlayer = player;

    if (!isLegal(player, hole)){
        cerr << "Illegal move attempted in makeMove" << endl;
        //value = -999;
        return player;
    }

    //remove stones from played hole
    if (player == 'A') {
        numberStones = playerAHoles[hole];
        playerAHoles[hole] = 0;
    }
    else if (player == 'B') {
        numberStones = playerBHoles[hole];
        playerBHoles[hole] = 0;
    }
    else{
        cerr << "Bad player value passed to makeMove" << endl;
        return 'C';
    }
    hole--;

    //playing an empty cup is illegal
    if (numberStones == 0){
        cerr << "An empty cup was played at makeMove" << endl;
        return 'C';
    }

    //keep placing stones until we reach the last stone
    while (numberStones > 1){
        //Case 1: regular hole for player A
        if (player == 'A' && hole >= 0){
            playerAHoles[hole]++;
            hole--;
        }
        //Case 2: kalah for player A
        else if (player == 'A' && hole == -1){
            if (oldPlayer == 'A'){
                playerAScore++;
            }
            else {
                //do not place in an opponent's kalah
                numberStones++;
            }
            hole = NUM_HOLES-1;
            player = 'B';
        }
        //Case 3: regular hole for player B
        else if (player == 'B' && hole >= 0){
            playerBHoles[hole]++;
            hole--;
        }
        //Case 4: kalah for player B
        else if (player == 'B' && hole == -1){
            if (oldPlayer == 'B'){
                playerBScore++;
            }
            else {
                //do not place in an opponent's kalah
                numberStones++;
            }
            hole = NUM_HOLES -1;
            player = 'A';
        }
        //Case 5: something has gone wrong
        else{
            cerr << "Bad state reached placing stones in makeMove" << endl;
            return 'C';
        }

        numberStones--;
    }

    //Place the last stone
    if (numberStones != 1){
        cerr << "Error placing last stone in makeMove" << endl;
        return 'C';
    }

    //Do not let the last move be the opponent's kalah
    if (hole == -1 && player != oldPlayer){
        hole = NUM_HOLES - 1;
        player = switchPlayer(player);
    }

    //Case 1: Player A's kalah
    if (player == 'A' && hole == -1){
        playerAScore++;
    }
    //Case 2: Player B's kalah
    else if (player == 'B'  && hole == -1){
        playerBScore++;
    }
    //Case 3:Empty hole for A
    else if (player == 'A' && oldPlayer == 'A' && playerAHoles[hole] == 0){
        //Add the stone of opposite cup to A's kalah
        playerAScore += playerBHoles[NUM_HOLES - hole - 1];
        playerBHoles[NUM_HOLES - hole - 1] = 0;
        //Add the final stone to A's kalh
        playerAScore++;
        //Switch player
        oldPlayer = 'B';
    }
    //Case 4: Empty hole for B
    else if (player == 'B' && oldPlayer == 'B' && playerBHoles[hole] == 0){
        //Add the stone of opposite cup to B's kalah
        playerBScore += playerAHoles[NUM_HOLES - hole - 1];
        playerAHoles[NUM_HOLES - hole - 1] = 0;
        //Add the final stone to A's kalh
        playerBScore++;
        //Switch player
        oldPlayer = 'A';
    }
    //Case 5: Non-empty hole for A
    else if (player == 'A' && hole >= 0){
        //Add stone to hole
        playerAHoles[hole]++;
        //switch player
        oldPlayer = switchPlayer(oldPlayer);
    }
    //Case 6: Non-empty hole for B
    else if (player == 'B' && hole >= 0){
        //Add stone to hole
        playerBHoles[hole]++;
        //switch player
        oldPlayer = switchPlayer(oldPlayer);
    }
    //Case 7: error case
    else {
        cerr << "Bad state reached placing last stone in makeMove" << endl;
        return 'C';
    }

    //Check to see if either side is empty
    for (int i = 0; i < NUM_HOLES; i++){
        sumA += playerAHoles[i];
        sumB += playerBHoles[i];
    }
    if (sumA == 0){
        playerAScore += sumB;
    }
    if (sumB == 0){
        playerBScore += sumA;
    }

    //Check for win condition
    if (playerAScore >= winningScore || playerBScore >= winningScore){
        finished = true;
    }

    //Complete
    return oldPlayer;

}

void Board::drawBoard(){
    cout << "\t";
    for (int i = 0; i < NUM_HOLES; i++)
        cout << playerBHoles[i] << " ";
    cout << endl;
    cout << playerBScore << "\t\t\t\t" << playerAScore << endl;
    cout << "\t";
    for (int i = NUM_HOLES -1; i >= 0; i--)
        cout << playerAHoles[i] << " ";
    cout << endl;

    return;
}
