#include "Board.h"
#include <iostream>
#include "prod225colour.h"

Board::Board() 
{
}

Board::~Board() 
{
    std::cout << "Game over" << std::endl;
}

void Board::displayTitle() 
{
    SetTextColour(4, 15);
    std::cout << "Tic";
    SetTextColour(2, 0);
    std::cout << "  -  Tac  -  ";
    SetTextColour(3, 15);
    std::cout << "Toe" << std::endl;
    SetTextColour(15, 0);

}

char* Board::getPoints() 
{
    return points;
}

int Board::drawBoard(int round, int Key) 
{
    Key = Key - 48;
    if (checkMove(Key)) 
    {
        if (round % 2 == 0) 
        {
            points[Key] = 'X';
        }
        else
        {
            points[Key] = 'O';
        }

        system("cls");
        displayTitle();

        std::cout << "     |     |      " << std::endl;
        std::cout << "  " << points[0] << "  |  " << points[1] << "  |  " << points[2] << "  " << std::endl;
        std::cout << "     |     |      " << std::endl;
        std::cout << "-----+-----+-----" << std::endl;
        std::cout << "     |     |      " << std::endl;
        std::cout << "  " << points[3] << "  |  " << points[4] << "  |  " << points[5] << "  " << std::endl;
        std::cout << "     |     |      " << std::endl;
        std::cout << "-----+-----+-----" << std::endl;
        std::cout << "     |     |      " << std::endl;
        std::cout << "  " << points[6] << "  |  " << points[7] << "  |  " << points[8] << "  " << std::endl;
        std::cout << "     |     |      " << std::endl;

        if (checkWin()) 
        {
            char winner = '\0';
            if (round % 2 == 0)
            {
                winner = 'X';
            }
            else {
                winner = 'O';
            }
            std::cout << "Player " << winner << " wins!" << std::endl;
            return 9;
        }
        round += 1;
        return round;
    }
    return round;
}

bool Board::checkMove(int Key)
{
    if (Key >= 0 && Key < 9) 
    {
        if (points[Key] == 'X' || points[Key] == 'O') 
        {
            std::cout << "Invalid move" << std::endl;
            return false;
        }
        return true;
    }
    else 
    {
        std::cout << "Invalid move" << std::endl;
        return false;
    }
}

bool Board::checkWin()
{
    for (int i = 0; i < 9; i += 3) 
    {
        if (points[i] == points[i + 1] && points[i + 1] == points[i + 2])
        {
            return true;
        }
    }
    for (int i = 0; i < 3; i++) 
    {
        if (points[i] == points[i + 3] && points[i + 3] == points[i + 6]) 
        {
            return true;
        }
    }
    if (points[0] == points[4] && points[4] == points[8]) 
    {
        return true;
    }
    if (points[2] == points[4] && points[4] == points[6])
    {
        return true;
    }
    return false;
}
