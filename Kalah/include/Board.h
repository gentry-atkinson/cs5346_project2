#ifndef BOARD_H
#define BOARD_H


class Board
{
public:

    Board();
    Board(int[],int[],int,int);
    Board(const Board *);
    Board(const Board& toCopy);
    ~Board();

    char move_p1(int);
    char move_p2(int);
    char move(int hole, char player);
    char  isFinished();
    void draw();
    int getAHoles(int i);
    int getBHoles(int i);



    //    void setValue(int algorithm, int player);
    //    void setValue (int newValue);
    //    int getValue();
    bool isLegal(char ,int);
    //bool isFinished();

    int getScore1();
    int getScore2();
    Board& operator= (const Board& other);


private:
    int holes[14]= {0, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6};
    int value;
    bool finished;
    int playerAHoles[6],playerBHoles[6];
    int playerAScore,playerBScore,numberOfSlots;
    int * playerPtr;

    int gentryValue(int player);
    int vishalValue(int player);
};

#endif // BOARD_H
