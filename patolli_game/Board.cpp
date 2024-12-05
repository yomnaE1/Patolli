#include "Board.h"
#include "iostream"
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;

///constructor to initialize all members
Board::Board()
{
    for(int i = 0; i < 33; i++)
    {
       for(int j = 0; j < 33; j++)
       {
           grid[i][j] = ' ';
       }
    }

    a = 0,  currentRowA = 0, currentColA = 0;
    rotationAinitial = 0;
    rA = 0, rB = 0, rC = 0, rD = 0, rE = 0, rF = 0;

    rotation1initial = 0;
    r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0, r6 = 0;
    foundP1 = false, foundP2 = false;
    currentRow1 = 0, currentCol1 = 0, score = 0, score1 = 0;
    RowA = 0, ColA = 0, RowB = 0, ColB = 0;
    RowC = 0, ColC = 0, RowD = 0, ColD = 0, RowE = 0, ColE = 0;
    RowF = 0, ColF = 0;
    Row1 = 0, Row2 = 0, Row3 = 0, Row4 = 0, Row5 = 0, Row6 = 0;
    Col1 = 0, Col2 = 0, Col3 = 0, Col4 = 0, Col5 = 0, Col6 = 0;

    Counter1 = 0;
    counterA =0;
    counterB = 0;
    counterC = 0;
    counterD = 0;
    counterE = 0;
    counterF = 0;

    Counter2 = 0;
    counter1 = 0;
    counter2 = 0;
    counter3 = 0;
    counter4 = 0;
    counter5 = 0;
    counter6 = 0;

    gp = ' ', GP = ' ', g = ' ';
    notBlank = false;
    mr1 = 0;
}

///this function prints the board itself
void Board::playGame()
{
 for(int i = 0; i < 33; i++)
 {
     for(int j = 0; j < 33; j++)
     {
        if(i%2==0 && (i!=14 || i!=16 || i!=18) && j>=14 && j<=18)
        {
           grid[i][j] = '-';
           cout << grid[i][j];
        }
        else if(i%2!=0 && (i!=15 || i!=17) && j==14 || j==16 || j==18)
        {
            grid[i][j] = '|';
            cout << grid[i][j];
        }
        else if(i==14 || i==16 || i==18 && j>=0 && j<=32)
        {
            grid[i][j] = '-';
            cout << grid[i][j];
        }
        else if((i== 17 || i==15) && j%2==0)
        {
           grid[i][j] = '|';
           cout << grid[i][j];
        }
        else if((i == currentRowA && j == currentColA))
        {
            cout << grid[currentRowA][currentColA];
        }
        else if(i== currentRow1 && j== currentCol1)
        {
            cout << grid[currentRow1][currentCol1];
        }
        else if(i == RowA && j == ColA)
        {
            cout << grid[RowA][ColA];
        }
        else if(i == RowB && j == ColB)
        {
            cout << grid[RowB][ColB];
        }
        else if(i == RowC && j == ColC)
        {
            cout << grid[RowC][ColC];
        }
        else if(i == RowD && j == ColD)
        {
            cout << grid[RowD][ColD];
        }
        else if(i == RowE && j == ColE)
        {
            cout << grid[RowE][ColE];
        }
        else if(i == RowF && j == ColF)
        {
            cout << grid[RowF][ColF];
        }
        else if(i == Row1 && j == Col1)
        {
            cout << grid[Row1][Col1];
        }
        else if(i == Row2 && j == Col2)
        {
            cout << grid[Row2][Col2];
        }
        else if(i == Row3 && j == Col3)
        {
            cout << grid[Row3][Col3];
        }
        else if(i == Row4 && j == Col4)
        {
            cout << grid[Row4][Col4];
        }
        else if(i == Row5 && j == Col5)
        {
            cout << grid[Row5][Col5];
        }
        else if(i == Row6 && j == Col6)
        {
            cout << grid[Row6][Col6];
        }
        else
        {
            grid[i][j] = ' ';
            cout << grid[i][j];
        }
     }
     cout << endl;
 }
}

///this function initializes the first player (player L) in the initial position
void Board::initializePlayer1(char gamePiece)
{
    for(int i = 0; i < 33; i++)
    {
        for(int j = 0; j < 33; j++)
        {
            if(i==19 && j==17)
            {
               grid[i][j] = gamePiece;
               currentRowA = i;
               currentColA = j;
            }
        }
    }
    GP = gamePiece;
}

///this function initializes the first player (player L)
///if piece A is not the first piece placed on the board
void Board::initializeA(char gamePiece)
{
    for(int i = 0; i < 33; i++)
    {
        for(int j = 0; j < 33; j++)
        {
            if(i==19 && j==17 && grid[19][17] == ' ')
            {
               grid[i][j] = gamePiece;
               RowA = i;
               ColA = j;
            }
        }
    }
}

///this function initializes the first player (player L)
///if piece B is not the first piece placed on the board
void Board::initializeB(char gamePiece)
{
    for(int i = 0; i < 33; i++)
    {
        for(int j = 0; j < 33; j++)
        {
            if(i==19 && j==17 && grid[19][17] == ' ')
            {
               grid[i][j] = gamePiece;
               RowB = i;
               ColB = j;
            }
        }
    }
}

///this function initializes the first player (player L)
///if piece C is not the first piece placed on the board
void Board::initializeC(char gamePiece)
{
    for(int i = 0; i < 33; i++)
    {
        for(int j = 0; j < 33; j++)
        {
            if(i==19 && j==17 && grid[19][17] == ' ')
            {
               grid[i][j] = gamePiece;
               RowC = i;
               ColC = j;
            }
        }
    }
}

///this function initializes the first player (player L)
///if piece D is not the first piece placed on the board
void Board::initializeD(char gamePiece)
{
    for(int i = 0; i < 33; i++)
    {
        for(int j = 0; j < 33; j++)
        {
            if(i==19 && j==17 && grid[19][17] == ' ')
            {
               grid[i][j] = gamePiece;
               RowD = i;
               ColD = j;
            }
        }
    }
}

///this function initializes the first player (player L)
///if piece E is not the first piece placed on the board
void Board::initializeE(char gamePiece)
{
    for(int i = 0; i < 33; i++)
    {
        for(int j = 0; j < 33; j++)
        {
            if(i==19 && j==17 && grid[19][17] == ' ')
            {
               grid[i][j] = gamePiece;
               RowE = i;
               ColE = j;
            }
        }
    }
}

///this function initializes the first player (player L)
///if piece F is not the first piece placed on the board
void Board::initializeF(char gamePiece)
{
    for(int i = 0; i < 33; i++)
    {
        for(int j = 0; j < 33; j++)
        {
            if(i==19 && j==17 && grid[19][17] == ' ')
            {
               grid[i][j] = gamePiece;
               RowF = i;
               ColF = j;
            }
        }
    }
}

///this function initializes the second player (player N)
void Board::initializePlayer2(char gamePiece)
{
    for(int i = 0; i < 33; i++)
    {
        for(int j = 0; j < 33; j++)
        {
            if(i==13 && j==15)
            {
               grid[i][j] = gamePiece;
               currentRow1 = i;
               currentCol1 = j;
            }
        }
    }

    gp = gamePiece;
}

///this function initializes the first player (player L)
///if piece 1 is not the first piece placed on the board
void Board::initialize1(char gamePiece)
{
    for(int i = 0; i < 33; i++)
    {
        for(int j = 0; j < 33; j++)
        {
            if(i==13 && j==15)
            {
               grid[i][j] = gamePiece;
               Row1 = i;
               Col1 = j;
            }
        }
    }
}

///this function initializes the first player (player L)
///if piece 2 is not the first piece placed on the board
void Board::initialize2(char gamePiece)
{
    for(int i = 0; i < 33; i++)
    {
        for(int j = 0; j < 33; j++)
        {
            if(i==13 && j==15)
            {
               grid[i][j] = gamePiece;
               Row2 = i;
               Col2 = j;
            }
        }
    }
}

///this function initializes the first player (player L)
///if piece 3 is not the first piece placed on the board
void Board::initialize3(char gamePiece)
{
     for(int i = 0; i < 33; i++)
    {
        for(int j = 0; j < 33; j++)
        {
            if(i==13 && j==15)
            {
               grid[i][j] = gamePiece;
               Row3 = i;
               Col3 = j;
            }
        }
    }
}

///this function initializes the first player (player L)
///if piece 4 is not the first piece placed on the board
void Board::initialize4(char gamePiece)
{
    for(int i = 0; i < 33; i++)
    {
        for(int j = 0; j < 33; j++)
        {
            if(i==13 && j==15)
            {
               grid[i][j] = gamePiece;
               Row4 = i;
               Col4 = j;
            }
        }
    }
}

///this function initializes the first player (player L)
///if piece 5 is not the first piece placed on the board
void Board::initialize5(char gamePiece)
{
    for(int i = 0; i < 33; i++)
    {
        for(int j = 0; j < 33; j++)
        {
            if(i==13 && j==15)
            {
               grid[i][j] = gamePiece;
               Row5 = i;
               Col5 = j;
            }
        }
    }
}

///this function initializes the first player (player L)
///if piece 6 is not the first piece placed on the board
void Board::initialize6(char gamePiece)
{
    for(int i = 0; i < 33; i++)
    {
        for(int j = 0; j < 33; j++)
        {
            if(i==13 && j==15)
            {
               grid[i][j] = gamePiece;
               Row6 = i;
               Col6 = j;
            }
        }
    }
}

///returns the row of player l's first piece on the board
int Board::getRowA()
{
    return currentRowA;
}

///returns the column of player l's first piece on the board
int Board::getColA()
{
    return currentColA;
}

