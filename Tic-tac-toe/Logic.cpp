#include <iostream>

#include "Logic.h"

Logic::Logic() {}

bool Logic::isEndOfGame(unsigned short row, unsigned short column, unsigned short length, char **boardArray) { //koniec gry
	if (!row && !column)
		return false;

	unsigned short horizontal = 0, vertical = 0, diagonal = 0, diagonal1 = 0;

	for (unsigned short i = 0; i < length; i++) { // w poziomie
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

		if (row+column == length&&boardArray[i][length-i] == boardArray[row][column]) {
			diagonal1++;
			std:: cout << 'dupa';
			if (diagonal1 == length)
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