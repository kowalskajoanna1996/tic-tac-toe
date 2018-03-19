#ifndef LOGIC_H
#define LOGIC_H

#include <iostream>

class Logic
{
	private:
		bool isCircle;
	public:
		Logic();
		bool isEndOfGame(unsigned short row, unsigned short column, unsigned short length, char **boardArray);
		bool isFirstPlayer();
		bool canMakeMove(unsigned short row, unsigned short column, unsigned short length, char item);
};
#endif