///to move the first piece for Player L
void Board::movePiece1(int position, char p, int Roll, int r, int c)
{
    int l = r; ///get the previous row position of the same piece and store it into l
    int k = c; ///get the previous col position of the same piece and store it into l
    char piece;
    int roll = 0, turn = 0;

        /// moving in the right bottom area
        if(currentRowA>=19 && currentRowA<=31 && currentColA == 17)
        {
                currentRowA = currentRowA + position;

                if (currentRowA == 31)
                {
                    /// additional turn
                    turn++;
                    grid[currentRowA][currentColA] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                    piece = ' ';

                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!= 'A' && piece != 'B' && piece!= 'C' && piece != 'D' && piece != 'E' && piece != 'F');
                    }

                    mr1 = roll*2;

                    if(piece == p)
                    {
                      movePiece1(mr1, p, Roll, 31, 17);
                    }
                    else
                    {
                        g = piece;
                    }
                }

                ///for additional turns as well
                if (currentRowA > 31)
                {
                    int difference;
                    difference = currentRowA - 31;

                    if (difference == 2)
                    {
                        currentRowA -= 2;
                        currentColA -= 2;
                        grid[currentRowA][currentColA] = p;
                        turn++;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!= 'A' && piece != 'B' && piece!= 'C' && piece != 'D' && piece != 'E' && piece != 'F');

                    mr1 = roll*2;

                    if(piece == p)
                    {
                      movePiece1(mr1, p, Roll, 31, 15);
                    }
                    else
                    {
                       g = piece;
                    }

                    }
                    else
                    {
                        currentRowA = 31 - ((currentRowA % 31)- 2);
                        currentColA -= 2;
                    }
                }

                ///sees if there are any blank spaces where you landed
                if(grid[currentRowA][currentColA] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       currentRowA = l;
                       currentColA = k;
                       grid[currentRowA][currentColA] = p;
                }
                else
                {
                    notBlank = false;
                    grid[currentRowA][currentColA] = p;
                }
        }


        /// moving in the left bottom area
        else if(currentRowA >=19 && currentRowA <=31 && currentColA ==15)
        {
            if(currentRowA + position != 17 && currentColA + position!=32)
            {
                currentRowA = currentRowA - position;

                if (currentRowA < 17)
                {
                    int difference;
                    difference = 17 - currentRowA;

                    if(difference == 2)
                    {
                        currentRowA = 17;
                        currentColA = currentColA - 2;
                    }
                    else
                    {
                        currentColA = 15 - ((17 % currentRowA));
                        currentRowA += 17 % currentRowA;
                    }
                }
            }

            ///sees if there are any blank spaces where you landed
             if(grid[currentRowA][currentColA] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       currentRowA = l;
                       currentColA = k;
                       grid[currentRowA][currentColA] = p;
                }
                else
                {
                    notBlank = false;
                    grid[currentRowA][currentColA] = p;
                }
        }

        /// moving in the Middle area Lower row (left bottom)
        else if(currentRowA ==17 && currentColA >0 && currentColA <=15)
        {
                currentColA = currentColA - position;

                if (currentColA < 0)
                {
                    int difference;
                    difference = abs(currentColA);

                    if(difference == 2)
                    {
                        currentRowA = 15;
                        currentColA = 1;
                    }
                    else
                    {
                        currentColA = difference;
                        currentRowA = 15;
                    }
                }

                if(currentColA == 1)
                {
                    ///for additional turns
                    turn++;
                    grid[currentRowA][currentColA] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!= 'A' && piece != 'B' && piece!= 'C' && piece != 'D' && piece != 'E' && piece != 'F');
                    }

                    mr1 = roll*2;
                    if(piece == p)
                        movePiece1(mr1, p, Roll, 31, currentColA);
                    else
                    {
                        g = piece;
                    }
                }

            ///see if there are any blank spaces where you landed
                if(grid[currentRowA][currentColA] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       currentRowA = l;
                       currentColA = k;
                       grid[currentRowA][currentColA] = p;
                }
                else
                {
                    notBlank = false;
                    grid[currentRowA][currentColA] = p;
                }
        }

        /// moving in the MIDDLE area upper row (left)
        else if(currentRowA ==15 && currentColA >0 && currentColA <=15)
        {
                currentColA = currentColA + position;

                if (currentColA > 15)
                {
                    int difference;
                    difference = abs(currentColA - 15);

                    if(difference == 2)
                    {
                        currentRowA = 13;
                        currentColA = 15;
                    }
                    else
                    {
                        currentRowA -= difference;
                        currentColA = 15;
                    }
                }

          ///see if there are any blank spaces where you landed
                if(grid[currentRowA][currentColA] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       currentRowA = l;
                       currentColA = k;
                       grid[currentRowA][currentColA] = p;
                }
                else
                {
                    notBlank = false;
                    grid[currentRowA][currentColA] = p;
                }
        }

        /// moving in the MIDDLE TOP area (left)
        else if(currentRowA >=0  && currentRowA <=13 && currentColA ==15)
        {
                currentRowA = currentRowA - position;

                if (currentRowA < 1)
                {
                    int difference;
                    difference = abs(currentRowA - 1) ;

                    if(difference == 2)
                    {
                        currentRowA = 1;
                        currentColA = 17;
                    }
                    else
                    {
                        currentRowA = difference-1;
                        currentColA = 17;
                    }
                }

                if(currentRowA == 1)
                {
                    ///for additional turns
                    turn++;
                   grid[currentRowA][currentColA] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePiece1(moveRowSpaces1, p, Roll, r, c);
                }
                ///see if there are any blank spaces where you landed
                if(grid[currentRowA][currentColA] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       currentRowA = l;
                       currentColA = k;
                       grid[currentRowA][currentColA] = p;
                }
                else
                {
                    notBlank = false;
                    grid[currentRowA][currentColA] = p;
                }
        }

        /// moving in the MIDDLE TOP area (right)
        else if(currentRowA >=1 && currentRowA <= 15 && currentColA == 17)
        {
            currentRowA = currentRowA + position;

            if(currentRowA > 15)
            {
                int difference;
                difference = abs(currentRowA - 15);
                 if (difference == 2)
                    {
                        currentRowA = 15;
                        currentColA = 19;
                    }
                    else
                    {
                        currentRowA = 15;
                        currentColA += difference;
                    }
            }

            ///see if there are any blank spaces where you landed
               if(grid[currentRowA][currentColA] != ' ' && Roll != 0 )
                {
                       notBlank = true;
                       currentRowA = l;
                       currentColA = k;
                       grid[currentRowA][currentColA] = p;
                }
                else
                {
                    notBlank = false;
                    grid[currentRowA][currentColA] = p;
                }
        }


        ///moving upper middle area (right side of the board)
        else if(currentRowA == 15 && currentColA > 17 && currentColA <=31)
        {
                currentColA = currentColA + position;

                if (currentColA > 31)
                {
                    int difference;
                    difference = abs(currentColA - 31) ;

                    if(difference == 2)
                    {
                        currentRowA = 17;
                        currentColA = 31;
                    }
                    else
                    {
                        currentRowA = 17;
                        currentColA = 31 - (difference-2);
                    }
                }

                if(currentColA == 31)
                {
                    ///for additional turns
                    turn++;
                    grid[currentRowA][currentColA] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                    char piece = ' ';

                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePiece1(moveRowSpaces1, p, Roll, r, c);
                }

            ///see if there are any blank spaces where you landed
             if(grid[currentRowA][currentColA] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       currentRowA = l;
                       currentColA = k;
                       grid[currentRowA][currentColA] = p;
                }
                else
                {
                    notBlank = false;
                    grid[currentRowA][currentColA] = p;
                }
        }


        ///moving in middle area right (bottom)
        else if((currentRowA == 17 && currentColA > 16 && currentColA <= 31))
        {
            currentColA = currentColA - position;
                if(grid[currentRowA][currentColA] != ' ' && Roll != 0)
                {
                    ///to see if there are any blank spaces on the board
                       notBlank = true;
                       currentRowA = l;
                       currentColA = k;
                       grid[currentRowA][currentColA] = p;
                }
                else if(currentColA == 19 && currentRowA == 17 && Counter1 == 0 && (p == 'A' || p == 'B' || p == 'C' || p == 'D' || p == 'E' || p == 'F'))
                {
                    ///calculating the score when the piece reaches the end of the board
                    score = 1;
                    grid[19][17] = ' ';
                    Counter1++;
                }
                else if(currentColA < 19)
                {
                       currentRowA = 0;
                       currentColA = 0;
                }
                else
                {
                    notBlank = false;
                    grid[currentRowA][currentColA] = p;
                }
        }
}

///see if there is any blank spaces in the initial position of l, so player l can add new pieces
bool Board::findEmpty()
{
    if(grid[19][17] == ' ')
    {
       return true;
    }
    else
    {
        return false;
    }
}

///to move player n's first piece
void Board::movePiece2(int position, char p, int Roll, int r, int c)
{
    int l = r;///get the previous row of the same piece
    int k = c;///get the previous col of the same piece
    int turn = 0;

     /// moving to the top (left)
      if(currentRow1 >=0  && currentRow1 <=13 && currentCol1 ==15)
        {
                currentRow1 = currentRow1 - position;

                if (currentRow1 < 1)
                {
                    int difference;
                    difference = abs(currentRow1 - 1);

                    if(difference == 2)
                    {
                        currentRow1 = 1;
                        currentCol1 = 17;
                    }
                    else
                    {
                        currentRow1 = difference-1;
                        currentCol1 = 17;
                    }
                }

                if(currentRow1 == 1)
                {
                    ///for additional turns
                    turn++;
                   grid[currentRow1][currentCol1] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                    char piece = ' ';

                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces2 = roll*2;
                    movePiece2(moveRowSpaces2, p, Roll, r,c);
                }

            ///see if there are any blank spaces where you landed
              if(grid[currentRow1][currentCol1] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       currentRow1 = l;
                       currentCol1 = k;
                       grid[currentRow1][currentCol1] = p;
                }
                else
                {
                    notBlank = false;
                    grid[currentRow1][currentCol1] = p;
                }
        }

        ///moving to the bottom (right)
        else if(currentRow1 >=1 && currentRow1 <= 15 && currentCol1 == 17)
        {
            currentRow1 = currentRow1 + position;

            if(currentRow1 > 15)
            {
                int difference;
                difference = abs(currentRow1 - 15);
                 if (difference == 2)
                    {
                        currentRow1 = 15;
                        currentCol1 = 19;
                    }
                    else
                    {
                        currentRow1 = 15;
                        currentCol1 += difference;
                    }
            }

            ///see of there are any blank spaces where you landed
              if(grid[currentRow1][currentCol1] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       currentRow1 = l;
                       currentCol1 = k;
                       grid[currentRow1][currentCol1] = p;
                }
                else
                {
                    notBlank = false;
                    grid[currentRow1][currentCol1] = p;
                }
        }

        ///moving to the right (top part)
        else if(currentRow1 == 15 && currentCol1 > 17 && currentCol1 <=31)
        {
                currentCol1 = currentCol1 + position;

                if (currentCol1 > 31)
                {
                    int difference;
                    difference = abs(currentCol1 - 31) ;

                    if(difference == 2)
                    {
                        currentRow1 = 17;
                        currentCol1 = 31;
                    }
                    else
                    {
                        currentRow1 = 17;
                        currentCol1 = 31 - (difference-2);
                    }
                }

                if(currentCol1 == 31)
                {
                    ///for additional turns
                    turn++;
                    grid[currentRow1][currentCol1] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                    char piece = ' ';

                    ///to make sure piece stays in the same place when roll is 0
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePiece2(moveRowSpaces1, p, Roll, r, c);
                }

            ///see if there are any blank spaces where you landed
              if(grid[currentRow1][currentCol1] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       currentRow1 = l;
                       currentCol1 = k;
                       grid[currentRow1][currentCol1] = p;
                }
                else
                {
                    notBlank = false;
                    grid[currentRow1][currentCol1] = p;
                }
        }

        ///moving left (bottom part)
        else if(currentRow1 == 17 && currentCol1 > 16 && currentCol1 <= 31)
        {
            currentCol1 = currentCol1 - position;

               if (currentCol1 < 17)
                {
                    int difference;
                    difference = abs(17 - currentCol1);

                    if(difference == 2)
                    {
                        currentRow1 = 19;
                        currentCol1 = 17;
                    }
                    else
                    {
                        currentRow1 = 17 + (abs(currentCol1 - 17));
                        currentCol1 = 17;
                    }
                }

            ///see if there are any blank spaces where you landed
             if(grid[currentRow1][currentCol1] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       currentRow1 = l;
                       currentCol1 = k;
                       grid[currentRow1][currentCol1] = p;
                }
                else
                {
                    notBlank = false;
                    grid[currentRow1][currentCol1] = p;
                }
        }

        ///moving down(right)
        else if(currentRow1>=19 && currentRow1<=31 && currentCol1 == 17)
        {
                currentRow1 = currentRow1 + position;

                if (currentRow1 == 31)
                {
                    /// additional turn
                    turn++;
                    grid[currentRow1][currentCol1] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;
                    char piece = ' ';

                    ///make sure piece stays in place when roll is 0
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces2 = roll*2;
                    movePiece2(moveRowSpaces2, p, Roll, r, c);
                }

                if (currentRow1 > 31)
                {
                    int difference;
                    difference = currentRow1 - 31;

                    if (difference == 2)
                    {
                        ///for additional turns
                        currentRow1 = 31;
                        currentCol1 = 15;
                        grid[currentRow1][currentCol1] = p;
                    turn++;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;
                    char piece = ' ';

                    ///make sure piece stays in place when roll is 0
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePiece2(moveRowSpaces1, p, Roll, r, c);
                    }
                    else
                    {
                        currentRow1 = 31 - ((currentRow1 % 31)- 2);
                        currentCol1 -= 2;
                    }
                }

            ///see if there are any blank spaces where you landed
              if(grid[currentRow1][currentCol1] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       currentRow1 = l;
                       currentCol1 = k;
                       grid[currentRow1][currentCol1] = p;
                }
                else
                {
                    notBlank = false;
                    grid[currentRow1][currentCol1] = p;
                }
        }


        ///moving up (left)
        else if(currentRow1 >=19 && currentRow1 <=31 && currentCol1 ==15)
        {
            if(currentRow1 + position != 17 && currentCol1 + position!=32)
            {
                currentRow1 = currentRow1 - position;

                if (currentRow1 < 17)
                {
                    int difference;
                    difference = 17 - currentRow1;

                    if(difference == 2)
                    {
                        currentRow1 = 17;
                        currentCol1 = currentCol1 - 2;
                    }
                    else
                    {
                        currentCol1 = 15 - ((17 % currentRow1));
                        currentRow1 += 17 % currentRow1;
                    }
                }
            }

            ///see if there are any blank spaces where you landed
             if(grid[currentRow1][currentCol1] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       currentRow1 = l;
                       currentCol1 = k;
                       grid[currentRow1][currentCol1] = p;
                }
                else
                {
                    notBlank = false;
                    grid[currentRow1][currentCol1] = p;
                }
        }

        ///move left (bottom)
        else if(currentRow1 ==17 && currentCol1 >0 && currentCol1 <=15)
        {
                currentCol1 = currentCol1 - position;

                if (currentCol1 < 0)
                {
                    int difference;
                    difference = abs(currentCol1);

                    if(difference == 2)
                    {
                        currentRow1 = 15;
                        currentCol1 = 1;
                    }
                    else
                    {
                        currentCol1 = difference;
                        currentRow1 = 15;
                    }
                }

                if(currentCol1 == 1)
                {
                    ///for additional turns
                    turn++;
                    grid[currentRow1][currentCol1] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;
                    char piece = ' ';

                    ///make sure piece stays in the same place when roll is 0
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePiece2(moveRowSpaces1, p, Roll, r, c);
                }

            ///see if there are any blank spaces where you landed
             if(grid[currentRow1][currentCol1] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       currentRow1 = l;
                       currentCol1 = k;
                       grid[currentRow1][currentCol1] = p;
                }
                else
                {
                    notBlank = false;
                    grid[currentRow1][currentCol1] = p;
                }
        }

        ///move to the right (upper part)
        else if(currentRow1 ==15 && currentCol1 >0 && currentCol1 <=15)
        {
            currentCol1 = currentCol1 + position;
                if(grid[currentRow1][currentCol1] != ' ' && Roll != 0 && turn == 0)
                {
                    ///see if there are any blank spaces where you landed
                       notBlank = true;
                       currentRow1 = l;
                       currentCol1 = k;
                       grid[currentRow1][currentCol1] = p;
                }
                else if(currentRow1 == 15 && currentCol1 == 13 && Counter2 == 0)
                {
                    ///calculate score when piece reaches the end of the grid
                    score1 = 1;
                    grid[currentRow1][currentCol1] = ' ';
                    Counter2++;
                }
                else if(currentCol1 > 15)
                {
                    ///if the piece exceeds the requirements (not on end spot)
                    currentRow1 = 13;
                    currentCol1 = 15;
                    grid[currentRow1][currentCol1] = p;
                }
                else
                {
                    notBlank = false;
                    grid[currentRow1][currentCol1] = p;
                }
        }
}

