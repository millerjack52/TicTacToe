#pragma once
#ifndef __BOARD_H__
#define __BOARD_H__

class Board
{
public:
	Board();
	~Board();
	int drawBoard(int round, int Key);
	void setPoints(int Key);
	char* getPoints();
	void displayTitle();
	bool checkWin();
	bool checkMove(int Key);

private:
	char points[9] = { '0', '1', '2', '3', '4', '5', '6', '7', '8' };

};

#endif