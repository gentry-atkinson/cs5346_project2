#ifndef BOARD_H
#define BOARD_H


class Board
{
    public:
        Board();
        ~Board();
        void draw();
        void move(int hole);

    protected:

    private:
        int holes[14]= {0, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6};
};

#endif // BOARD_H