///return the row of the player n piece
int Board::getRow1()
{
    return currentRow1;
}

///return the column of player n piece
int Board::getCol1()
{
    return currentCol1;
}

///return the score for player
int Board::getScoreA()
{

    if(score == 0)
    {
        return score;
    }
    else if(score > 0)
    {
      if(rotationAinitial == 0 && currentRowA == 17 && currentColA == 19)
      {
          rotationAinitial++;
          return score;
      }
      else if(rA == 0 && RowA == 17 && ColA == 19)
      {
          rA++;
          return score;
      }
      else if(rB == 0 && RowB == 17 && ColB == 19)
      {
          rB++;
          return score;
      }
      else if(rC == 0 && RowC == 17 && ColC == 19)
      {
          rC++;
          return score;
      }
      else if(rD == 0 && RowD == 17 && ColD == 19)
      {
          rD++;
          return score;
      }
      else if(rE == 0 && RowE == 17 && ColE == 19)
      {
          rE++;
          return score;
      }
      else if(rF == 0 && RowF == 17 && ColF == 19)
      {
          rF++;
          return score;
      }
      else
      {
          return 0;
      }
    }
    else if(score1 == 0)
    {
        return score1;
    }
    else if(score1 > 0)
    {
    if(rotation1initial == 0 && currentRow1 == 15 && currentCol1 == 13)
      {
          rotation1initial++;
          return score1;
      }
      else if(r1 == 0 && Row1 == 15 && Col1 == 13)
      {
          r1++;
          return score1;
      }
      else if(r2 == 0 && Row2 == 15 && Col2 == 13)
      {
          r2++;
          return score1;
      }
      else if(r3 == 0 && Row3 == 15 && Col3 == 13)
      {
          r3++;
          return score1;
      }
      else if(r4 == 0 && Row4 == 15 && Col4 == 13)
      {
          r4++;
          return score1;
      }
      else if(r5 == 0 && Row5 == 15 && Col5 == 13)
      {
          r5++;
          return score1;
      }
      else if(r6 == 0 && Row6 == 15 && Col6 == 13)
      {
          r6++;
          return score1;
      }
      else
      {
          return 0;
      }
    }
}

///return the rows an columns of player l and n's pieces
int Board::getRA()
{
    return RowA;
}
int Board::getCA()
{
    return ColA;
}

int Board::getRB()
{
    return RowB;
}

int Board::getCB()
{
    return ColB;
}

int Board::getRC()
{
    return RowC;
}

int Board::getCC()
{
    return ColC;
}

int Board::getRD()
{
    return RowD;
}

int Board::getCD()
{
    return ColD;
}

int Board::getRE()
{
    return RowE;
}

int Board::getCE()
{
    return ColE;
}

int Board::getRF()
{
    return RowF;
}

int Board::getCF()
{
    return ColF;
}

int Board::getR1()
{
    return Row1;
}

int Board::getC1()
{
    return Col1;
}

int Board::getR2()
{
    return Row2;
}

int Board::getC2()
{
    return Col2;
}

int Board::getR3()
{
    return Row3;
}

int Board::getC3()
{
    return Col3;
}

int Board::getR4()
{
    return Row4;
}

int Board::getC4()
{
    return Col4;
}

int Board::getR5()
{
    return Row5;
}

int Board::getC5()
{
    return Col5;
}

int Board::getR6()
{
    return Row6;
}

int Board::getC6()
{
    return Col6;
}

///move player l's piece
void Board::movePieceA(int position, char p, int Roll, int r, int c)
{
    int l = r; ///get the previous row of the same piece
    int k = c; ///get the previous col of the same piece
    int turn = 0;

        /// moving in the right bottom area
        if(RowA>=19 && RowA<=31 && ColA == 17)
        {
                RowA = RowA + position;

                if (RowA == 31)
                {
                    /// additional turn
                    turn++;
                    grid[RowA][ColA] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                    char piece = ' ';
                    ///make sure piece stays in place when roll is 0
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceA(moveRowSpaces1, p, Roll, r, c);
                }

                if (RowA > 31)
                {
                    int difference;
                    difference = RowA - 31;

                    if (difference == 2)
                    {
                        ///additional turn
                        RowA -= 2;
                        ColA -= 2;
                        grid[RowA][ColA] = p;
                    playGame();
                    turn++;
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;
                    char piece = ' ';
                    ///make sure piece stays in same place when roll is 0
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceA(moveRowSpaces1, p, Roll, r, c);
                    }
                    else
                    {
                        RowA = 31 - ((RowA % 31)- 2);
                        ColA -= 2;
                    }
                }

        ///see if there are blank spaces where you landed
        if(grid[RowA][ColA] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowA = l;
                       ColA = k;
                       grid[RowA][ColA] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowA][ColA] = p;
                }
        }


        /// moving in the left bottom area
        else if(RowA >=19 && RowA <=31 && ColA ==15)
        {
            if(RowA + position != 17 && ColA + position!=32)
            {
                RowA = RowA - position;

                if (RowA < 17)
                {
                    int difference;
                    difference = 17 - RowA;

                    if(difference == 2)
                    {
                        RowA = 17;
                        ColA = ColA - 2;
                    }
                    else
                    {
                        ColA = 15 - ((17 % RowA));
                        RowA += 17 % RowA;
                    }
                }

            }

            ///see if there are blank spaces where you landed
          if(grid[RowA][ColA] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowA = l;
                       ColA = k;
                       grid[RowA][ColA] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowA][ColA] = p;
                }
        }

        /// moving in the Middle area Lower row (left bottom)
        else if(RowA ==17 && ColA >0 && ColA <=15)
        {
                ColA = ColA - position;

                if (ColA < 0)
                {
                    int difference;
                    difference = abs(ColA);

                    if(difference == 2)
                    {
                        RowA = 15;
                        ColA = 1;
                    }
                    else
                    {
                        ColA = difference;
                        RowA = 15;
                    }
                }

                if(ColA == 1)
                {
                    ///additional turn
                    grid[RowA][ColA] = p;
                    turn++;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    ///make sure piece stays in same place when roll is 0
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceA(moveRowSpaces1, p, Roll, r, c);
                }

          ///see if there are any blank spaces where you landed
            if(grid[RowA][ColA] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowA = l;
                       ColA = k;
                       grid[RowA][ColA] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowA][ColA] = p;
                }
        }

        /// moving in the MIDDLE area upper row (left)
        else if(RowA ==15 && ColA >0 && ColA <=15)
        {
                ColA = ColA + position;

                if (ColA > 15)
                {
                    int difference;
                    difference = abs(ColA - 15);

                    if(difference == 2)
                    {
                        RowA = 13;
                        ColA = 15;
                    }
                    else
                    {
                        RowA -= difference;
                        ColA = 15;
                    }
                }

            ///see if there are any blank spaces where you landed
            if(grid[RowA][ColA] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowA = l;
                       ColA = k;
                       grid[RowA][ColA] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowA][ColA] = p;
                }
        }

        /// moving in the MIDDLE TOP area (left)
        else if(RowA >=0  && RowA <=13 && ColA ==15)
        {
                RowA = RowA - position;

                if (RowA < 1)
                {
                    int difference;
                    difference = abs(RowA - 1) ;

                    if(difference == 2)
                    {
                        RowA = 1;
                        ColA = 17;
                    }
                    else
                    {
                        RowA = difference-1;
                        ColA = 17;
                    }
                }

                if(RowA == 1)
                {
                    ///additional turn
                   grid[RowA][ColA] = p;
                   turn++;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                    char piece = ' ';
                    ///piece stays in same place when roll is 0
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceA(moveRowSpaces1, p, Roll, r, c);
                }

            ///see if there are any blanks where you landed
          if(grid[RowA][ColA] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowA = l;
                       ColA = k;
                       grid[RowA][ColA] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowA][ColA] = p;
                }
        }

        /// moving in the MIDDLE TOP area (right)
        else if(RowA >=1 && RowA <= 15 && ColA == 17)
        {
            RowA = RowA + position;

            if(RowA > 15)
            {
                int difference;
                difference = abs(RowA - 15);
                 if (difference == 2)
                    {
                        RowA = 15;
                        ColA = 19;
                    }
                    else
                    {
                        RowA = 15;
                        ColA += difference;
                    }
            }

            ///see if there are any blanks where you landed
            if(grid[RowA][ColA] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowA = l;
                       ColA = k;
                       grid[RowA][ColA] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowA][ColA] = p;
                }
        }


        ///moving upper middle area (right side of the board)
        else if(RowA == 15 && ColA > 17 && ColA <=31)
        {
                ColA = ColA + position;

                if (ColA > 31)
                {
                    int difference;
                    difference = abs(ColA - 31) ;

                    if(difference == 2)
                    {
                        RowA = 17;
                        ColA = 31;
                    }
                    else
                    {
                        RowA = 17;
                        ColA = 31 - (difference-2);
                    }
                }

                if(ColA == 31)
                {
                    ///additional turn
                    grid[RowA][ColA] = p;
                    turn++;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                    char piece = ' ';
                    ///piece stays in same place when roll is 0
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceA(moveRowSpaces1, p, Roll, r, c);
                }

            ///see if there are any blank spaces where you landed
            if(grid[RowA][ColA] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowA = l;
                       ColA = k;
                       grid[RowA][ColA] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowA][ColA] = p;
                }
        }


        ///moving in middle area right (bottom)
        else if(RowA == 17 && ColA > 16 && ColA <= 31)
        {
            ColA = ColA - position;
                if(grid[RowA][ColA] != ' ' && Roll != 0)
                {
                    ///see if blank spaces where you landed
                       notBlank = true;
                       RowA = l;
                       ColA = k;
                       grid[RowA][ColA] = p;
                }
                else if(ColA == 19 && RowA == 17 && counterA == 0 && p == 'A')
                {
                    ///calculate the score when piece is at end spot
                    grid[RowA][ColA] = ' ';
                    score = 1;
                    counterA++;
                }
                else if(ColA < 19)
                {
                    ///when piece exceeds end spot
                    RowA = 19;
                    ColA = 17;
                    grid[RowA][ColA] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowA][ColA] = p;
                }
        }
}

