#ifndef PLAYER_H
#define PLAYER_H
#include "Board.h"
#include "Referee.h"

class Player
{
    Board player; ///reference to board
    Referee R1; ///reference to referee
    ///roll = dice roll, turnA-F = for player l, turn1-6 = for player n
    int roll, turnA, turnB, turnC, turnD, turnE, turnF, scoreL;
    int scoreN, turn1, turn2, turn3, turn4, turn5, turn6;

public:
    Player(); ///constructor
    void playing(); ///players playing the game
    void generateRoll(); ///generate randomly generated dice roll
};


#endif // PLAYER_H
