#include <iostream>
#include <cstdio>

#include "Tree.h"

using namespace std;

int main()
{
    Tree * tree1, * tree2;
    char lastPlayer, currentPlayer;
    int lastMove, aScore, bScore, depth, turn;

    //Case 1: Vishal vs. Gentry with MinMaxAB at depth 3
    cout << "***************************" << endl;
    cout << "Vishal vs. Gentry with MinMaxAB at depth 3" << endl;
    depth = 3;
    tree1 = new Tree(Tree::MINMAXAB, Tree::GENTRY, depth, 'A');
    tree2 = new Tree(Tree::MINMAXAB, Tree::VISHAL, depth, 'B');
    currentPlayer = 'A';
    lastPlayer = Tree::FIRST_MOVE;
    lastMove = 0;
    turn = 0;
    aScore = 0;
    bScore = 0;

    while(! tree1->getFinished() && ! tree2->getFinished()){
        tree1->play(currentPlayer, lastPlayer, lastMove);
        tree2->play(currentPlayer, lastPlayer, lastMove);
        turn++;
        //tree1->draw();
        //tree2->draw();
        //getchar();
    }

    aScore = tree2->getAScore();
    bScore = tree2->getBScore();

    cout << turn << " turns played" << endl;

    if (aScore > bScore){
        cout << "Gentry wins " << aScore << " to " << bScore << endl;
    }
    else if (bScore > aScore){
        cout << "Vishal wins " << bScore << " to " << aScore << endl;
    }
    else {
        cout << "Tie game." << endl;
    }

    delete tree1;
    delete tree2;
    getchar();
    //Case 2: Vishal vs. Gentry with AlphaBeta at depth 3

    cout << "***************************" << endl;
    cout << "Vishal vs. Gentry with AlphaBeta at depth 3" << endl;
    depth = 3;
    tree1 = new Tree(Tree::ALPHABETA, Tree::GENTRY, depth, 'A');
    tree2 = new Tree(Tree::ALPHABETA, Tree::VISHAL, depth, 'B');
    currentPlayer = 'A';
    lastPlayer = Tree::FIRST_MOVE;
    lastMove = 0;
    turn = 0;
    aScore = 0;
    bScore = 0;

    while(! tree1->getFinished() && ! tree2->getFinished()){
        tree1->play(currentPlayer, lastPlayer, lastMove);
        tree2->play(currentPlayer, lastPlayer, lastMove);
        turn++;
        //tree1->draw();
        //tree2->draw();
        //getchar();
    }

    aScore = tree2->getAScore();
    bScore = tree2->getBScore();

    cout << turn << " turns played" << endl;

    if (aScore > bScore){
        cout << "Gentry wins " << aScore << " to " << bScore << endl;
    }
    else if (bScore > aScore){
        cout << "Vishal wins " << bScore << " to " << aScore << endl;
    }
    else {
        cout << "Tie game." << endl;
    }

    delete tree1;
    delete tree2;
    getchar();

    //Case 3: MinMax vs. AlphaBeta with Vishal at depth 3
    cout << "***************************" << endl;
    cout << "MinMax vs. AlphaBeta with Vishal at depth 3" << endl;
    depth = 3;
    tree1 = new Tree(Tree::MINMAXAB, Tree::VISHAL, depth, 'A');
    tree2 = new Tree(Tree::ALPHABETA, Tree::VISHAL, depth, 'B');
    currentPlayer = 'A';
    lastPlayer = Tree::FIRST_MOVE;
    lastMove = 0;
    turn = 0;
    aScore = 0;
    bScore = 0;

    while(! tree1->getFinished() && ! tree2->getFinished()){
        tree1->play(currentPlayer, lastPlayer, lastMove);
        tree2->play(currentPlayer, lastPlayer, lastMove);
        turn++;
        //tree1->draw();
        //tree2->draw();
        //getchar();
    }

    aScore = tree2->getAScore();
    bScore = tree2->getBScore();

    cout << turn << " turns played" << endl;

    if (aScore > bScore){
        cout << "MinMaxAB wins " << aScore << " to " << bScore << endl;
    }
    else if (bScore > aScore){
        cout << "AlphaBeta wins " << bScore << " to " << aScore << endl;
    }
    else {
        cout << "Tie game." << endl;
    }

    delete tree1;
    delete tree2;
    getchar();

    //Case 4: MinMax vs. AlphaBeta with Gentry at depth 3
    cout << "***************************" << endl;
    cout << "MinMax vs. AlphaBeta with Gentry at depth 3" << endl;
    depth = 3;
    tree1 = new Tree(Tree::MINMAXAB, Tree::GENTRY, depth, 'A');
    tree2 = new Tree(Tree::ALPHABETA, Tree::GENTRY, depth, 'B');
    currentPlayer = 'A';
    lastPlayer = Tree::FIRST_MOVE;
    lastMove = 0;
    turn = 0;
    aScore = 0;
    bScore = 0;

    while(! tree1->getFinished() && ! tree2->getFinished()){
        tree1->play(currentPlayer, lastPlayer, lastMove);
        tree2->play(currentPlayer, lastPlayer, lastMove);
        turn++;
        //tree1->draw();
        //tree2->draw();
        //getchar();
    }

    aScore = tree2->getAScore();
    bScore = tree2->getBScore();

    cout << turn << " turns played" << endl;

    if (aScore > bScore){
        cout << "MinMaxAB wins " << aScore << " to " << bScore << endl;
    }
    else if (bScore > aScore){
        cout << "AlphaBeta wins " << bScore << " to " << aScore << endl;
    }
    else {
        cout << "Tie game." << endl;
    }

    delete tree1;
    delete tree2;
    getchar();

    //Case 5: Vishal vs. Gentry with MinMaxAB at depth 5
    cout << "***************************" << endl;
    cout << "Vishal vs. Gentry with MinMaxAB at depth 5" << endl;
    depth = 5;
    tree1 = new Tree(Tree::MINMAXAB, Tree::GENTRY, depth, 'A');
    tree2 = new Tree(Tree::MINMAXAB, Tree::VISHAL, depth, 'B');
    currentPlayer = 'A';
    lastPlayer = Tree::FIRST_MOVE;
    lastMove = 0;
    turn = 0;
    aScore = 0;
    bScore = 0;

    while(! tree1->getFinished() && ! tree2->getFinished()){
        tree1->play(currentPlayer, lastPlayer, lastMove);
        tree2->play(currentPlayer, lastPlayer, lastMove);
        turn++;
        //tree1->draw();
        //tree2->draw();
        //getchar();
    }

    aScore = tree2->getAScore();
    bScore = tree2->getBScore();

    cout << turn << " turns played" << endl;

    if (aScore > bScore){
        cout << "Gentry wins " << aScore << " to " << bScore << endl;
    }
    else if (bScore > aScore){
        cout << "Vishal wins " << bScore << " to " << aScore << endl;
    }
    else {
        cout << "Tie game." << endl;
    }

    delete tree1;
    delete tree2;
    getchar();

    //Case 6: Vishal vs. Gentry with AlphaBeta at depth 5
    cout << "***************************" << endl;
    cout << "Vishal vs. Gentry with AlphaBeta at depth 5" << endl;
    depth = 5;
    tree1 = new Tree(Tree::ALPHABETA, Tree::GENTRY, depth, 'A');
    tree2 = new Tree(Tree::ALPHABETA, Tree::VISHAL, depth, 'B');
    currentPlayer = 'A';
    lastPlayer = Tree::FIRST_MOVE;
    lastMove = 0;
    turn = 0;
    aScore = 0;
    bScore = 0;

    while(! tree1->getFinished() && ! tree2->getFinished()){
        tree1->play(currentPlayer, lastPlayer, lastMove);
        tree2->play(currentPlayer, lastPlayer, lastMove);
        turn++;
        //tree1->draw();
        //tree2->draw();
        //getchar();
    }

    aScore = tree2->getAScore();
    bScore = tree2->getBScore();

    cout << turn << " turns played" << endl;

    if (aScore > bScore){
        cout << "Gentry wins " << aScore << " to " << bScore << endl;
    }
    else if (bScore > aScore){
        cout << "Vishal wins " << bScore << " to " << aScore << endl;
    }
    else {
        cout << "Tie game." << endl;
    }

    delete tree1;
    delete tree2;
    getchar();

    //Case 7: MinMax vs. AlphaBeta with Vishal at depth 5
    cout << "***************************" << endl;
    cout << "MinMax vs. AlphaBeta with Vishal at depth 5" << endl;
    depth = 5;
    tree1 = new Tree(Tree::MINMAXAB, Tree::VISHAL, depth, 'A');
    tree2 = new Tree(Tree::ALPHABETA, Tree::VISHAL, depth, 'B');
    currentPlayer = 'A';
    lastPlayer = Tree::FIRST_MOVE;
    lastMove = 0;
    turn = 0;
    aScore = 0;
    bScore = 0;

    while(! tree1->getFinished() && ! tree2->getFinished()){
        tree1->play(currentPlayer, lastPlayer, lastMove);
        tree2->play(currentPlayer, lastPlayer, lastMove);
        turn++;
        //tree1->draw();
        //tree2->draw();
        //getchar();
    }

    aScore = tree2->getAScore();
    bScore = tree2->getBScore();

    cout << turn << " turns played" << endl;

    if (aScore > bScore){
        cout << "MinMaxAB wins " << aScore << " to " << bScore << endl;
    }
    else if (bScore > aScore){
        cout << "AlphaBeta wins " << bScore << " to " << aScore << endl;
    }
    else {
        cout << "Tie game." << endl;
    }

    delete tree1;
    delete tree2;
    getchar();

    //Case 8: MinMax vs. AlphaBeta with Gentry at depth 5
    cout << "***************************" << endl;
    cout << "MinMax vs. AlphaBeta with Gentry at depth 5" << endl;
    depth = 5;
    tree1 = new Tree(Tree::MINMAXAB, Tree::GENTRY, depth, 'A');
    tree2 = new Tree(Tree::ALPHABETA, Tree::GENTRY, depth, 'B');
    currentPlayer = 'A';
    lastPlayer = Tree::FIRST_MOVE;
    lastMove = 0;
    turn = 0;
    aScore = 0;
    bScore = 0;

    while(! tree1->getFinished() && ! tree2->getFinished()){
        tree1->play(currentPlayer, lastPlayer, lastMove);
        tree2->play(currentPlayer, lastPlayer, lastMove);
        turn++;
        //tree1->draw();
        //tree2->draw();
        //getchar();
    }

    aScore = tree2->getAScore();
    bScore = tree2->getBScore();

    cout << turn << " turns played" << endl;

    if (aScore > bScore){
        cout << "MinMaxAB wins " << aScore << " to " << bScore << endl;
    }
    else if (bScore > aScore){
        cout << "AlphaBeta wins " << bScore << " to " << aScore << endl;
    }
    else {
        cout << "Tie game." << endl;
    }

    delete tree1;
    delete tree2;
    getchar();

    //Case 9: Vishal vs. Gentry with MinMaxAB at depth 7
    cout << "***************************" << endl;
    cout << "Vishal vs. Gentry with MinMaxAB at depth 7" << endl;
    depth = 7;
    tree1 = new Tree(Tree::MINMAXAB, Tree::GENTRY, depth, 'A');
    tree2 = new Tree(Tree::MINMAXAB, Tree::VISHAL, depth, 'B');
    currentPlayer = 'A';
    lastPlayer = Tree::FIRST_MOVE;
    lastMove = 0;
    turn = 0;
    aScore = 0;
    bScore = 0;

    while(! tree1->getFinished() && ! tree2->getFinished()){
        tree1->play(currentPlayer, lastPlayer, lastMove);
        tree2->play(currentPlayer, lastPlayer, lastMove);
        turn++;
        //tree1->draw();
        //tree2->draw();
        //getchar();
    }

    aScore = tree2->getAScore();
    bScore = tree2->getBScore();

    cout << turn << " turns played" << endl;

    if (aScore > bScore){
        cout << "Gentry wins " << aScore << " to " << bScore << endl;
    }
    else if (bScore > aScore){
        cout << "Vishal wins " << bScore << " to " << aScore << endl;
    }
    else {
        cout << "Tie game." << endl;
    }

    delete tree1;
    delete tree2;
    getchar();

    //Case 10: Vishal vs. Gentry with AlphaBeta at depth 7
    cout << "***************************" << endl;
    cout << "Vishal vs. Gentry with AlphaBeta at depth 7" << endl;
    depth = 7;
    tree1 = new Tree(Tree::ALPHABETA, Tree::GENTRY, depth, 'A');
    tree2 = new Tree(Tree::ALPHABETA, Tree::VISHAL, depth, 'B');
    currentPlayer = 'A';
    lastPlayer = Tree::FIRST_MOVE;
    lastMove = 0;
    turn = 0;
    aScore = 0;
    bScore = 0;

    while(! tree1->getFinished() && ! tree2->getFinished()){
        tree1->play(currentPlayer, lastPlayer, lastMove);
        tree2->play(currentPlayer, lastPlayer, lastMove);
        turn++;
        //tree1->draw();
        //tree2->draw();
        //getchar();
    }

    aScore = tree2->getAScore();
    bScore = tree2->getBScore();

    cout << turn << " turns played" << endl;

    if (aScore > bScore){
        cout << "Gentry wins " << aScore << " to " << bScore << endl;
    }
    else if (bScore > aScore){
        cout << "Vishal wins " << bScore << " to " << aScore << endl;
    }
    else {
        cout << "Tie game." << endl;
    }

    delete tree1;
    delete tree2;
    getchar();

    //Case 11: MinMax vs. AlphaBeta with Vishal at depth 7
    cout << "***************************" << endl;
    cout << "MinMax vs. AlphaBeta with Vishal at depth 7" << endl;
    depth = 7;
    tree1 = new Tree(Tree::MINMAXAB, Tree::VISHAL, depth, 'A');
    tree2 = new Tree(Tree::ALPHABETA, Tree::VISHAL, depth, 'B');
    currentPlayer = 'A';
    lastPlayer = Tree::FIRST_MOVE;
    lastMove = 0;
    turn = 0;
    aScore = 0;
    bScore = 0;

    while(! tree1->getFinished() && ! tree2->getFinished()){
        tree1->play(currentPlayer, lastPlayer, lastMove);
        tree2->play(currentPlayer, lastPlayer, lastMove);
        turn++;
        //tree1->draw();
        //tree2->draw();
        //getchar();
    }

    aScore = tree2->getAScore();
    bScore = tree2->getBScore();

    cout << turn << " turns played" << endl;

    if (aScore > bScore){
        cout << "MinMaxAB wins " << aScore << " to " << bScore << endl;
    }
    else if (bScore > aScore){
        cout << "AlphaBeta wins " << bScore << " to " << aScore << endl;
    }
    else {
        cout << "Tie game." << endl;
    }

    delete tree1;
    delete tree2;
    getchar();
    //Case 12: MinMax vs. AlphaBeta with Gentry at depth 7
    cout << "***************************" << endl;
    cout << "MinMax vs. AlphaBeta with Gentry at depth 7" << endl;
    depth = 7;
    tree1 = new Tree(Tree::MINMAXAB, Tree::GENTRY, depth, 'A');
    tree2 = new Tree(Tree::ALPHABETA, Tree::GENTRY, depth, 'B');
    currentPlayer = 'A';
    lastPlayer = Tree::FIRST_MOVE;
    lastMove = 0;
    turn = 0;
    aScore = 0;
    bScore = 0;

    while(! tree1->getFinished() && ! tree2->getFinished()){
        tree1->play(currentPlayer, lastPlayer, lastMove);
        tree2->play(currentPlayer, lastPlayer, lastMove);
        turn++;
        //tree1->draw();
        //tree2->draw();
        //getchar();
    }

    aScore = tree2->getAScore();
    bScore = tree2->getBScore();

    cout << turn << " turns played" << endl;

    if (aScore > bScore){
        cout << "MinMaxAB wins " << aScore << " to " << bScore << endl;
    }
    else if (bScore > aScore){
        cout << "AlphaBeta wins " << bScore << " to " << aScore << endl;
    }
    else {
        cout << "Tie game." << endl;
    }

    delete tree1;
    delete tree2;

    return 0;
}