///move player l piece
///the following code bellow is the same repetition of A until movePieceF
void Board::movePieceB(int position, char p, int Roll, int r, int c)
{
        int l = r; ///get previous row of same piece
        int k = c;///get previous col of same piece
        int turn = 0;

        /// moving in the right bottom area
        if(RowB>=19 && RowB<=31 && ColB == 17)
        {
                RowB = RowB + position;

                if (RowB == 31)
                {
                    /// additional turn
                    turn++;
                    grid[RowB][ColB] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceB(moveRowSpaces1, p, Roll, r, c);
                }

                if (RowB > 31)
                {
                    int difference;
                    difference = RowB - 31;

                    if (difference == 2)
                    {
                        RowB -= 2;
                        ColB -= 2;
                        grid[RowB][ColB] = p;
                    playGame();
                    turn++;
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceB(moveRowSpaces1, p, Roll, r, c);
                    }
                    else
                    {
                        RowB = 31 - ((RowB % 31)- 2);
                        ColB -= 2;
                    }
                }

          if(grid[RowB][ColB] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowB = l;
                       ColB = k;
                       grid[RowB][ColB] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowB][ColB] = p;
                }
        }


        /// moving in the left bottom area
        else if(RowB >=19 && RowB <=31 && ColB ==15)
        {
            if(RowB + position != 17 && ColB + position!=32)
            {
                RowB = RowB - position;

                if (RowB < 17)
                {
                    int difference;
                    difference = 17 - RowB;

                    if(difference == 2)
                    {
                        RowB = 17;
                        ColB = ColB - 2;
                    }
                    else
                    {
                        ColB = 15 - ((17 % RowB));
                        RowB += 17 % RowB;
                    }
                }
            }

            if(grid[RowB][ColB] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowB = l;
                       ColB = k;
                       grid[RowB][ColB] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowB][ColB] = p;
                }
        }

        /// moving in the Middle area Lower row (left bottom)
        else if(RowB ==17 && ColB >0 && ColB <=15)
        {
                ColB = ColB - position;

                if (ColB < 0)
                {
                    int difference;
                    difference = abs(ColB);

                    if(difference == 2)
                    {
                        RowB = 15;
                        ColB = 1;
                    }
                    else
                    {
                        ColB = difference;
                        RowB = 15;
                    }
                }

                if(ColB == 1)
                {
                    grid[RowB][ColB] = p;
                    turn++;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceB(moveRowSpaces1, p, Roll, r, c);
                }

            if(grid[RowB][ColB] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowB = l;
                       ColB = k;
                       grid[RowB][ColB] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowB][ColB] = p;
                }
        }

        /// moving in the MIDDLE area upper row (left)
        else if(RowB ==15 && ColB >0 && ColB <=15)
        {
                ColB = ColB + position;

                if (ColB > 15)
                {
                    int difference;
                    difference = abs(ColB - 15);

                    if(difference == 2)
                    {
                        RowB = 13;
                        ColB = 15;
                    }
                    else
                    {
                        RowB -= difference;
                        ColB = 15;
                    }
                }

            if(grid[RowA][ColA] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowB = l;
                       ColB = k;
                       grid[RowB][ColB] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowB][ColB] = p;
                }
        }

        /// moving in the MIDDLE TOP area (left)
        else if(RowB >=0  && RowB <=13 && ColB ==15)
        {
                RowB = RowB - position;

                if (RowB < 1)
                {
                    int difference;
                    difference = abs(RowB - 1) ;

                    if(difference == 2)
                    {
                        RowB = 1;
                        ColB = 17;
                    }
                    else
                    {
                        RowB = difference-1;
                        ColB = 17;
                    }
                }

                if(RowB == 1)
                {
                   grid[RowB][ColB] = p;
                   turn++;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }


                    int moveRowSpaces1 = roll*2;
                    movePieceB(moveRowSpaces1, p, Roll, r, c);
                }


          if(grid[RowB][ColB] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowB = l;
                       ColB = k;
                       grid[RowB][ColB] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowB][ColB] = p;
                }
        }

        /// moving in the MIDDLE TOP area (right)
        else if(RowB >=1 && RowB <= 15 && ColB == 17)
        {
            RowB = RowB + position;

            if(RowB > 15)
            {
                int difference;
                difference = abs(RowB - 15);
                 if (difference == 2)
                    {
                        RowB = 15;
                        ColB = 19;
                    }
                    else
                    {
                        RowB = 15;
                        ColB += difference;
                    }
            }

                if(grid[RowB][ColB] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowB = l;
                       ColB = k;
                       grid[RowB][ColB] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowB][ColB] = p;
                }
        }


        ///moving upper middle area (right side of the board)
        else if(RowB == 15 && ColB > 17 && ColB <=31)
        {
                ColB = ColB + position;

                if (ColB > 31)
                {
                    int difference;
                    difference = abs(ColB - 31) ;

                    if(difference == 2)
                    {
                        RowB = 17;
                        ColB = 31;
                    }
                    else
                    {
                        RowB = 17;
                        ColB = 31 - (difference-2);
                    }
                }

                if(ColB == 31)
                {
                    grid[RowB][ColB] = p;
                    turn++;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }


                    int moveRowSpaces1 = roll*2;
                    movePieceB(moveRowSpaces1, p, Roll, r, c);
                }


            if(grid[RowB][ColB] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowB = l;
                       ColB = k;
                       grid[RowB][ColB] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowB][ColB] = p;
                }
        }

        ///moving in middle area right (bottom)
        else if(RowB == 17 && ColB > 16 && ColB <= 31)
        {
            ColB = ColB - position;
                if(grid[RowB][ColB] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowB = l;
                       ColB = k;
                       grid[RowB][ColB] = p;
                }
                 else if(ColB == 19 && RowB == 17 && counterB == 0 && p == 'B')
                {
                    grid[RowB][ColB] = ' ';
                    score = 1;
                    counterB++;
                }
                else if(ColB < 19)
                {
                    RowB = 19;
                    ColB = 17;
                    grid[RowB][ColB] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowB][ColB] = p;
                }
        }
}

void Board::movePieceC(int position, char p, int Roll, int r, int c)
{
    int l = r;
    int k = c;
    int turn = 0;

        /// moving in the right bottom area
        if(RowC>=19 && RowC<=31 && ColC == 17)
        {
                RowC = RowC + position;

                if (RowC == 31)
                {
                    /// additional turn
                    turn++;
                    grid[RowC][ColC] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceC(moveRowSpaces1, p, Roll, r, c);
                }

                if (RowC > 31)
                {
                    int difference;
                    difference = RowC - 31;

                    if (difference == 2)
                    {
                        RowC -= 2;
                        ColC -= 2;
                        grid[RowC][ColC] = p;
                        turn++;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceC(moveRowSpaces1, p, Roll, r, c);
                    }
                    else
                    {
                        RowC = 31 - ((RowC % 31)- 2);
                        ColC -= 2;
                    }
                }

            if(grid[RowC][ColC] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowC = l;
                       ColC = k;
                       grid[RowC][ColC] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowC][ColC] = p;
                }
        }


        /// moving in the left bottom area
        else if(RowC >=19 && RowC <=31 && ColC ==15)
        {
            if(RowC + position != 17 && ColC + position!=32)
            {
                RowC = RowC - position;

                if (RowC < 17)
                {
                    int difference;
                    difference = 17 - RowC;

                    if(difference == 2)
                    {
                        RowC = 17;
                        ColC = ColC - 2;
                    }
                    else
                    {
                        ColC = 15 - ((17 % RowC));
                        RowC += 17 % RowC;
                    }
                }
            }

            if(grid[RowC][ColC] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowC = l;
                       ColC = k;
                       grid[RowC][ColC] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowC][ColC] = p;
                }
        }

        /// moving in the Middle area Lower row (left bottom)
        else if(RowC ==17 && ColC >0 && ColC <=15)
        {
                ColC = ColC - position;

                if (ColC < 0)
                {
                    int difference;
                    difference = abs(ColC);

                    if(difference == 2)
                    {
                        RowC = 15;
                        ColC = 1;
                    }
                    else
                    {
                        ColC = difference;
                        RowC = 15;
                    }
                }

                if(ColC == 1)
                {
                    turn++;
                    grid[RowC][ColC] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceC(moveRowSpaces1, p, Roll, r, c);
                }

            if(grid[RowC][ColC] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowC = l;
                       ColC = k;
                       grid[RowC][ColC] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowC][ColC] = p;
                }
        }

        /// moving in the MIDDLE area upper row (left)
        else if(RowC ==15 && ColC >0 && ColC <=15)
        {
                ColC = ColC + position;

                if (ColC > 15)
                {
                    int difference;
                    difference = abs(ColC - 15);

                    if(difference == 2)
                    {
                        RowC = 13;
                        ColC = 15;
                    }
                    else
                    {
                        RowC -= difference;
                        ColC = 15;
                    }
                }

             if(grid[RowC][ColC] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowC = l;
                       ColC = k;
                       grid[RowC][ColC] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowC][ColC] = p;
                }
        }

        /// moving in the MIDDLE TOP area (left)
        else if(RowC >=0  && RowC <=13 && ColC ==15)
        {
                RowC = RowC - position;

                if (RowC < 1)
                {
                    int difference;
                    difference = abs(RowC - 1) ;

                    if(difference == 2)
                    {
                        RowC = 1;
                        ColC = 17;
                    }
                    else
                    {
                        RowC = difference-1;
                        ColC = 17;
                    }
                }

                if(RowC == 1)
                {
                    turn++;
                   grid[RowC][ColC] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }


                    int moveRowSpaces1 = roll*2;
                    movePieceC(moveRowSpaces1, p, Roll, r, c);
                }


            if(grid[RowC][ColC] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowC = l;
                       ColC = k;
                       grid[RowC][ColC] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowC][ColC] = p;
                }
        }

        /// moving in the MIDDLE TOP area (right)
        else if(RowC >=1 && RowC <= 15 && ColC == 17)
        {
            RowC = RowC + position;

            if(RowC > 15)
            {
                int difference;
                difference = abs(RowC - 15);
                 if (difference == 2)
                    {
                        RowC = 15;
                        ColC = 19;
                    }
                    else
                    {
                        RowC = 15;
                        ColC += difference;
                    }
            }

           if(grid[RowC][ColC] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowC = l;
                       ColC = k;
                       grid[RowC][ColC] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowC][ColC] = p;
                }
        }


        ///moving upper middle area (right side of the board)
        else if(RowC == 15 && ColC > 17 && ColC <=31)
        {
                ColC = ColC + position;

                if (ColC > 31)
                {
                    int difference;
                    difference = abs(ColC - 31) ;

                    if(difference == 2)
                    {
                        RowC = 17;
                        ColC = 31;
                    }
                    else
                    {
                        RowC = 17;
                        ColC = 31 - (difference-2);
                    }
                }

                if(ColC == 31)
                {
                    turn++;
                    grid[RowC][ColC] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }


                    int moveRowSpaces1 = roll*2;
                    movePieceC(moveRowSpaces1, p, Roll, r, c);
                }


             if(grid[RowC][ColC] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowC = l;
                       ColC = k;
                       grid[RowC][ColC] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowC][ColC] = p;
                }
        }

        ///moving in middle area right (bottom)
        else if(RowC == 17 && ColC > 16 && ColC <= 31)
        {
            ColC = ColC - position;
                if(grid[RowC][ColC] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowC = l;
                       ColC = k;
                       grid[RowC][ColC] = p;
                }
                 else if(ColC == 19 && RowC == 17 && counterC == 0 && p =='C')
                {
                    grid[RowC][ColC] = ' ';
                    score = 1;
                    counterC++;
                }
                else if(ColC < 19)
                {
                    RowC = 19;
                    ColC = 17;
                    grid[RowC][ColC] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowC][ColC] = p;
                }
        }
}

