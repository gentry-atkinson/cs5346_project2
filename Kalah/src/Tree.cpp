#include "Tree.h"
#include <iostream>
#include <math.h>

using namespace std;
int expand_nodes, generate_nodes;

Tree::Tree()
{
    //depth = 3;
    player = 'n';
    //valueAlgorithm = 1;
    value=-1000;
    stone=0;
    //searchAlgorithm = 1;
    //totalBoards = 259;
    for(int i=0;i<6;i++)
    {
        stones[i] = NULL;
    }
    //boards = new Board[totalBoards];
    
    //buildTree();
}

Tree::Tree(char p)
{
    player = p;
    value = -1000;
    stone = 0;
    for(int i=0;i<6;i++)
    {
        stones[i] = NULL;
    }
}

//Tree::~Tree()
//{
//    //cout << "Deleting tree for player " << player << endl;
//    delete[] boards;
//}
//
//Tree::Tree(int value, int search, int depth, int player){
//    this->depth = depth;
//    valueAlgorithm = value;
//    searchAlgorithm = search;
//    this->player = player;
//    totalBoards = 1;
//    for (int i = 1; i <= depth; i++)
//        totalBoards += pow(6, i);
//    boards = new Board[totalBoards];
//    //cout << "Player " << player << " has " << totalBoards << " boards in tree." << endl;
//    buildTree();
//}

void Tree::create_node(char p)
{
    stones[stone++]=new Tree(p);
}


void Tree::set_value(int v)
{
    value = v;
}




int Tree::getChildIndex(int parentIndex, int childNumber){
    return (6*parentIndex + childNumber);
}

int Tree::getParentIndex(int childIndex){
    return ((childIndex-1)/6);
}

//void Tree::drawRoot(){
//    boards[0].draw();
//}

//An illegal move creates a child with the same value as the parent.
void Tree::buildTree(){
    //cout << "Building tree for Player " << player << endl;
    int child;
    
    for (int i = 0; i < depth; i++){
        for (int j = 1; j <= 6; j++){
            child = 6*i+j;
            boards[child] = boards[getParentIndex(child)];
            if (boards[child].isLegal(j, player))
                boards[child].move(j, player);
        }
    }
    cout << "Tree done." << endl;
    
    switch(searchAlgorithm){
        case 1:
            // minMaxAB(0, 0, player, 100, -120);
            break;
        case 2:
            void aBSearch();
            break;
        default:
            cerr << "Bad value for search algorithm in buildTree" << endl;
            break;
    }
    
    return;
}


//int Tree::minMaxAB(Tree *index, int depth, int player, int useThresh, int passThresh) {
//    cout << "MinMax called for depth " << depth << endl;
//    int newValue;
//    int resultSucc;
//    int structure;
//
//    if(index->IsitDeep(depth))
//    {
//        structure = index->evaluation();
//        if(player==2)
//        {
//            structure=-structure;
//        }
//        index->setValue(structure);
//        return structure;
//    }
//    int structure1=0;
//
//    for(int i = 0 ; i < 14; i++)
//    {
//        if(index->stones[i] == NULL)
//            continue;
//        if(player == 1)
//            resultSucc = 2;
//        else
//            resultSucc = 1;
//
//        structure1 = minMaxAB(index->stones[i],depth+1,resultSucc,-passThresh,-useThresh);
//        newValue = -structure1;
//
//        if(newValue > passThresh)
//        {
//            index->setValue(i);
//            passThresh = newValue;
//        }
//        if(passThresh >= useThresh)
//        {
//            structure1=passThresh;
//            return structure1;
//        }
//    }
//    structure1=passThresh;
//    return structure1;
//}


//int Tree::minMaxAB(int index, int depth, int player, int useThresh, int passThresh) {
//    cout << "MinMax called for depth " << depth << endl;
//    int newValue;
//    int resultSucc;
//    //Algorithm: MINIMAX-A-B( Position, Depth, Player, Use-Thresh, Pass-Thresh )
//    //1. If DEEP-ENOUGH(Position, Depth), then return the structure
//    if (depth >= this->depth){
//        //VALUE = STATlC (Position, Player);
//        boards[index].setValue(valueAlgorithm, player);
//        return boards[index].getValue();
//    }
//    //PATH = nil
//    //2. Otherwise, generate one more ply of the tree by calling the function MOVE-     GEN(Position, Player) and setting SUCCESSORS to the list it returns.
//
//    //3.If SUCCESSORS is empty, there are no moves to be made; return the same structure that     would have been returned if DEEP-ENOUGH had returned TRUE.
//
//    //4. If SUCCESSORS is not empty, then go through it, examining each element and keeping     track of the best one. This is done as follows.
//    //For each clement SUCC of SUCCESSORS:
//    for (int i = 0; i < 6; i++){
//        //(a) Set RESULT-SUCC to
//        //MINIMAX-A-B(SUCC, Depth + 1, OPPOSlTE (Player),
//        //- Pass-Thresh, - Use-Thresh).
//        resultSucc = minMaxAB(getChildIndex(index, i), depth+1, player, -1 * passThresh, -1 * useThresh);
//        //(b) Set NEW-VALUE to - VALUE(RESULT-SUCC).
//        newValue = -1 * resultSucc;
//        //(c) If NEW-VALUE> Pass-Thresh, then we have found a successor that is better than any that have
//        //been examined so far. Record this by doing the following.
//        if (newValue > passThresh){
//            //(i) Set Pass-Thresh to NEW-VALUE.
//            passThresh = newValue;
//            //(ii) The best known path is now from CURRENT to SUCC and then on to the appropriate path
//            //from SUCC as determined by the recursive call to MINIMAX-A-B. So set BEST-PATH to
//            //the result of attaching SUCC to the front of PATH(RESULT-SUCC).
//        }
//        //(d) If Pass-Thresh (reflecting the current best value) is not better than Use-Thresh, then we should
//        //stop examining this branch. But both thresholds and values have been inverted. So if Pass-Thresh
//        //>= Use-Thresh, then return immediately with the value
//        // VALUE = Pass-Thresh
//        // PATH = BEST-PATH
//        if (passThresh <= useThresh)
//            return passThresh;
//    }
//    //5. Return the structure
//    //VALUE = Pass-Thresh
//    //PATH = BEST-PATH
//    return passThresh;
//
//}



