#ifndef REFEREE_H
#define REFEREE_H
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include "Board.h"

class Referee
{
    char input1, input2, normalPiece1, normalPiece2;
    bool counter1, counter2;
    int score1, score2; ///scores for each player
    bool equalInput1, equalInput2;
    Board Ref; ///reference to board

public:
    Referee(); ///constructor
    void pieceSelectionPL(); ///allow user to enter initial input for player l
    void pieceSelectionPN(); ///allow user to enter initial input for player n
    char getPiece1();
    char getPiece2();
    void P1_moveAcross(); ///move player l piece across
    void P2_moveAcross(); ///move player n piece across
    int getCounter1();
    int getCounter2();
    ///return score to player adt
    int getScore1();
    int getScore2();
    ///display winner
    void winner();
    ///set the score
    void setScore1(int s);
    void setScore2(int s);
    bool equal_1();
    char getOtherInput();
    char getNormalPiece2();
    bool equal_2();
};

#endif // REFEREE_H