void Board::movePieceD(int position, char p, int Roll, int r, int c)
{
        int l = r;
        int k = c;
        int turn = 0;

        /// moving in the right bottom area
        if(RowD>=19 && RowD<=31 && ColD == 17)
        {
                RowD = RowD + position;

                if (RowD == 31)
                {
                    /// additional turn
                    turn++;
                    grid[RowD][ColD] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                    ///move the do-while to referee later
                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceD(moveRowSpaces1, p, Roll, r, c);
                }

                if (RowD > 31)
                {
                    int difference;
                    difference = RowD - 31;

                    if (difference == 2)
                    {
                        RowD -= 2;
                        ColD -= 2;
                        grid[RowD][ColD] = p;
                    playGame();
                    turn++;
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceD(moveRowSpaces1, p, Roll, r, c);
                    }
                    else
                    {
                        RowD = 31 - ((RowD % 31)- 2);
                        ColD -= 2;
                    }
                }

           if(grid[RowD][ColD] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowD = l;
                       ColD = k;
                       grid[RowD][ColD] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowD][ColD] = p;
                }
        }


        /// moving in the left bottom area
        else if(RowD >=19 && RowD <=31 && ColD ==15)
        {
            if(RowD + position != 17 && ColD + position!=32)
            {
                RowD = RowD - position;

                if (RowD < 17)
                {
                    int difference;
                    difference = 17 - RowD;

                    if(difference == 2)
                    {
                        RowD = 17;
                        ColD = ColD - 2;
                    }
                    else
                    {
                        ColD = 15 - ((17 % RowD));
                        RowD += 17 % RowD;
                    }
                }
            }

             if(grid[RowD][ColD] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowD = l;
                       ColD = k;
                       grid[RowD][ColD] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowD][ColD] = p;
                }
        }

        /// moving in the Middle area Lower row (left bottom)
        else if(RowD ==17 && ColD >0 && ColD <=15)
        {
                ColD = ColD - position;

                if (ColD < 0)
                {
                    int difference;
                    difference = abs(ColD);

                    if(difference == 2)
                    {
                        RowD = 15;
                        ColD = 1;
                    }
                    else
                    {
                        ColD = difference;
                        RowD = 15;
                    }
                }

                if(ColD == 1)
                {
                    turn++;
                    grid[RowD][ColD] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceD(moveRowSpaces1, p, Roll, r, c);
                }

              if(grid[RowD][ColD] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowD = l;
                       ColD = k;
                       grid[RowD][ColD] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowD][ColD] = p;
                }
        }

        /// moving in the MIDDLE area upper row (left)
        else if(RowD ==15 && ColD >0 && ColD <=15)
        {
                ColD = ColD + position;

                if (ColD > 15)
                {
                    int difference;
                    difference = abs(ColD - 15);

                    if(difference == 2)
                    {
                        RowD = 13;
                        ColD = 15;
                    }
                    else
                    {
                        RowD -= difference;
                        ColD = 15;
                    }
                }

              if(grid[RowD][ColD] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowD = l;
                       ColD = k;
                       grid[RowD][ColD] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowD][ColD] = p;
                }
        }

        /// moving in the MIDDLE TOP area (left)
        else if(RowD >=0  && RowD <=13 && ColD ==15)
        {
                RowD = RowD - position;

                if (RowD < 1)
                {
                    int difference;
                    difference = abs(RowD - 1) ;

                    if(difference == 2)
                    {
                        RowD = 1;
                        ColD = 17;
                    }
                    else
                    {
                        RowD = difference-1;
                        ColD = 17;
                    }
                }

                if(RowD == 1)
                {
                    turn++;
                   grid[RowD][ColD] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceD(moveRowSpaces1, p, Roll, r, c);
                }

            if(grid[RowD][ColD] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowD = l;
                       ColD = k;
                       grid[RowD][ColD] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowD][ColD] = p;
                }
        }

        /// moving in the MIDDLE TOP area (right)
        else if(RowD >=1 && RowD <= 15 && ColD == 17)
        {
            RowD = RowD + position;

            if(RowD > 15)
            {
                int difference;
                difference = abs(RowD - 15);
                 if (difference == 2)
                    {
                        RowD = 15;
                        ColD = 19;
                    }
                    else
                    {
                        RowD = 15;
                        ColD += difference;
                    }
            }

              if(grid[RowD][ColD] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowD = l;
                       ColD = k;
                       grid[RowD][ColD] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowD][ColD] = p;
                }
        }


        ///moving upper middle area (right side of the board)
        else if(RowD == 15 && ColD > 17 && ColD <=31)
        {
                ColD = ColD + position;

                if (ColD > 31)
                {
                    int difference;
                    difference = abs(ColD - 31) ;

                    if(difference == 2)
                    {
                        RowD = 17;
                        ColD = 31;
                    }
                    else
                    {
                        RowD = 17;
                        ColD = 31 - (difference-2);
                    }
                }

                if(ColD == 31)
                {
                    turn++;
                    grid[RowD][ColD] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!= 0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceD(moveRowSpaces1, p, Roll, r, c);
                }

            //grid[RowD][ColD] = p;
              if(grid[RowD][ColD] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowD = l;
                       ColD = k;
                       grid[RowD][ColD] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowD][ColD] = p;
                }
        }

        ///moving in middle area right (bottom)
        else if(RowD == 17 && ColD > 16 && ColD <= 31)
        {
            ColD = ColD - position;
                 if(grid[RowD][ColD] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowD = l;
                       ColD = k;
                       grid[RowD][ColD] = p;
                }
                 else if(ColD == 19 && RowD == 17 && counterD == 0 && p == 'D')
                {
                    grid[RowD][ColD] = ' ';
                    score = 1;
                    counterD++;
                }
                else if(ColD < 19)
                {
                    RowD = 19;
                    ColD = 17;
                    grid[RowD][ColD] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowD][ColD] = p;
                }
        }
}

void Board::movePieceE(int position, char p, int Roll, int r, int c)
{
        int l = r;
        int k = c;
        int turn = 0;

        /// moving in the right bottom area
        if(RowE>=19 && RowE<=31 && ColE == 17)
        {
                RowE = RowE + position;

                if (RowE == 31)
                {
                    /// additional turn
                    turn++;
                    grid[RowE][ColE] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceE(moveRowSpaces1, p, Roll, r, c);
                }

                if (RowE > 31)
                {
                    int difference;
                    difference = RowE - 31;

                    if (difference == 2)
                    {
                        RowE -= 2;
                        ColE -= 2;
                        grid[RowE][ColE] = p;
                    turn++;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceE(moveRowSpaces1, p, Roll, r, c);
                    }
                    else
                    {
                        RowE = 31 - ((RowE % 31)- 2);
                        ColE -= 2;
                    }
                }
            //grid[RowE][ColE] = p;
           if(grid[RowE][ColE] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowE = l;
                       ColE = k;
                       grid[RowE][ColE] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowE][ColE] = p;
                }
        }


        /// moving in the left bottom area
        else if(RowE >=19 && RowE <=31 && ColE ==15)
        {
            if(RowE + position != 17 && ColE + position!=32)
            {
                RowE = RowE - position;

                if (RowE < 17)
                {
                    int difference;
                    difference = 17 - RowE;

                    if(difference == 2)
                    {
                        RowE = 17;
                        ColE = ColE - 2;
                    }
                    else
                    {
                        ColE = 15 - ((17 % RowE));
                        RowE += 17 % RowE;
                    }
                }
            }
            //grid[RowE][ColE] = p;
            if(grid[RowE][ColE] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowE = l;
                       ColE = k;
                       grid[RowE][ColE] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowE][ColE] = p;
                }
        }

        /// moving in the Middle area Lower row (left bottom)
        else if(RowE ==17 && ColE >0 && ColE <=15)
        {
                ColE = ColE - position;

                if (ColE < 0)
                {
                    int difference;
                    difference = abs(ColE);

                    if(difference == 2)
                    {
                        RowE = 15;
                        ColE = 1;
                    }
                    else
                    {
                        ColE = difference;
                        RowE = 15;
                    }
                }

                if(ColE == 1)
                {
                    turn++;
                    grid[RowE][ColE] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceE(moveRowSpaces1, p, Roll, r, c);
                }
        if(grid[RowE][ColE] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowE = l;
                       ColE = k;
                       grid[RowE][ColE] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowE][ColE] = p;
                }
        }

        /// moving in the MIDDLE area upper row (left)
        else if(RowE ==15 && ColE >0 && ColE <=15)
        {
                ColE = ColE + position;

                if (ColE > 15)
                {
                    int difference;
                    difference = abs(ColE - 15);

                    if(difference == 2)
                    {
                        RowE = 13;
                        ColE = 15;
                    }
                    else
                    {
                        RowE -= difference;
                        ColE = 15;
                    }
                }
            //grid[RowE][ColE] = p;
            if(grid[RowE][ColE] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowE = l;
                       ColE = k;
                       grid[RowE][ColE] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowE][ColE] = p;
                }
        }

        /// moving in the MIDDLE TOP area (left)
        else if(RowE >=0  && RowE <=13 && ColE ==15)
        {
                RowE = RowE - position;

                if (RowE < 1)
                {
                    int difference;
                    difference = abs(RowE - 1) ;

                    if(difference == 2)
                    {
                        RowE = 1;
                        ColE = 17;
                    }
                    else
                    {
                        RowE = difference-1;
                        ColE = 17;
                    }
                }

                if(RowE == 1)
                {
                    turn++;
                   grid[RowE][ColE] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }


                    int moveRowSpaces1 = roll*2;
                    movePieceE(moveRowSpaces1, p, Roll, r, c);
                }

            //grid[RowE][ColE] = p;
            if(grid[RowE][ColE] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowE = l;
                       ColE = k;
                       grid[RowE][ColE] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowE][ColE] = p;
                }
        }

        /// moving in the MIDDLE TOP area (right)
        else if(RowE >=1 && RowE <= 15 && ColE == 17)
        {
            RowE = RowE + position;

            if(RowE > 15)
            {
                int difference;
                difference = abs(RowE - 15);
                 if (difference == 2)
                    {
                        RowE = 15;
                        ColE = 19;
                    }
                    else
                    {
                        RowE = 15;
                        ColE += difference;
                    }
            }
            //grid[RowE][ColE] = p;
            if(grid[RowE][ColE] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowE = l;
                       ColE = k;
                       grid[RowE][ColE] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowE][ColE] = p;
                }
        }


        ///moving upper middle area (right side of the board)
        else if(RowE == 15 && ColE > 17 && ColE <=31)
        {
                ColE = ColE + position;

                if (ColE > 31)
                {
                    int difference;
                    difference = abs(ColE - 31) ;

                    if(difference == 2)
                    {
                        RowE = 17;
                        ColE = 31;
                    }
                    else
                    {
                        RowE = 17;
                        ColE = 31 - (difference-2);
                    }
                }

                if(ColE == 31)
                {
                    turn++;
                    grid[RowE][ColE] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceE(moveRowSpaces1, p, Roll, r, c);
                }

            //grid[RowE][ColE] = p;
            if(grid[RowE][ColE] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowE = l;
                       ColE = k;
                       grid[RowE][ColE] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowE][ColE] = p;
                }
        }

        ///moving in middle area right (bottom)
        else if(RowE == 17 && ColE > 16 && ColE <= 31)
        {
            ColE = ColE - position;
               if(grid[RowE][ColE] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowE = l;
                       ColE = k;
                       grid[RowE][ColE] = p;
                }
                 else if(ColE == 19 && RowE == 17 && counterE == 0 && p == 'E')
                {
                    grid[RowE][ColE] = ' ';
                    score = 1;
                    counterE++;
                }
                else if(ColE < 19)
                {
                    RowE = 19;
                    ColE = 17;
                    grid[RowE][ColE] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowE][ColE] = p;
                }
        }
}

void Board::movePieceF(int position, char p, int Roll, int r, int c)
{
    int l = r;
    int k = c;
    int turn = 0;

        /// moving in the right bottom area
        if(RowF>=19 && RowF<=31 && ColF == 17)
        {
                RowF = RowF + position;

                if (RowF == 31)
                {
                    /// additional turn
                    turn++;
                    grid[RowF][ColF] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceF(moveRowSpaces1, p, Roll, r, c);
                }

                if (RowF > 31)
                {
                    int difference;
                    difference = RowF - 31;

                    if (difference == 2)
                    {
                        RowF -= 2;
                        ColF -= 2;
                        grid[RowF][ColF] = p;
                    playGame();
                    turn++;
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceF(moveRowSpaces1, p, Roll, r, c);
                    }
                    else
                    {
                        RowF = 31 - ((RowF % 31)- 2);
                        ColF -= 2;
                    }
                }
            //grid[RowF][ColF] = p;
         if(grid[RowF][ColF] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowF = l;
                       ColF = k;
                       grid[RowF][ColF] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowF][ColF] = p;
                }
        }


        /// moving in the left bottom area
        else if(RowF >=19 && RowF <=31 && ColF ==15)
        {
            if(RowF + position != 17 && ColF + position!=32)
            {
                RowF = RowF - position;

                if (RowF < 17)
                {
                    int difference;
                    difference = 17 - RowF;

                    if(difference == 2)
                    {
                        RowF = 17;
                        ColF = ColF - 2;
                    }
                    else
                    {
                        ColF = 15 - ((17 % RowF));
                        RowF += 17 % RowF;
                    }
                }
            }
            //grid[RowF][ColF] = p;
         if(grid[RowF][ColF] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowF = l;
                       ColF = k;
                       grid[RowF][ColF] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowF][ColF] = p;
                }
        }

        /// moving in the Middle area Lower row (left bottom)
        else if(RowF ==17 && ColF >0 && ColF <=15)
        {
                ColF = ColF - position;

                if (ColF < 0)
                {
                    int difference;
                    difference = abs(ColF);

                    if(difference == 2)
                    {
                        RowF = 15;
                        ColF = 1;
                    }
                    else
                    {
                        ColF = difference;
                        RowF = 15;
                    }
                }

                if(ColF == 1)
                {
                    turn++;
                    grid[RowF][ColF] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceF(moveRowSpaces1, p, Roll, r, c);
                }
            //grid[RowF][ColF] = p;
        if(grid[RowF][ColF] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowF = l;
                       ColF = k;
                       grid[RowF][ColF] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowF][ColF] = p;
                }
        }

        /// moving in the MIDDLE area upper row (left)
        else if(RowF ==15 && ColF >0 && ColF <=15)
        {
                ColF = ColF + position;

                if (ColF > 15)
                {
                    int difference;
                    difference = abs(ColF - 15);

                    if(difference == 2)
                    {
                        RowF = 13;
                        ColF = 15;
                    }
                    else
                    {
                        RowF -= difference;
                        ColF = 15;
                    }
                }
            if(grid[RowF][ColF] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowF = l;
                       ColF = k;
                       grid[RowF][ColF] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowF][ColF] = p;
                }
        }

        /// moving in the MIDDLE TOP area (left)
        else if(RowF >=0  && RowF <=13 && ColF ==15)
        {
                RowF = RowF - position;

                if (RowF < 1)
                {
                    int difference;
                    difference = abs(RowF - 1) ;

                    if(difference == 2)
                    {
                        RowF = 1;
                        ColF = 17;
                    }
                    else
                    {
                        RowF = difference-1;
                        ColF = 17;
                    }
                }

                if(RowF == 1)
                {
                    turn++;
                   grid[RowF][ColF] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                  ///move the do-while to referee later
                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }


                    int moveRowSpaces1 = roll*2;
                    movePieceF(moveRowSpaces1, p, Roll, r, c);
                }

            //grid[RowF][ColF] = p;
           if(grid[RowF][ColF] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowF = l;
                       ColF = k;
                       grid[RowF][ColF] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowF][ColF] = p;
                }
        }

        /// moving in the MIDDLE TOP area (right)
        else if(RowF >=1 && RowF <= 15 && ColF == 17)
        {
            RowF = RowF + position;

            if(RowF > 15)
            {
                int difference;
                difference = abs(RowF - 15);
                 if (difference == 2)
                    {
                        RowF = 15;
                        ColF = 19;
                    }
                    else
                    {
                        RowF = 15;
                        ColF += difference;
                    }
            }
            if(grid[RowF][ColF] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       RowF = l;
                       ColF = k;
                       grid[RowF][ColF] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowF][ColF] = p;
                }
        }


        ///moving upper middle area (right side of the board)
        else if(RowF == 15 && ColF > 17 && ColF <=31)
        {
                ColF = ColF + position;

                if (ColF > 31)
                {
                    int difference;
                    difference = abs(ColF - 31) ;

                    if(difference == 2)
                    {
                        RowF = 17;
                        ColF = 31;
                    }
                    else
                    {
                        RowF = 17;
                        ColF = 31 - (difference-2);
                    }
                }

                if(ColF == 31)
                {
                    turn++;
                    grid[RowF][ColF] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    movePieceF(moveRowSpaces1, p, Roll, r, c);
                }

            //grid[RowF][ColF] = p;
           if(grid[RowF][ColF] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowF = l;
                       ColF = k;
                       grid[RowF][ColF] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowF][ColF] = p;
                }
        }

        ///moving in middle area right (bottom)
        else if(RowF == 17 && ColF > 16 && ColF <= 31)
        {
            ColF = ColF - position;
              if(grid[RowF][ColF] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       RowF = l;
                       ColF = k;
                       grid[RowF][ColF] = p;
                }
                else if(ColF == 19 && RowF == 17 && counterF == 0 && p == 'F')
                {
                    grid[RowF][ColF] = ' ';
                    score = 1;
                    counterF++;
                }
                else if(ColF < 19)
                {
                    RowF = 19;
                    ColF = 17;
                    grid[RowF][ColF] = p;
                }
                else
                {
                    notBlank = false;
                    grid[RowF][ColF] = p;
                }
        }
}

