#include "prod225colour.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Board.h"
#include <conio.h>



int main()
{
	Board gameBoard;
	char* points = gameBoard.getPoints();
	int round = 0;
	unsigned char Key = '\0';
	gameBoard.displayTitle();

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

	do 
	{
		Key = _getch();
		round = gameBoard.drawBoard(round, Key);
		gameBoard.checkWin();
		
	} while (round < 9);

	return 0;
}