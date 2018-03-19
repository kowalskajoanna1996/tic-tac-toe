#include <iostream>

#include "Logic.h"

Logic::Logic() {}

bool Logic::isEndOfGame(unsigned short row, unsigned short column, unsigned short length, char **boardArray) { 
	if (!row && !column)
		return false;

	unsigned short horizontal = 0, vertical = 0, diagonal = 0, oppositeDiagonal = 0;

	for (unsigned short i = 0; i < length; i++) { 
		if (boardArray[row][i] == boardArray[row][column]) {
			horizontal++;
			if (horizontal == length)
				return true;
		}
		
		if (boardArray[i][column] == boardArray[row][column]) {
			vertical++;
			if (vertical == length)
				return true;
		}
		
		if (row == column && boardArray[i][i] == boardArray[row][column]) {
			diagonal++;
			if (diagonal == length)
				return true; 
		}

		if (row+column == length-1&&boardArray[i][length-i-1] == boardArray[row][column]) {
			oppositeDiagonal++;
			if (oppositeDiagonal == length)
				return true;
		}
	}

	return false;
}

bool Logic::isFirstPlayer() {
	Logic::isCircle = !Logic::isCircle;
	return Logic::isCircle;
}

bool Logic::canMakeMove(unsigned short row, unsigned short column, unsigned short length, char item) {
	if (row >= length || column >= length || item != ' ')
		return false;
	return true;
}