///move1-move6 is the same code repeated as movePiece2
void Board::move1(int position, char p, int Roll, int r, int c)
{
    int l = r;
    int k = c;
    int turn = 0;

     /// moving to the top (left)
      if(Row1 >=0  && Row1 <=13 && Col1 ==15)
        {
                Row1 = Row1 - position;

                if (Row1 < 1)
                {
                    int difference;
                    difference = abs(Row1 - 1);

                    if(difference == 2)
                    {
                        Row1 = 1;
                        Col1 = 17;
                    }
                    else
                    {
                        Row1 = difference-1;
                        Col1 = 17;
                    }
                }

                if(Row1 == 1)
                {
                    turn++;
                   grid[Row1][Col1] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces2 = roll*2;
                    move1(moveRowSpaces2, p, Roll, r, c);
                }

           if(grid[Row1][Col1] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row1 = l;
                       Col1 = k;
                       grid[Row1][Col1] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row1][Col1] = p;
                }
        }

        ///moving to the bottom (right)
        else if(Row1 >=1 && Row1 <= 15 && Col1 == 17)
        {
            Row1 = Row1 + position;

            if(Row1 > 15)
            {
                int difference;
                difference = abs(Row1 - 15);
                 if (difference == 2)
                    {
                        Row1 = 15;
                        Col1 = 19;
                    }
                    else
                    {
                        Row1 = 15;
                        Col1 += difference;
                    }
            }
           if(grid[Row1][Col1] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row1 = l;
                       Col1 = k;
                       grid[Row1][Col1] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row1][Col1] = p;
                }
        }

        ///three
        else if(Row1 == 15 && Col1 > 17 && Col1 <=31)
        {
                Col1 = Col1 + position;

                if (Col1 > 31)
                {
                    int difference;
                    difference = abs(Col1 - 31) ;

                    if(difference == 2)
                    {
                        Row1 = 17;
                        Col1 = 31;
                    }
                    else
                    {
                        Row1 = 17;
                        Col1 = 31 - (difference-2);
                    }
                }

                if(Col1 == 31)
                {
                    turn++;
                    grid[Row1][Col1] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    move1(moveRowSpaces1, p, Roll, r, c);
                }

           if(grid[Row1][Col1] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row1 = l;
                       Col1 = k;
                       grid[Row1][Col1] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row1][Col1] = p;
                }
        }

        ///four
        else if(Row1 == 17 && Col1 > 16 && Col1 <= 31)
        {
            Col1 = Col1 - position;

               if (Col1 < 17)
                {
                    int difference;
                    difference = abs(17-Col1);

                    if(difference == 2)
                    {
                        Row1 = 19;
                        Col1 = 17;
                    }
                    else
                    {
                        Row1 = 17 + (abs(Col1 -17));
                        Col1 = 17;
                    }
                }

            if(grid[Row1][Col1] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row1 = l;
                       Col1 = k;
                       grid[Row1][Col1] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row1][Col1] = p;
                }
        }

        ///five
        if(Row1>=19 && Row1<=31 && Col1 == 17)
        {
                Row1 = Row1 + position;

                if (Row1 == 31)
                {
                    /// additional turn
                    turn++;
                    grid[Row1][Col1] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces2 = roll*2;
                    move1(moveRowSpaces2, p, Roll, r, c);
                }

                if (Row1 > 31)
                {
                    int difference;
                    difference = Row1 - 31;

                    if (difference == 2)
                    {
                        Row1 = 31;
                        Col1 = 15;
                        grid[Row1][Col1] = p;
                    playGame();
                    turn++;
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    move1(moveRowSpaces1, p, Roll, r, c);
                    }
                    else
                    {
                        Row1 = 31 - ((Row1 % 31)- 2);
                        Col1 -= 2;
                    }
                }
            //grid[Row1][Col1] = p;
            if(grid[Row1][Col1] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row1 = l;
                       Col1 = k;
                       grid[Row1][Col1] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row1][Col1] = p;
                }
        }


        ///six
        else if(Row1 >=19 && Row1 <=31 && Col1 ==15)
        {
            if(Row1 + position != 17 && Col1 + position!=32)
            {
                Row1 = Row1 - position;

                if (Row1 < 17)
                {
                    int difference;
                    difference = 17 - Row1;

                    if(difference == 2)
                    {
                        Row1 = 17;
                        Col1 = Col1 - 2;
                    }
                    else
                    {
                        Col1 = 15 - ((17 % Row1));
                        Row1 += 17 % Row1;
                    }
                }
            }
           if(grid[Row1][Col1] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row1 = l;
                       Col1 = k;
                       grid[Row1][Col1] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row1][Col1] = p;
                }
        }

        ///seven
        else if(Row1 ==17 && Col1 >0 && Col1 <=15)
        {
                Col1 = Col1 - position;

                if (Col1 < 0)
                {
                    int difference;
                    difference = abs(Col1);

                    if(difference == 2)
                    {
                        Row1 = 15;
                        Col1 = 1;
                    }
                    else
                    {
                        Col1 = difference;
                        Row1 = 15;
                    }
                }

                if(Col1 == 1)
                {
                    turn++;
                    grid[Row1][Col1] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    move2(moveRowSpaces1, p, Roll, r, c);
                }
            if(grid[Row1][Col1] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row1 = l;
                       Col1 = k;
                       grid[Row1][Col1] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row1][Col1] = p;
                }
        }

        ///eight
        else if(Row1 ==15 && Col1 >0 && Col1 <=15)
        {
            Col1 = Col1 + position;
              if(grid[Row1][Col1] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row1 = l;
                       Col1 = k;
                       grid[Row1][Col1] = p;
                }
                else if(Row1 == 15 && Col1 == 13 && counter1 == 0 && p == '1')
                {
                    score1 = 1;
                    grid[Row1][Col1] = ' ';
                    counter1++;
                }
                else if(Col1 > 15)
                {
                    Row1 = 13;
                    Col1 = 15;
                    grid[Row1][Col1] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row1][Col1] = p;
                }
        }
}

void Board::move2(int position, char p, int Roll, int r, int c)
{
    int l = r;
    int k = c;
    int turn = 0;

     /// moving to the top (left)
      if(Row2 >=0  && Row2 <=13 && Col2 ==15)
        {
                Row2 = Row2 - position;

                if (Row2 < 1)
                {
                    int difference;
                    difference = abs(Row2 - 1);

                    if(difference == 2)
                    {
                        Row2 = 1;
                        Col2 = 17;
                    }
                    else
                    {
                        Row2 = difference-1;
                        Col2 = 17;
                    }
                }

                if(Row2 == 1)
                {
                    turn++;
                   grid[Row2][Col2] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces2 = roll*2;
                    move2(moveRowSpaces2, p, Roll, r, c);
                }

            if(grid[Row2][Col2] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row2 = l;
                       Col2 = k;
                       grid[Row2][Col2] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row2][Col2] = p;
                }
        }

        ///moving to the bottom (right)
        else if(Row2 >=1 && Row2 <= 15 && Col2 == 17)
        {
            Row2 = Row2 + position;

            if(Row2 > 15)
            {
                int difference;
                difference = abs(Row2 - 15);
                 if (difference == 2)
                    {
                        Row2 = 15;
                        Col2 = 19;
                    }
                    else
                    {
                        Row2 = 15;
                        Col2 += difference;
                    }
            }
            if(grid[Row2][Col2] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row2 = l;
                       Col2 = k;
                       grid[Row2][Col2] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row2][Col2] = p;
                }
        }

        ///three
        else if(Row2 == 15 && Col2 > 17 && Col2 <=31)
        {
                Col2 = Col2 + position;

                if (Col2 > 31)
                {
                    int difference;
                    difference = abs(Col2 - 31) ;

                    if(difference == 2)
                    {
                        Row2 = 17;
                        Col2 = 31;
                    }
                    else
                    {
                        Row2 = 17;
                        Col2 = 31 - (difference-2);
                    }
                }

                if(Col2 == 31)
                {
                    turn++;
                    grid[Row2][Col2] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    move2(moveRowSpaces1, p, Roll, r, c);
                }

          if(grid[Row2][Col2] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row2 = l;
                       Col2 = k;
                       grid[Row2][Col2] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row2][Col2] = p;
                }
        }

        ///four
        else if(Row2 == 17 && Col2 > 16 && Col2 <= 31)
        {
            Col2 = Col2 - position;

               if (Col2 < 17)
                {
                    int difference;
                    difference = abs(17-Col2);

                    if(difference == 2)
                    {
                        Row2 = 19;
                        Col2 = 17;
                    }
                    else
                    {
                        Row2 = 17 + (abs(Col2-17));
                        Col2 = 17;
                    }
                }

            if(grid[Row2][Col2] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row2 = l;
                       Col2 = k;
                       grid[Row2][Col2] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row2][Col2] = p;
                }
        }

        ///five
        else if(Row2>=19 && Row2<=31 && Col2 == 17)
        {
                Row2 = Row2 + position;

                if (Row2 == 31)
                {
                    /// additional turn
                    turn++;
                    grid[Row2][Col2] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces2 = roll*2;
                    move2(moveRowSpaces2, p, Roll, r, c);
                }

                if (Row2 > 31)
                {
                    int difference;
                    difference = Row2 - 31;

                    if (difference == 2)
                    {
                        Row2 = 31;
                        Col2 = 15;
                        grid[Row2][Col2] = p;
                    playGame();
                    turn++;
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    move2(moveRowSpaces1, p, Roll, r, c);
                    }
                    else
                    {
                        Row2 = 31 - ((Row2 % 31)- 2);
                        Col2 -= 2;
                    }
                }
          if(grid[Row2][Col2] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row2 = l;
                       Col2 = k;
                       grid[Row2][Col2] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row2][Col2] = p;
                }
        }


        ///six
        else if(Row2 >=19 && Row2 <=31 && Col2 ==15)
        {
            if(Row2 + position != 17 && Col2 + position!=32)
            {
                Row2 = Row2 - position;

                if (Row2 < 17)
                {
                    int difference;
                    difference = 17 - Row2;

                    if(difference == 2)
                    {
                        Row2 = 17;
                        Col2 = Col2 - 2;
                    }
                    else
                    {
                        Col2 = 15 - ((17 % Row2));
                        Row2 += 17 % Row2;
                    }
                }
            }
           if(grid[Row2][Col2] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row2 = l;
                       Col2 = k;
                       grid[Row2][Col2] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row2][Col2] = p;
                }
        }

        ///seven
        else if(Row2 ==17 && Col2 >0 && Col2 <=15)
        {
                Col2 = Col2 - position;

                if (Col2 < 0)
                {
                    int difference;
                    difference = abs(Col2);

                    if(difference == 2)
                    {
                        Row2 = 15;
                        Col2 = 1;
                    }
                    else
                    {
                        Col2 = difference;
                        Row2 = 15;
                    }
                }

                if(Col2 == 1)
                {
                    turn++;
                    grid[Row2][Col2] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    move2(moveRowSpaces1, p, Roll, r, c);
                }

            if(grid[Row2][Col2] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row2 = l;
                       Col2 = k;
                       grid[Row2][Col2] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row2][Col2] = p;
                }
        }

        ///eight
        else if(Row2 ==15 && Col2 >0 && Col2 <=15)
        {
            Col2 = Col2 + position;
               if(grid[Row2][Col2] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row2 = l;
                       Col2 = k;
                       grid[Row2][Col2] = p;
                }
                else if(Row2 == 15 && Col2 == 13 && counter2 == 0 && p == '2')
                {
                    score1 = 1;
                    grid[Row2][Col2] = ' ';
                    counter2++;
                }
                else if(Col2 > 15)
                {
                    Row2 = 13;
                    Col2 = 15;
                    grid[Row2][Col2] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row2][Col2] = p;
                }
        }
}