//void Tree::setValue(int value)
//{
//    value = value;
//}

void Tree::print(Tree *n,int nestLevel)

{
    
    cout<<n->player<<":"<<n->value<<endl;
    
    int i, j;
    
    for (i = 0; n->stones[i] != NULL && i < 6; i++)
        
    {
        
        for (j = 0; j < nestLevel; j++)
            
            cout<<"\t";
        
        print(n->stones[i], nestLevel + 1);
        
    }
    
}
void Tree :: grab_all_stones()
{
    
    char p = (player=='A')?'B':'A';
    for(int i=0;i<6;i++)
    {
        stone++;
        stones[i]=new Tree(p);
        if(this->bx.A[i]!=0 && player == 'A')
            
            stones[i]->bx = this->bx;
        
        else if(this->bx.B[i]!=0 && player == 'B')
            
            stones[i]->bx = this->bx;
        
        else
            
            stones[i] = NULL;
        
        if(stones[i]!=NULL)
            
        {
            
            generate_nodes++;
            
            stones[i]->bx.move(i,stones[i]->player);
            
        }
        
        
    }
    
}


bool Tree::IsitDeep(int d)
{
    if(value != -1000)
        return value;
    //if the depth is greater than 3 or a player has won the game then it is deep enough.
    if(d >= 3 || bx.isFinished()!='N')
    {
        return true;
    }
    else
    {
        expand_nodes++;
        grab_all_stones();
        return false;
    }
}

int Tree::evaluation()
{
    int x;
    //int p1stones=0, p2stones=0;
    if(player == 'A')
    {
        int p1stones = 0;
        for(int i = 0 ; i < 6 ; i++)
        {
            if(bx.A[i] == 0)
                p1stones++;
        }
        if(p1stones == 6)
        {
            x = 1000;
        }
    }
    else if(player == 'B')
    {
        int p2stones = 0;
        for(int i = 0 ; i < 6 ; i++)
        {
            if(bx.B[i] == 0)
                p2stones++;
        }
        if(p2stones == 6)
            x = -1000;
    }
    set_value(x);
    return x;
}


//int alphabeta(Tree *node, int depth, int player, int alpha, int beta)
//{
//    //Initial Condition -> node is a leaf node
//    if(node->IsitDeep(depth))
//        return node->evaluation() ;
//    if (player == 1 )
//    {
//        int bestVal = -100,value;
//        for(int i=0;i < 6 ; i++ )
//        {
//            if(node->stones[i]== NULL)
//                continue;
//            value = alphabeta(node->stones[i], depth+1, node->player, alpha, beta);
//            bestVal = ( bestVal > value) ? bestVal : value;
//            alpha = ( alpha > bestVal) ? alpha : bestVal;
//            if (beta <= alpha)
//                break;
//        }
//        node->setValue(bestVal);
//        return bestVal;
//    }
//    else
//    {
//        int bestVal = +100,value;
//        for(int i=7; i < 14 ; i++ )
//        {
//            if(node->stones[i]== NULL)
//                continue;
//            value = alphabeta(node->stones[i], depth+1, node->player, alpha, beta);
//            bestVal = ( bestVal < value) ? bestVal : value;
//            beta = ( beta < bestVal) ? beta : bestVal;
//            if (beta < alpha)
//                break;
//        }
//        node->setValue(bestVal);
//        return bestVal;
//    }
//}



int Tree::getHole()
{
    for(int i=0;i<6;i++)
    {
        if(stones[i] == NULL)
            continue;
        if(stones[i]->value == value)
        {
            cout<<"hole #"<<i;
            return i;
        }
    }
    return -1;
}
//if same player's move
//select best move from 6 children
//update tree
//update player
//update finished
//return best move
//if opposite player
//update tree
//TODO: players are making illegal moves and always making the same move.
//int Tree::play(int lastMove, bool& finished, int& player){
//    cout << "Player " << player << " is moving." << endl;
//    int bestMove = 1;
//    if (player == 2)  bestMove = 8;
//
//    int i = 1, bound = 7;
//    if (player == 2){
//        i = 7;
//        bound = 14;
//    }
//
//    if (lastMove != 99){
//        boards[0].move(lastMove, player);
//        buildTree();
//    }
//
//    if (player == this->player){
//        for (; i < bound; i++){
//            cout << i << " ";
//            if (boards[i].isLegal(i, player))
//                if (boards[i].getValue() > boards[bestMove].getValue())
//                    bestMove = i;
//        }
//        cout << "Player " << " selects hole " << bestMove << endl;
//        player = boards[0].move(bestMove, player);
//        buildTree();
//        finished = boards[0].isFinished();
//        cout << "Player " << player << " moves hole " << bestMove << endl;
//        if (player == this-> player)
//            return 99;
//        else
//            return bestMove;
//    }
//    else {
//        return 99;
//    }
//}



void Tree::copyBoardStatus(Board b)
{
    for(int i=0;i<6;i++)
    {
        this->bx.A[i]=b.A[i];
        this->bx.B[i]=b.B[i];
    }
    this->bx.player1=b.player1;
    this->bx.player2=b.player2;
}
