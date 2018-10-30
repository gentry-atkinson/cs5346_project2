#ifndef BOARD_H
#define BOARD_H


class Board
{
    public:
        Board();
        ~Board();
        void draw();
        void move(int hole, int player);
        void setValue(int algorithm, int player);
        int getValue();

    protected:

    private:
        int holes[14]= {0, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6};
        int value;

        int gentryValue(int player);
        int vishalValue();
};

#endif // BOARD_H