void Board::move3(int position, char p, int Roll, int r, int c)
{
    int l = r;
    int k = c;
    int turn = 0;

     /// moving to the top (left)
      if(Row3 >=0  && Row3 <=13 && Col3 ==15)
        {
                Row3 = Row3 - position;

                if (Row3 < 1)
                {
                    int difference;
                    difference = abs(Row3 - 1);

                    if(difference == 2)
                    {
                        Row3 = 1;
                        Col3 = 17;
                    }
                    else
                    {
                        Row3 = difference-1;
                        Col3 = 17;
                    }
                }

                if(Row3 == 1)
                {
                    turn++;
                   grid[Row3][Col3] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces2 = roll*2;
                    move3(moveRowSpaces2, p, Roll, r, c);
                }
                if(grid[Row3][Col3] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row3 = l;
                       Col3 = k;
                       grid[Row3][Col3] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row3][Col3] = p;
                }

        }

        ///moving to the bottom (right)
        else if(Row3 >=1 && Row3 <= 15 && Col3 == 17)
        {
            Row3 = Row3 + position;

            if(Row3 > 15)
            {
                int difference;
                difference = abs(Row3 - 15);
                 if (difference == 2)
                    {
                        Row3 = 15;
                        Col3 = 19;
                    }
                    else
                    {
                        Row3 = 15;
                        Col3 += difference;
                    }
            }
           if(grid[Row3][Col3] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row3 = l;
                       Col3 = k;
                       grid[Row3][Col3] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row3][Col3] = p;
                }
        }

        ///three
        else if(Row3 == 15 && Col3 > 17 && Col3 <=31)
        {
                Col3 = Col3 + position;

                if (Col3 > 31)
                {
                    int difference;
                    difference = abs(Col3 - 31) ;

                    if(difference == 2)
                    {
                        Row3 = 17;
                        Col3 = 31;
                    }
                    else
                    {
                        Row3 = 17;
                        Col3 = 31 - (difference-2);
                    }
                }

                if(Col3 == 31)
                {
                    turn++;
                    grid[Row3][Col3] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    move3(moveRowSpaces1, p, Roll, r, c);
                }

         if(grid[Row3][Col3] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row3 = l;
                       Col3 = k;
                       grid[Row3][Col3] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row3][Col3] = p;
                }
        }

        ///four
        else if(Row3 == 17 && Col3 > 16 && Col3 <= 31)
        {
            Col3 = Col3 - position;

               if (Col3 < 17)
                {
                    int difference;
                    difference = abs(17-Col3);

                    if(difference == 2)
                    {
                        Row3 = 19;
                        Col3 = 17;
                    }
                    else
                    {
                        Row3 = 17 + (abs(Col3-17));
                        Col3 = 17;
                    }
                }
            if(grid[Row3][Col3] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row3 = l;
                       Col3 = k;
                       grid[Row3][Col3] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row3][Col3] = p;
                }
        }

        ///five
        else if(Row3>=19 && Row3<=31 && Col3 == 17)
        {
                Row3 = Row3 + position;

                if (Row3 == 31)
                {
                    /// additional turn
                    turn++;
                    grid[Row3][Col3] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces2 = roll*2;
                    move3(moveRowSpaces2, p, Roll, r, c);
                }

                if (Row3 > 31)
                {
                    int difference;
                    difference = Row3 - 31;

                    if (difference == 2)
                    {
                        Row3 = 31;
                        Col3 = 15;
                        grid[Row3][Col3] = p;
                        turn++;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    move3(moveRowSpaces1, p, Roll, r, c);
                    }
                    else
                    {
                        Row3 = 31 - ((Row3 % 31)- 2);
                        Col3 -= 2;
                    }
                }
         if(grid[Row3][Col3] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row3 = l;
                       Col3 = k;
                       grid[Row3][Col3] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row3][Col3] = p;
                }
        }


        ///six
        else if(Row3 >=19 && Row3 <=31 && Col3 ==15)
        {
            if(Row3 + position != 17 && Col3 + position!=32)
            {
                Row3 = Row3 - position;

                if (Row3 < 17)
                {
                    int difference;
                    difference = 17 - Row3;

                    if(difference == 2)
                    {
                        Row3 = 17;
                        Col3 = Col3 - 2;
                    }
                    else
                    {
                        Col3 = 15 - ((17 % Row3));
                        Row3 += 17 % Row3;
                    }
                }
            }

            if(grid[Row3][Col3] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row3 = l;
                       Col3 = k;
                       grid[Row3][Col3] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row3][Col3] = p;
                }
        }

        ///seven
        else if(Row3 ==17 && Col3 >0 && Col3 <=15)
        {
                Col3 = Col3 - position;

                if (Col3 < 0)
                {
                    int difference;
                    difference = abs(Col3);

                    if(difference == 2)
                    {
                        Row3 = 15;
                        Col3 = 1;
                    }
                    else
                    {
                        Col3 = difference;
                        Row3 = 15;
                    }
                }

                if(Col3 == 1)
                {
                    turn++;
                    grid[Row3][Col3] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    move3(moveRowSpaces1, p, Roll, r, c);
                }

            if(grid[Row3][Col3] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row3 = l;
                       Col3 = k;
                       grid[Row3][Col3] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row3][Col3] = p;
                }
        }

        ///eight
        else if(Row3 ==15 && Col3 >0 && Col3 <=15)
        {
            Col3 = Col3 + position;
            if(grid[Row3][Col3] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row3 = l;
                       Col3 = k;
                       grid[Row3][Col3] = p;
                }
                else if(Row3 == 15 && Col3 == 13 && counter3 == 0 && p == '3')
                {
                    score1 = 1;
                    grid[Row3][Col3] = ' ';
                    counter3++;
                }
                else if(Col3 > 15)
                {
                    Row3 = 13;
                    Col3 = 15;
                    grid[Row3][Col3] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row3][Col3] = p;
                }
        }
}

void Board::move4(int position, char p, int Roll, int r, int c)
{
    int l = r;
    int k = c;
    int turn = 0;

     /// moving to the top (left)
      if(Row4 >=0  && Row4 <=13 && Col4 ==15)
        {
                Row4 = Row4 - position;

                if (Row4 < 1)
                {
                    int difference;
                    difference = abs(Row4 - 1);

                    if(difference == 2)
                    {
                        Row4 = 1;
                        Col4 = 17;
                    }
                    else
                    {
                        Row4 = difference-1;
                        Col4 = 17;
                    }
                }

                if(Row4 == 1)
                {
                    turn++;
                   grid[Row4][Col4] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces2 = roll*2;
                    move4(moveRowSpaces2, p, Roll, r, c);
                }


            if(grid[Row4][Col4] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row4 = l;
                       Col4 = k;
                       grid[Row4][Col4] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row4][Col4] = p;
                }
        }

        ///moving to the bottom (right)
        else if(Row4 >=1 && Row4 <= 15 && Col4 == 17)
        {
            Row4 = Row4 + position;

            if(Row4 > 15)
            {
                int difference;
                difference = abs(Row4 - 15);
                 if (difference == 2)
                    {
                        Row4 = 15;
                        Col4 = 19;
                    }
                    else
                    {
                        Row4 = 15;
                        Col4 += difference;
                    }
            }


            if(grid[Row4][Col4] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row4 = l;
                       Col4 = k;
                       grid[Row4][Col4] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row4][Col4] = p;
                }
        }

        ///three
        else if(Row4 == 15 && Col4 > 17 && Col4 <=31)
        {
                Col4 = Col4 + position;

                if (Col4 > 31)
                {
                    int difference;
                    difference = abs(Col4 - 31) ;

                    if(difference == 2)
                    {
                        Row4 = 17;
                        Col4 = 31;
                    }
                    else
                    {
                        Row4 = 17;
                        Col4 = 31 - (difference-2);
                    }
                }

                if(Col4 == 31)
                {
                    turn++;
                    grid[Row4][Col4] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    move4(moveRowSpaces1, p, Roll, r, c);
                }


            if(grid[Row4][Col4] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row4 = l;
                       Col4 = k;
                       grid[Row4][Col4] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row4][Col4] = p;
                }
        }

        ///four
        else if(Row4 == 17 && Col4 > 16 && Col4 <= 31)
        {
            Col4 = Col4 - position;

               if (Col4 < 17)
                {
                    int difference;
                    difference = abs(17-Col4);

                    if(difference == 2)
                    {
                        Row4 = 19;
                        Col4 = 17;
                    }
                    else
                    {
                        Row4 = 17 + (abs(Col4-17));
                        Col4 = 17;
                    }
                }

            if(grid[Row4][Col4] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row4 = l;
                       Col4 = k;
                       grid[Row4][Col4] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row4][Col4] = p;
                }
        }

        ///five
        else if(Row4>=19 && Row4<=31 && Col4 == 17)
        {
                Row4 = Row4 + position;

                if (Row4 == 31)
                {
                    /// additional turn
                    turn++;
                    grid[Row4][Col4] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces2 = roll*2;
                    move4(moveRowSpaces2, p, Roll, r, c);
                }

                if (Row4 > 31)
                {
                    int difference;
                    difference = Row4 - 31;

                    if (difference == 2)
                    {
                        Row4 = 31;
                        Col4 = 15;
                        grid[Row4][Col4] = p;
                        turn++;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    move4(moveRowSpaces1, p, Roll, r, c);
                    }
                    else
                    {
                        Row4 = 31 - ((Row4 % 31)- 2);
                        Col4 -= 2;
                    }
                }

            if(grid[Row4][Col4] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row4 = l;
                       Col4 = k;
                       grid[Row4][Col4] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row4][Col4] = p;
                }
        }


        ///six
        else if(Row4 >=19 && Row4 <=31 && Col4 ==15)
        {
            if(Row4 + position != 17 && Col4 + position!=32)
            {
                Row4 = Row4 - position;

                if (Row4 < 17)
                {
                    int difference;
                    difference = 17 - Row4;

                    if(difference == 2)
                    {
                        Row4 = 17;
                        Col4 = Col4 - 2;
                    }
                    else
                    {
                        Col4 = 15 - ((17 % Row4));
                        Row4 += 17 % Row4;
                    }
                }
            }

            if(grid[Row4][Col4] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row4 = l;
                       Col4 = k;
                       grid[Row4][Col4] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row4][Col4] = p;
                }
        }

        ///seven
        else if(Row4 ==17 && Col4 >0 && Col4 <=15)
        {
                Col4 = Col4 - position;

                if (Col4 < 0)
                {
                    int difference;
                    difference = abs(Col4);

                    if(difference == 2)
                    {
                        Row4 = 15;
                        Col4 = 1;
                    }
                    else
                    {
                        Col4 = difference;
                        Row4 = 15;
                    }
                }

                if(Col4 == 1)
                {
                    turn++;
                    grid[Row4][Col4] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    move4(moveRowSpaces1, p, Roll, r, c);
                }

            if(grid[Row4][Col4] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row4 = l;
                       Col4 = k;
                       grid[Row4][Col4] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row4][Col4] = p;
                }
        }

        ///eight
        else if(Row4 ==15 && Col4 >0 && Col4 <=15)
        {
            Col4 = Col4 + position;
            if(grid[Row4][Col4] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row4 = l;
                       Col4 = k;
                       grid[Row4][Col4] = p;
                }
                else if(Row4 == 15 && Col4 == 13 && counter4 == 0 && p == '4')
                {
                    score1 = 1;
                    grid[Row4][Col4] = ' ';
                    counter4++;
                }
                else if(Col4 > 15)
                {
                    Row4 = 13;
                    Col4 = 15;
                    grid[Row4][Col4] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row4][Col4] = p;
                }
        }
}

