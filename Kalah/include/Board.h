#ifndef BOARD_H
#define BOARD_H


class Board
{
    public:
        Board();
        ~Board();
        void draw();
        void move(int hole);
        void gentryValue();
        void vishalValue();

    protected:

    private:
        int holes[14]= {0, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6};
        int value;
};

#endif // BOARD_H
