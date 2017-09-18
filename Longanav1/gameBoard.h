#pragma once
#include <vector>
#include "dominoTile.h"
#include "gameBoard.h"

class gameBoard
{
public:
	// this is the game board itself
	gameBoard();
	// this is the default constructor
	~gameBoard();

	// this function will print the board to the console screen
	void printBoard();



private:
	vector<dominoTile> boardLeft;
	vector<dominoTile> boardRight;
};