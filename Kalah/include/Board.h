#ifndef BOARD_H
#define BOARD_H


class Board
{
public:

    int A[6],B[6];
    int player1,player2,numberOfSlots;
    int *ptr;
    Board();
    Board(int[],int[],int,int);
    Board(Board *);
    char move_p1(int);
    char move_p2(int);
    char move(int hole, char player);
    char  isFinished();
    void draw();


    Board(const Board& toCopy);

    ~Board();


    //    void setValue(int algorithm, int player);
    //    void setValue (int newValue);
    //    int getValue();
    bool isLegal(char ,int);
    //bool isFinished();

    int getScore1();
    int getScore2();
    // Board& operator= (const Board& other);
    void operator=(Board);


private:
    int holes[14]= {0, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6};
    int value;
    bool finished;

    int gentryValue(int player);
    int vishalValue(int player);
};

#endif // BOARD_H
