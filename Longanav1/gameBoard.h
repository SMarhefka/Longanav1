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
	void addToLeft(dominoTile a_tileToAdd);

	// this function will print the right most tile
	dominoTile getRightMostTile();

	// void printBoardToFile();
	void printToScreen();


private:
	vector<dominoTile>::iterator insertAt;
	vector<dominoTile> leftSide;
	vector<dominoTile> rightSide;
	dominoTile m_leftMostTile;
	dominoTile m_rightMostTile;
};