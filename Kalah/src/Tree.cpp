#include "Tree.h"
#include <math.h>
#include <iostream>

using namespace std;

//Default constructor. Should not be used
Tree::Tree(){
    totalBoards = 7;
    boards = new Board[totalBoards];
    player = 'A';
    maxDepth = 1;
    searchAlg = MINMAXAB;
    valueAlg = GENTRY;

    buildTree();
}

Tree::Tree(int searchAlg, int valueAlg, int maxDepth, char player){
    this->searchAlg = searchAlg;
    this->valueAlg = valueAlg;
    this->maxDepth = maxDepth;
    this->player = player;

    totalBoards = 0;
    for (int i = 0; i <= maxDepth; i++)
        totalBoards += pow(NUM_HOLES, i);

    boards = new Board[totalBoards];
    buildTree();
}
Tree::~Tree(){
    delete[] boards;
}

int Tree::getTier(int boardNumber){
    int tier = 0;
    int total = 1;
    while (boardNumber >= total){
        tier++;
        total += pow(NUM_HOLES, tier);
    }
    cout << "Child " << boardNumber << " is on tier " << tier << endl;
    return tier;
}

int Tree::getChild(int current, int moveNum){
 return (6*current + moveNum + 1);
}

int Tree::getParent(int current){
    current--;
    return (current / 6);
}

//node 0 is the root and should be in a position determind in play()
//every child node is a legal move from its parent
//an illegal child duplicates its parent
void Tree::buildTree(){
    int currentNode = 1;
    int currentDepth;
    while (currentNode < totalBoards){
        currentDepth = getTier(currentNode);
        for (int i = 0; i < NUM_HOLES; i++){
            boards[currentNode] = boards[getParent(currentNode)];
            if (boards[currentNode].isLegal(player, i)){
                boards[currentNode].makeMove(player, i);
            }
            if (currentDepth == maxDepth){
                boards[currentNode].setValue(player, valueAlg);
                cout << "Leaf node: " << boards[currentNode].getValue() << endl;
            }
            else
                boards[currentNode].setValue(-9999);
            currentNode++;
            if (currentNode == totalBoards+1){
                cerr << "Out of bounds board reached in buildTree" << endl;
                break;
            }
        }
    }

    switch (searchAlg){
        case MINMAXAB:
            minMaxAB(1, 1, player, 99999, -99999);
            break;
        case ALPHABETA:
            alphabeta(1, 1, player, 99999, -99999);
            break;
        default:
            cerr << "Bad search algorithm number in buildTree()" << endl;
            break;
    }
    return;
}

//getters and setters
bool Tree::getFinished() {return boards[0].getFinished();}
int Tree::getAScore() {return boards[0].getAScore();}
int Tree::getBScore() {return boards[0].getBScore();}
int Tree::getTotalBoards() {return totalBoards;}

//draw the root board in tree
void Tree::draw() {
    boards[0].drawBoard();
    return;}

int Tree::minMaxAB(int currentNode, int depth, char player, int useThresh, int passThresh) {
    int newValue;
    char resultSucc;
    int structure;

    //check for bad values
    if (currentNode >= totalBoards){
        cerr << "Bad current node for minMaxAB" << endl;
        return -9999;
    }
    if (depth > maxDepth){
        cerr << "Bad depth value in minMaxAB" << endl;
        return -9999;
    }

    //if deep enough
    if(depth == maxDepth)
    {
        return boards[currentNode].getValue();
    }

    //otherwise
    for(int i = 0 ; i < NUM_HOLES; i++)
    {
        structure = minMaxAB(getChild(currentNode, i),depth+1, Board::switchPlayer(player),-passThresh,-useThresh);
        newValue = -structure;

        if(newValue > passThresh)
        {
            //index->set_value(i);
            boards[currentNode].setValue(newValue);
            passThresh = newValue;
        }
        if(passThresh >= useThresh)
        {
            structure=passThresh;
            return structure;
        }
    }
    structure=passThresh;
    return structure;
}

int Tree::alphabeta(int currentNode, int depth, char player, int alpha, int beta)
{
    //check for bad values
    if (currentNode >= totalBoards){
        cerr << "Bad current node for alphabeta" << endl;
        return -9999;
    }
    if (depth > maxDepth){
        cerr << "Bad depth value in alphabeta" << endl;
        return -9999;
    }

    //node is a leaf node)
    if (depth == maxDepth)
        return boards[currentNode].getValue();

    if (player == 'A' )
    {
        int bestVal = -100,value;
        for(int i=0;i < 6 ; i++ )
        {
            value = alphabeta(getChild(currentNode, i), depth+1, player, alpha, beta);
            bestVal = ( bestVal > value) ? bestVal : value;
            alpha = ( alpha > bestVal) ? alpha : bestVal;
            if (beta <= alpha)
                break;
        }
        //node->set_value(bestVal);
        boards[currentNode].setValue(bestVal);
        return bestVal;
    }
    else
    {
        int bestVal = +100,value;
        for(int i=0; i < 6 ; i++ )
        {
            value = alphabeta(getChild(currentNode, i), depth+1, player, alpha, beta);
            bestVal = ( bestVal < value) ? bestVal : value;
            beta = ( beta < bestVal) ? beta : bestVal;
            if (beta < alpha)
                break;
        }
        //node->set_value(bestVal);
        boards[currentNode].setValue(bestVal);
        return bestVal;
    }
}

int Tree::chooseBestMove(){
    int bestMove;
    int bestVal = -9999;
    for (int i = 1; i <= NUM_HOLES; i++){
        if (!boards[0].isLegal(player, i-1))
            continue;
        if (boards[i].getValue() > bestVal){
            bestMove = i;
            bestVal = boards[i].getValue();
        }
        cout << "Best move: " << boards[bestMove].getValue() << endl;
    }

    cout << "My best move is " << bestMove << endl;
    return bestMove-1;
}

void Tree::play(char& currentPlayer, char& lastPlayer, int& lastMove){
    cout << "Current player is " << currentPlayer << endl;
    cout << "Last player is " << lastPlayer << endl;
    //Case 1: first move for A
    if (currentPlayer == 'A' && lastPlayer == FIRST_MOVE){
        cout << "First move" << endl;
        lastPlayer = currentPlayer;
        lastMove = chooseBestMove();
        currentPlayer = boards[0].makeMove(player, lastMove);
    }
    //Case 2: update board then choose move then update board
    else if (currentPlayer == player && lastPlayer != currentPlayer){
        cout << player << "'s move and " << lastPlayer << " went last time." << endl;
        boards[0].makeMove(lastPlayer, lastMove);
        buildTree();
        lastPlayer = currentPlayer;
        lastMove = chooseBestMove();
        currentPlayer = boards[0].makeMove(player, lastMove);
        buildTree();
    }
    //Case 3: choose move then update board
    else if (currentPlayer == player && lastPlayer == currentPlayer){
        cout << player << "'s move and I'm going again" << endl;
        lastPlayer = currentPlayer;
        lastMove = chooseBestMove();
        currentPlayer = boards[0].makeMove(player, lastMove);
        buildTree();
    }
    //Case 4: update board without choosing move
    else if (currentPlayer != player){
        cout << "I just need to update" << endl;
        boards[0].makeMove(lastPlayer, lastMove);
        buildTree();
    }
    //Case 5: error condition
    else{
        cerr << "Bad case in play" << endl;
    }
    return;
}