void Board::move5(int position, char p, int Roll, int r, int c)
{
    int l = r;
    int k = c;
    int turn = 0;

     /// moving to the top (left)
      if(Row5 >=0  && Row5 <=13 && Col5 ==15)
        {
                Row5 = Row5 - position;

                if (Row5 < 1)
                {
                    int difference;
                    difference = abs(Row5 - 1);

                    if(difference == 2)
                    {
                        Row5 = 1;
                        Col5 = 17;
                    }
                    else
                    {
                        Row5 = difference-1;
                        Col5 = 17;
                    }
                }

                if(Row5 == 1)
                {
                    turn++;
                   grid[Row5][Col5] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces2 = roll*2;
                    move5(moveRowSpaces2, p, Roll, r, c);
                }
            if(grid[Row5][Col5] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row5 = l;
                       Col5 = k;
                       grid[Row5][Col5] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row5][Col5] = p;
                }
        }

        ///moving to the bottom (right)
        else if(Row5 >=1 && Row5 <= 15 && Col5 == 17)
        {
            Row5 = Row5 + position;

            if(Row5 > 15)
            {
                int difference;
                difference = abs(Row5 - 15);
                 if (difference == 2)
                    {
                        Row5 = 15;
                        Col5 = 19;
                    }
                    else
                    {
                        Row5 = 15;
                        Col5 += difference;
                    }
            }
            if(grid[Row5][Col5] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row5 = l;
                       Col5 = k;
                       grid[Row5][Col5] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row5][Col5] = p;
                }
        }

        ///three
        else if(Row5 == 15 && Col5 > 17 && Col5 <=31)
        {
                Col5 = Col5 + position;

                if (Col5 > 31)
                {
                    int difference;
                    difference = abs(Col5 - 31) ;

                    if(difference == 2)
                    {
                        Row5 = 17;
                        Col5 = 31;
                    }
                    else
                    {
                        Row5 = 17;
                        Col5 = 31 - (difference-2);
                    }
                }

                if(Col5 == 31)
                {
                    turn++;
                    grid[Row5][Col5] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    move5(moveRowSpaces1, p, Roll, r, c);
                }

            if(grid[Row5][Col5] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row5 = l;
                       Col5 = k;
                       grid[Row5][Col5] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row5][Col5] = p;
                }
        }

        ///four
        else if(Row5 == 17 && Col5 > 16 && Col5 <= 31)
        {
            Col5 = Col5 - position;

               if (Col5 < 17)
                {
                    int difference;
                    difference = abs(17-Col5);

                    if(difference == 2)
                    {
                        Row5 = 19;
                        Col5 = 17;
                    }
                    else
                    {
                        Row5 = 17 + ((Col5-17));
                        Col5 = 17;
                    }
                }

            if(grid[Row5][Col5] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row5 = l;
                       Col5 = k;
                       grid[Row5][Col5] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row5][Col5] = p;
                }
        }

        ///five
        else if(Row5>=19 && Row5<=31 && Col5 == 17)
        {
                Row5 = Row5 + position;

                if (Row5 == 31)
                {
                    /// additional turn
                    turn++;
                    grid[Row5][Col5] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces2 = roll*2;
                    move5(moveRowSpaces2, p, Roll, r, c);
                }

                if (Row5 > 31)
                {
                    int difference;
                    difference = Row5 - 31;

                    if (difference == 2)
                    {
                        Row5 = 31;
                        Col5 = 15;
                        grid[Row5][Col5] = p;
                        turn++;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    move5(moveRowSpaces1, p, Roll, r, c);
                    }
                    else
                    {
                        Row5 = 31 - ((Row5 % 31)- 2);
                        Col5 -= 2;
                    }
                }
            if(grid[Row5][Col5] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row5 = l;
                       Col5 = k;
                       grid[Row5][Col5] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row5][Col5] = p;
                }
        }


        ///six
        else if(Row5 >=19 && Row5 <=31 && Col5 ==15)
        {
            if(Row5 + position != 17 && Col5 + position!=32)
            {
                Row5 = Row5 - position;

                if (Row5 < 17)
                {
                    int difference;
                    difference = 17 - Row5;

                    if(difference == 2)
                    {
                        Row5 = 17;
                        Col5 = Col5 - 2;
                    }
                    else
                    {
                        Col5 = 15 - ((17 % Row5));
                        Row5 += 17 % Row5;
                    }
                }
            }
           if(grid[Row5][Col5] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row5 = l;
                       Col5 = k;
                       grid[Row5][Col5] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row5][Col5] = p;
                }
        }

        ///seven
        else if(Row5 ==17 && Col5 >0 && Col5 <=15)
        {
                Col5 = Col5 - position;

                if (Col5 < 0)
                {
                    int difference;
                    difference = abs(Col5);

                    if(difference == 2)
                    {
                        Row5 = 15;
                        Col5 = 1;
                    }
                    else
                    {
                        Col5 = difference;
                        Row5 = 15;
                    }
                }

                if(Col5 == 1)
                {
                    turn++;
                    grid[Row5][Col5] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    move5(moveRowSpaces1, p, Roll, r, c);
                }
            if(grid[Row5][Col5] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row5 = l;
                       Col5 = k;
                       grid[Row5][Col5] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row5][Col5] = p;
                }
        }

        ///eight
        else if(Row5 ==15 && Col5 >0 && Col5 <=15)
        {
            Col5 = Col5 + position;
             if(grid[Row5][Col5] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row5 = l;
                       Col5 = k;
                       grid[Row5][Col5] = p;
                }
                else if(Row5 == 15 && Col5 == 13 && counter5 == 0 && p == '5')
                {
                    score1 = 1;
                    grid[Row5][Col5] = ' ';
                }
                else if(Col5 > 15)
                {
                    Row5 = 13;
                    Col5 = 15;
                    grid[Row5][Col5] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row5][Col5] = p;
                }
        }
}

void Board::move6(int position, char p, int Roll, int r, int c)
{
    int l = r;
    int k = c;
    int turn = 0;

     /// moving to the top (left)
      if(Row6 >=0  && Row6 <=13 && Col6 ==15)
        {
                Row6 = Row6 - position;

                if (Row6 < 1)
                {
                    int difference;
                    difference = abs(Row6 - 1);

                    if(difference == 2)
                    {
                        Row6 = 1;
                        Col6 = 17;
                    }
                    else
                    {
                        Row6 = difference-1;
                        Col6 = 17;
                    }
                }

                if(Row6 == 1)
                {
                    turn++;
                   grid[Row6][Col6] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces2 = roll*2;
                    move6(moveRowSpaces2, p, Roll, r, c);
                }

             if(grid[Row6][Col6] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row6 = l;
                       Col6 = k;
                       grid[Row6][Col6] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row6][Col6] = p;
                }
        }

        ///moving to the bottom (right)
        else if(Row6 >=1 && Row6 <= 15 && Col6 == 17)
        {
            Row6 = Row6 + position;

            if(Row6 > 15)
            {
                int difference;
                difference = abs(Row6 - 15);
                 if (difference == 2)
                    {
                        Row6 = 15;
                        Col6 = 19;
                    }
                    else
                    {
                        Row6 = 15;
                        Col6 += difference;
                    }
            }
             if(grid[Row6][Col6] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row6 = l;
                       Col6 = k;
                       grid[Row6][Col6] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row6][Col6] = p;
                }
        }

        ///three
        else if(Row6 == 15 && Col6 > 17 && Col6 <=31)
        {
                Col6 = Col6 + position;

                if (Col6 > 31)
                {
                    int difference;
                    difference = abs(Col6 - 31) ;

                    if(difference == 2)
                    {
                        Row6 = 17;
                        Col6 = 31;
                    }
                    else
                    {
                        Row6 = 17;
                        Col6 = 31 - (difference-2);
                    }
                }

                if(Col6 == 31)
                {
                    turn++;
                    grid[Row6][Col6] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                  ///move the do-while to referee later
                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    move6(moveRowSpaces1, p, Roll, r, c);
                }

           if(grid[Row6][Col6] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row6 = l;
                       Col6 = k;
                       grid[Row6][Col6] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row6][Col6] = p;
                }
        }

        ///four
        else if(Row6 == 17 && Col6 > 16 && Col6 <= 31)
        {
            Col6 = Col6 - position;

               if (Col6 < 17)
                {
                    int difference;
                    difference = abs(17-Col6);

                    if(difference == 2)
                    {
                        Row6 = 19;
                        Col6 = 17;
                    }
                    else
                    {
                        Row6 = 17 + (abs(Col6-17));
                        Col6 = 17;
                    }
                }

            if(grid[Row6][Col6] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row6 = l;
                       Col6 = k;
                       grid[Row6][Col6] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row6][Col6] = p;
                }
        }

        ///five
        else if(Row6>=19 && Row6<=31 && Col6 == 17)
        {
                Row6 = Row6 + position;

                if (Row6 == 31)
                {
                    /// additional turn
                    turn++;
                    grid[Row6][Col6] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces2 = roll*2;
                    move6(moveRowSpaces2, p, Roll, r, c);
                }

                if (Row6 > 31)
                {
                    int difference;
                    difference = Row6 - 31;

                    if (difference == 2)
                    {
                        Row6 = 31;
                        Col6 = 15;
                        grid[Row6][Col6] = p;
                        turn++;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;

                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    move6(moveRowSpaces1, p, Roll, r, c);
                    }
                    else
                    {
                        Row6 = 31 - ((Row6 % 31)- 2);
                        Col6 -= 2;
                    }
                }
             if(grid[Row6][Col6] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row6 = l;
                       Col6 = k;
                       grid[Row6][Col6] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row6][Col6] = p;
                }
        }


        ///six
        else if(Row6 >=19 && Row6 <=31 && Col6 ==15)
        {
            if(Row6 + position != 17 && Col6 + position!=32)
            {
                Row6 = Row6 - position;

                if (Row6 < 17)
                {
                    int difference;
                    difference = 17 - Row6;

                    if(difference == 2)
                    {
                        Row6 = 17;
                        Col6 = Col6 - 2;
                    }
                    else
                    {
                        Col6 = 15 - ((17 % Row6));
                        Row6 += 17 % Row6;
                    }
                }
            }
             if(grid[Row6][Col6] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row6 = l;
                       Col6 = k;
                       grid[Row6][Col6] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row6][Col6] = p;
                }
        }

        ///seven
        else if(Row6 ==17 && Col6 >0 && Col6 <=15)
        {
                Col6 = Col6 - position;

                if (Col6 < 0)
                {
                    int difference;
                    difference = abs(Col6);

                    if(difference == 2)
                    {
                        Row6 = 15;
                        Col6 = 1;
                    }
                    else
                    {
                        Col6 = difference;
                        Row6 = 15;
                    }
                }

                if(Col6 == 1)
                {
                    turn++;
                    grid[Row6][Col6] = p;
                    playGame();
                    cout << "You got another turn!" << endl;
                    srand(time(0));
                    int roll;
                    roll = rand()%6;
                    cout << "Your roll is: " << roll << endl;


                    char piece = ' ';
                    if(roll!=0)
                    {
                    do
                    {
                    cout << "Enter a character: ";
                    cin >> piece;
                    }
                    while(piece!=p);
                    }

                    int moveRowSpaces1 = roll*2;
                    move6(moveRowSpaces1, p, Roll, r, c);
                }
            if(grid[Row6][Col6] != ' ' && Roll != 0 && turn == 0)
                {
                       notBlank = true;
                       Row6 = l;
                       Col6 = k;
                       grid[Row6][Col6] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row6][Col6] = p;
                }
        }

        ///eight
        else if(Row6 ==15 && Col6 >0 && Col6 <=15)
        {
            Col6 = Col6 + position;
             if(grid[Row6][Col6] != ' ' && Roll != 0)
                {
                       notBlank = true;
                       Row6 = l;
                       Col6 = k;
                       grid[Row6][Col6] = p;
                }
                else if(Row6 == 15 && Col6 == 13 && counter6 == 0 && p == '6')
                {
                    score1 = 1;
                    grid[Row6][Col6] = ' ';
                    counter6++;
                }
                else if(Col6 > 15)
                {
                    Row6 = 13;
                    Col6 = 15;
                    grid[Row6][Col6] = p;
                }
                else
                {
                    notBlank = false;
                    grid[Row6][Col6] = p;
                }
        }
}

///return areas that are notBlank
bool Board::getNotBlank()
{
    return notBlank;
}

