#ifndef BOARD_H
#define BOARD_H


class Board
{
public:
    Board();
    int *ptr;
    int player1,player2,numberOfSlots;
    int A[6],B[6];
    Board(const Board& toCopy);
    Board(Board *);
    ~Board();
    void draw();
    int move_p1(int);
    int move_p2(int);
    int move(int hole, int player);
    void setValue(int algorithm, int player);
    void setValue (int newValue);
    int getValue();
    bool isLegal(int moveNumber, int player);
    //bool isFinished();
    char  isFinished();
    int getScore1();
    int getScore2();
    Board& operator= (const Board& other);

    //protected:

    //private:
    int holes[14]= {0, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6};
    int value;
    bool finished;

    int gentryValue(int player);
    int vishalValue(int player);
};

#endif // BOARD_H
