#ifndef BOARD_H
#define BOARD_H

#include <fstream>
#include "Player.h"
#include "Logic.h"

class Board
{
	private:
		unsigned short row, column, sizeBoard;
		char **myBoard;
		Player player1, player2;
		Logic logic;

		void move();
		void makeBoard();
		void drawBoard();
		void setSignToArrow(unsigned short row, unsigned short column);
	public:	
		Board();
		unsigned short getSizeBoard();
		unsigned short getRow();
		unsigned short getColumn();
		char getItem(unsigned short row, unsigned short column);
		void round();
};
#endif
	