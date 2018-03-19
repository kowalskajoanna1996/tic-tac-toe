#include<iostream>

#include "Board.h"

Board::Board() {
	Board::player1 = Player('x');
	Board::player2 = Player('o');

	Board::makeBoard();
}

unsigned short Board::getSizeBoard() {//zwraca rozmiar planszy
	return Board::sizeBoard;
}

unsigned short Board::getRow() {
	return Board::row;
}

unsigned short Board::getColumn() {
	return Board::column;
}

char Board::getItem(unsigned short row, unsigned short column) { //zwraca element tablicy
	return Board::myBoard[row][column]; 
}

void Board::makeBoard() {  //wywolywana tylko raz
	std::cout << "Set size of board: ";
	std::cin >> Board::sizeBoard;

	Board::myBoard = new char*[Board::sizeBoard];	//tworzenie planszy
	for (int i = 0; i < sizeBoard; ++i)
		Board::myBoard[i] = new char[Board::sizeBoard];

	for (int i = 0; i < Board::sizeBoard; i++) {	//wypelnienie spacjami
		for (int j = 0; j < Board::sizeBoard; j++) {
			Board::myBoard[i][j] = ' ';
		}
	}

	Board::round();
}

void Board::drawBoard() {	//rysuje plansze i wypelnia ja obecnymi wartosciami
	char letter = 'A';
	int j = 0;

	for (int i = 0; i < sizeBoard; i++)//rysowanie planszy
		std::cout << "   " << char(letter + i);

	for (int i = 0; i < sizeBoard; i++) {
		std::cout << '\n';

		for (int j = 0; j < sizeBoard; j++)
			std::cout << "----";

		std::cout << '\n' << i << '|';

		for (j = 0; j < Board::sizeBoard; j++)
			std::cout << ' ' << Board::myBoard[i][j] << " |";
	}
}

void Board::setSignToArrow(unsigned short row, unsigned short column) {//wpisywanie ruchu do tablicy
	if(logic.isFirstPlayer())
		Board::myBoard[row][column] = Board::player1.getSign();
	else
		Board::myBoard[row][column] = Board::player2.getSign();
}

void Board::round() { // rozegranie rundy
	while (true) {
		if (logic.isEndOfGame(Board::row, Board::column, Board::getSizeBoard(), Board::myBoard ))
			break;
		Board::move();
	};
	std::cout << "\n***End of game!***\n";
	getchar();
}

void Board::move() { //wpisanie pozycji gdzie ma byc ruch
	std::cout << "\nEnter the row number: ";
	std::cin >> Board::row;
	std::cout << "Enter the column number: ";
	std::cin >> Board::column;

	while (!logic.canMakeMove(Board::row, Board::column, Board::getSizeBoard(), Board::myBoard[Board::row][Board::column])) {
		std::cout << "\nYou have entered wrong data\n\n";

		std::cout << "\nEnter the row number: ";
		std::cin >> Board::row;
		std::cout << "Enter the column number: ";
		std::cin >> Board::column;
	}

	Board::setSignToArrow(Board::row, Board::column);
	Board::drawBoard();
}


