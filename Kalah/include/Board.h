#ifndef BOARD_H
#define BOARD_H


class Board
{
    public:
        //construstors and destructors
        Board();
        Board(const Board&);
        ~Board();

        //getters and setters
        int getNumHoles();
        int getAScore();
        int getBScore();
        int getValue();
        void setValue(int);
        void setValue(char, int);
        bool getFinished();

        //operator overloading
        Board& operator=(const Board&);
        bool operator==(const Board&);

        //is a move legal for a certain player?
        bool isLegal(char, int);

        //allter the board in a legal fashion
        char makeMove(char, int);

        //draw the current board on the console
        void drawBoard();

        //returns the character of the opposite player
        static char switchPlayer(char);

    private:
        //The number of holes for each player
        static const int NUM_HOLES = 6;
        //The number of stones in each hole at start
        static const int NUM_STONES = 6;

        //let A[0] be across from B[NUM_HOLES]
        //let A[0] be closest to A's kalah
        //let B[0] be closest to B's kalah
        int playerAHoles[NUM_HOLES];
        int playerBHoles[NUM_HOLES];

        //A player's score is also the number of stones in his kalah
        int playerAScore;
        int playerBScore;

        //The value of the board is calculated with the setValue func
        int value;

        //true when the board is finished
        bool finished;


        //called by setValue
        void gentryValue(char);
        void vishalValue(char);
};

#endif // BOARD_H
