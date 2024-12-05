#include "Player.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

///constructor to initialize member variables
Player::Player()
{
    roll = 0, turnA = 0, turnB = 0, turnC = 0, turnD = 0;
    turnE = 0, turnF = 0;
    scoreL = 0, scoreN = 0;
    turn1 = 0, turn2 = 0, turn3 = 0, turn4 = 0, turn5 = 0;
    turn6 = 0;
}

void Player::playing()
{
    int turn = 0;
    int player1Counter = 0;

    ///to initialize the players in the beginning of the game
    while(turn !=2)
    {
      char piece, n;
      player.playGame();
      cout << endl;
      cout << "Player L score: " << R1.getScore1() << endl;
      cout << "Player N score: " << R1.getScore2() << endl;
      cout << endl << endl;
      generateRoll();
      if(player1Counter == 0)
      {
         R1.pieceSelectionPL();
         piece = R1.getPiece1();
         system("cls");
         player.initializePlayer1(piece);
         player1Counter++;
      }
      else if(player1Counter == 1)
      {
         R1.pieceSelectionPN();
         piece = R1.getPiece2();
         system("cls");
         player.initializePlayer2(piece);
         player1Counter++;
      }

      turn++;
    }

    ///to play the game after the two pieces are initialized in the beginning
    while(R1.getScore1() !=6 && R1.getScore2() !=6)
     {
         do
         {
        char p1, l, k, moveRowSpaces1, n;
        ///print the board and allow players to play the game
        player.playGame();
        cout << endl;
        ///display the scores of each player
        cout << "Player L score: " << R1.getScore1() << endl;
        cout << "Player N score: " << R1.getScore2() << endl;
        cout << endl << endl;
        generateRoll();

        ///ask player to enter piece and get piece
        R1.P1_moveAcross();
        R1.getCounter1();
        p1 = R1.getPiece1();
        bool ifTrue = R1.getCounter1();

        ///for the first piece placed on the board
        if(ifTrue == true && R1.equal_1() == true)
        {
            ///get information about player piece and move it to the board
            moveRowSpaces1 = roll*2;
            k = player.getRowA();
            l = player.getColA();
            player.movePiece1(moveRowSpaces1, p1, roll, k, l);
            if(player.getRowA() == 0 && player.getColA() == 0 && player.findEmpty() == true)
            {
                player.initializePlayer1(p1);
            }
            ///calculate the score
            scoreL += player.getScoreA();
                R1.setScore1(scoreL);
                if(R1.getScore1() == 6)
                {
                    R1.winner();
                    break;
                }
            ///system("cls");
        }

        ///for other pieces of player l, not the first piece placed on the board
        else if(ifTrue && R1.equal_1() == false && R1.getOtherInput() == 'A')
        {
            char p1 = R1.getOtherInput();

            if(turnA!=1)
            {
                ///initialize the piece on the baord
                player.initializeA(R1.getOtherInput());
                turnA++;
            }

            else if(turnA == 1)
            {
                ///once initialized, get info about piece and move it correspondingly on board
                int moveRowSpaces1 = roll*2;
                int k = player.getRA();
                int l = player.getCA();
                player.movePieceA(moveRowSpaces1, p1, roll, k, l);
                ///calculate the score for player A
                scoreL += player.getScoreA();
                R1.setScore1(scoreL);
                if(R1.getScore1() == 6)
                {
                    R1.winner();
                    break;
                }
            }
        }
        ///the code from here until the end of the turnF if-else statement is the same thing repeated for area of code with turnA
        else if(ifTrue && R1.equal_1() == false && (R1.getOtherInput() == 'B'))
        {
            char p1 = R1.getOtherInput();

            if(turnB!=1)
            {
                player.initializeB(R1.getOtherInput());
                turnB++;
            }
            else if(turnB == 1)
            {
               int moveRowSpaces1 = roll*2;
               int k = player.getRB();
               int l = player.getCB();
               player.movePieceB(moveRowSpaces1, p1, roll, k, l);
               scoreL = scoreL + player.getScoreA();
               R1.setScore1(scoreL);
               if(R1.getScore1() == 6)
               {
                R1.winner();
                break;
              }

            }

        }
        else if(ifTrue && R1.equal_1() == false && R1.getOtherInput() == 'C')
        {
            char p1 = R1.getOtherInput();

            if(turnC!=1)
            {
                player.initializeC(R1.getOtherInput());
                turnC++;
            }
            else if(turnC == 1)
            {
                int moveRowSpaces1 = roll*2;
                int k = player.getRC();
                int l = player.getCC();
                player.movePieceC(moveRowSpaces1, p1, roll, k, l);
                scoreL += player.getScoreA();
                R1.setScore1(scoreL);
                if(R1.getScore1() == 6)
                {
                    R1.winner();
                    break;
                }
            }
        }
        else if(ifTrue && R1.equal_1() == false && R1.getOtherInput() == 'D')
        {
            char p1 = R1.getOtherInput();

            if(turnD!=1)
            {
                player.initializeD(R1.getOtherInput());
                turnD++;
            }
            else if(turnD == 1)
            {
                int moveRowSpaces1 = roll*2;
                int k = player.getRD();
                int l = player.getCD();
                player.movePieceD(moveRowSpaces1, p1, roll, k, l);
                scoreL += player.getScoreA();
                R1.setScore1(scoreL);
                if(R1.getScore1() == 6)
                {
                    R1.winner();
                    break;
                }
            }
        }
        else if(ifTrue && R1.equal_1() == false && R1.getOtherInput() == 'E')
        {
            char p1 = R1.getOtherInput();

            if(turnE!=1)
            {
                player.initializeE(R1.getOtherInput());
                turnE++;
            }
            else if(turnE == 1)
            {
                int moveRowSpaces1 = roll*2;
                int k = player.getRE();
                int l = player.getCE();
                player.movePieceE(moveRowSpaces1, p1, roll, k, l);
                scoreL += player.getScoreA();
                R1.setScore1(scoreL);
                if(R1.getScore1() == 6)
                {
                    R1.winner();
                    break;
                }
            }
        }
        else if(ifTrue && R1.equal_1() == false && R1.getOtherInput() == 'F')
        {
            char p1 = R1.getOtherInput();

            if(turnF!=1)
            {
                player.initializeF(R1.getOtherInput());
                turnF++;
            }
            else if(turnF == 1)
            {
                int moveRowSpaces1 = roll*2;
                int k = player.getRF();
                int l = player.getCF();
                player.movePieceF(moveRowSpaces1, p1, roll, k, l);
                scoreL += player.getScoreA();
                R1.setScore1(scoreL);
                if(R1.getScore1() == 6)
                {
                    R1.winner();
                    break;
                }
            }
        }

        }
        ///if there are no blank spaces, repeat this segement of code
        while(player.getNotBlank() == true);

        ///code here is repeated as above
        do
        {
        char p2;
        player.playGame();
        cout << endl;
        cout << "Player L score: " << R1.getScore1() << endl;
        cout << "Player N score: " << R1.getScore2() << endl;
        cout << endl << endl;
        generateRoll();
        R1.P2_moveAcross();
        R1.getCounter2();
        R1.getPiece2();
        p2 = R1.getPiece2();
        bool ifT = R1.getCounter2();
        if(ifT == true && R1.equal_2() == true)
        {
            int moveRowSpaces2 = roll*2;
            int k = player.getRow1();
            int l = player.getCol1();
            player.movePiece2(moveRowSpaces2, p2, roll, k, l);
            scoreN += player.getScoreA();

            R1.setScore2(scoreN);
            if(R1.getScore2() == 6)
            {
               R1.winner();
            }
            ///system("cls");
        }
        else if(ifT && R1.equal_2() == false && R1.getNormalPiece2() == '1')
        {
            char p1 = R1.getNormalPiece2();

            if(turn1!=1)
            {
                player.initialize1(R1.getNormalPiece2());
                turn1++;
            }
            else if(turn1 == 1)
            {
                int moveRowSpaces1 = roll*2;
                int k = player.getR1();
                int l = player.getC1();
                player.move1(moveRowSpaces1, p1, roll, k, l);
                scoreN += player.getScoreA();
                R1.setScore2(scoreN);
                if(R1.getScore2() == 6)
                {
                    R1.winner();
                    break;
                }
            }
        }
        else if(ifT && R1.equal_2() == false && R1.getNormalPiece2() == '2')
        {
            char p1 = R1.getNormalPiece2();

            if(turn2!=1)
            {
                player.initialize2(R1.getNormalPiece2());
                turn2++;
            }
            else if(turn2 == 1)
            {
                int moveRowSpaces1 = roll*2;
                int k = player.getR2();
                int l = player.getC2();
                player.move2(moveRowSpaces1, p1, roll, k, l);
                scoreN += player.getScoreA();
                R1.setScore2(scoreN);
                if(R1.getScore2() == 6)
                {
                    R1.winner();
                    break;
                }
            }
        }
        else if(ifT && R1.equal_2() == false && R1.getNormalPiece2() == '3')
        {
            char p1 = R1.getNormalPiece2();

            if(turn3!=1)
            {
                player.initialize3(R1.getNormalPiece2());
                turn3++;
            }
            else if(turn3 == 1)
            {
                int moveRowSpaces1 = roll*2;
                int k = player.getR3();
                int l = player.getC3();
                player.move3(moveRowSpaces1, p1, roll, k, l);
                scoreN += player.getScoreA();
                R1.setScore2(scoreN);
                if(R1.getScore2() == 6)
                {
                    R1.winner();
                    break;
                }
            }
        }
        else if(ifT && R1.equal_2() == false && R1.getNormalPiece2() == '4')
        {
            char p1 = R1.getNormalPiece2();

            if(turn4!=1)
            {
                player.initialize4(R1.getNormalPiece2());
                turn4++;
            }
            else if(turn4 == 1)
            {
                int moveRowSpaces1 = roll*2;
                int k = player.getR4();
                int l = player.getC4();
                player.move4(moveRowSpaces1, p1, roll, k, l);
                scoreN += player.getScoreA();
                R1.setScore2(scoreN);
                if(R1.getScore2() == 6)
                {
                    R1.winner();
                    break;
                }
            }
        }
        else if(ifT && R1.equal_2() == false && R1.getNormalPiece2() == '5')
        {
            char p1 = R1.getNormalPiece2();

            if(turn5!=1)
            {
                player.initialize5(R1.getNormalPiece2());
                turn5++;
            }
            else if(turn5 == 1)
            {
                int moveRowSpaces1 = roll*2;
                int k = player.getR5();
                int l = player.getC5();
                player.move5(moveRowSpaces1, p1, roll, k, l);
                scoreN += player.getScoreA();
                R1.setScore2(scoreN);
                if(R1.getScore2() == 6)
                {
                    R1.winner();
                    break;
                }
            }
        }
        else if(ifT && R1.equal_2() == false && R1.getNormalPiece2() == '6')
        {
            char p1 = R1.getNormalPiece2();

            if(turn6!=1)
            {
                player.initialize6(R1.getNormalPiece2());
                turn6++;
            }
            else if(turn6 == 1)
            {
                int moveRowSpaces1 = roll*2;
                int k = player.getR6();
                int l = player.getC6();
                player.move6(moveRowSpaces1, p1, roll, k, l);
                scoreN += player.getScoreA();
                R1.setScore2(scoreN);
                if(R1.getScore2() == 6)
                {
                    R1.winner();
                    break;
                }
            }
        }

        }
        while(player.getNotBlank() == true);
}

}

///generate random dice rolls from 0-5
void Player::generateRoll()
{
    srand(time(0));
    roll = rand()%6;
    cout << "Your roll is: " << roll << endl;
}

