#include <iostream>
#include "Referee.h"

using namespace std;

///constructor to initialize member variables
Referee::Referee()
{
    input1 = ' ', input2 = ' ', normalPiece1 = ' ', normalPiece2 = ' ';
    counter1 = false, counter2 = false;
    score1 = 0;
    score2 = 0;
    equalInput1 = false, equalInput2 = false;
}

///to initialize the first piece of player l
void Referee::pieceSelectionPL()
{
    do
    {
        cout << "Player L Select Piece (A, B, C, D, E, F) or P (forfeit): ";
        cin >> input1;
    }
    while(input1 != 'A' && input1 != 'B' && input1 != 'C' && input1 != 'D' && input1 != 'E' && input1 != 'F');

}

///to initialize the first piece of player n
void Referee::pieceSelectionPN()
{
    do
    {
        cout << "Player N Select Piece (1, 2, 3, 4, 5, 6) or P (forfeit): ";
        cin >> input2;
    }
    while(input2 != '1' && input2 != '2' && input2 != '3' && input2 != '4' && input2 != '5' && input2 != '6');
}

///return the inputs to player adt to play game
char Referee::getPiece1()
{
    return input1;
}

char Referee::getPiece2()
{
   return input2;
}

///move player l pieces across once pieces are initialized in the beginning
void Referee::P1_moveAcross()
{
    do
    {
        cout << "Player L Select Piece (A, B, C, D, E, F) or P (forfeit): ";
        cin >> normalPiece1;
        if((normalPiece1 == 'A' ||normalPiece1 == 'B' || normalPiece1 == 'C' || normalPiece1 == 'D' || normalPiece1 == 'E' || normalPiece1 == 'F'))
        {
            break;
        }
    }
    while(normalPiece1 != input1 && normalPiece1 != 'P');

    if(normalPiece1 == input1 || (normalPiece1 == 'A' || normalPiece1 == 'B' || normalPiece1 == 'C'|| normalPiece1 == 'D' || normalPiece1 == 'E' || normalPiece1 == 'F'))
    {
        counter1 = true;
    }
    if(normalPiece1 == input1)
    {
        equalInput1 = true;
    }
    else if(normalPiece1 != input1)
    {
        equalInput1 = false;
    }
    if(normalPiece1 == 'P')
    {
        counter1 = false;
    }

}

///return necessary inputs
int Referee::getCounter1()
{
    return counter1;
}

///move player n piece across once pieces are initialized in the beginning
void Referee::P2_moveAcross()
{
    do
    {
        cout << "Player N Select Piece (1, 2, 3, 4, 5, 6) or P (forfeit): ";
        cin >> normalPiece2;
        if((normalPiece2 == '1' ||normalPiece2 == '2' || normalPiece2 == '3' || normalPiece2 == '4' || normalPiece2 == '5' || normalPiece2 == '6'))
        {
            break;
        }
    }
    while(normalPiece2 != input2 && normalPiece2 != 'P');

    if(normalPiece2 == input2 || (normalPiece2 == '1' || normalPiece2 == '2' || normalPiece2 == '3'|| normalPiece2 == '4' || normalPiece2 == '5' || normalPiece2 == '6'))
    {
        counter2 = true;
    }
    if(normalPiece2 == input2)
    {
        equalInput2 = true;
    }
    else if(normalPiece2 != input2)
    {
        equalInput2 = false;
    }
    if(normalPiece2 == 'P')
    {
        counter2 = false;
    }

}

///return necessary inputs
int Referee::getCounter2()
{
    return counter2;
}

///display winner of the game
void Referee::winner()
{
    if(score1 == 6)
    {
        system("cls");
        cout << "Player L score: " << score1 << endl;
        cout << "Player L wins!";
    }
    else if(score2 == 6)
    {
        system("cls");
        cout << "Player N score: " << score2 << endl;
        cout << "Player N wins!";
    }
}

///return necessary inputs
int Referee::getScore1()
{
    return score1;
}

int Referee::getScore2()
{
    return score2;
}

///set scores for both players
void Referee::setScore1(int s)
{
    score1 = s;
}

void Referee::setScore2(int s)
{
    score2 = s;
}

///return necessary inputs
bool Referee::equal_1()
{
    return equalInput1;
}

char Referee::getOtherInput()
{
    return normalPiece1;
}

char Referee::getNormalPiece2()
{
    return normalPiece2;
}

bool Referee::equal_2()
{
    return equalInput2;
}

