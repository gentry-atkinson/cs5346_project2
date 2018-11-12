#ifndef BOARD_H
#define BOARD_H


class Board
{
public:
    Board();
    Board(const Board& toCopy);
    ~Board();
    void draw();
    int move(int hole, int player);
    void setValue(int algorithm, int player);
    void setValue (int newValue);
    int getValue();
    bool isLegal(int moveNumber, int player);
    bool isFinished();
    int getScore1();
    int getScore2();
    Board& operator= (const Board& other);

protected:

private:
    int holes[14]= {0, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6};
    int value;
    bool finished;

    int gentryValue(int player);
    int vishalValue(int player);
};

#endif // BOARD_H
