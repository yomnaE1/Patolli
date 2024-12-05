#ifndef BOARD_H
#define BOARD_H

using namespace std;

class Board
{
    ///to create the grid (line 9)
    char grid[33][33];

    int a, mr1;

    ///to return the score
    int rotationAinitial;
    int rA, rB, rC, rD, rE, rF;

    int rotation1initial;
    int r1, r2, r3, r4, r5, r6;

    ///to keep track of where the player pieces are based on their rows and columns
    int currentRowA, currentColA;
    int currentRow1, currentCol1;

    ///the scores of each player
    int score, score1;

    ///to make sure 1 point is alloted each time the player reaches the end of the grid
    int Counter1;
    int counterA, counterB, counterC, counterD, counterE, counterF;

    int Counter2;
    int counter1, counter2, counter3, counter4, counter5, counter6;

    bool foundP1, foundP2;

    ///to keep track of where the player pieces are based on their rows and columns
    int RowA, ColA;
    int RowB, ColB;
    int RowC, ColC;
    int RowD, ColD;
    int RowE, ColE;
    int RowF, ColF;
    int Row1, Col1;
    int Row2, Col2;
    int Row3, Col3;
    int Row4, Col4;
    int Row5, Col5;
    int Row6, Col6;

    char gp, GP, g;
    bool notBlank; ///to see if there are any blank spaces on the board

    public:

        Board(); ///constructor
        void playGame();///prints the board to the screen
        void initializePlayer1(char gamePiece);///initializes player l's first piece
        void initializePlayer2(char gamePiece);///initializes player n's first piece

        void movePiece1(int position, char p, int Roll, int r, int c); ///to move player l's first piece

        ///to move player l's other pieces
        void movePieceA(int position, char p, int Roll, int r, int c);
        void movePieceB(int position, char p, int Roll, int r, int c);
        void movePieceC(int position, char p, int Roll, int r, int c);
        void movePieceD(int position, char p, int Roll, int r, int c);
        void movePieceE(int position, char p, int Roll, int r, int c);
        void movePieceF(int position, char p, int Roll, int r, int c);

        void movePiece2(int position, char p, int Roll, int r, int c);///to move player n's first piece

        ///to move player n's other pieces
        void move1(int position, char p, int Roll, int r, int c);
        void move2(int position, char p, int Roll, int r, int c);
        void move3(int position, char p, int Roll, int r, int c);
        void move4(int position, char p, int Roll, int r, int c);
        void move5(int position, char p, int Roll, int r, int c);
        void move6(int position, char p, int Roll, int r, int c);

        ///to initialize player l's other pieces
        void initializeA(char gamePiece);
        void initializeB(char gamePiece);
        void initializeC(char gamePiece);
        void initializeD(char gamePiece);
        void initializeE(char gamePiece);
        void initializeF(char gamePiece);

        ///to initialize player n's other pieces
        void initialize1(char gamePiece);
        void initialize2(char gamePiece);
        void initialize3(char gamePiece);
        void initialize4(char gamePiece);
        void initialize5(char gamePiece);
        void initialize6(char gamePiece);

        int getScoreA(); ///return player l's and n's score
        bool getNotBlank(); ///see if there are blank spaces on the board
        int getRowA(); ///return the row of player l's first piece
        int getColA(); ///return the column of player l's first piece
        int getRow1(); ///return the row of player n's first piece
        int getCol1(); ///return the column of player n's first piece
        char getPiece();
        int getTurn();

        ///return the rows and columns of player l and n's pieces
        int getRA();
        int getCA();
        int getRB();
        int getCB();
        int getRC();
        int getCC();
        int getRD();
        int getCD();
        int getRE();
        int getCE();
        int getRF();
        int getCF();
        int getR1();
        int getC1();
        int getR2();
        int getC2();
        int getR3();
        int getC3();
        int getR4();
        int getC4();
        int getR5();
        int getC5();
        int getR6();
        int getC6();

        bool findEmpty();

        void moveBottomRight_L(int position, char p, int row, int col);
};


#endif // BOARD_H
