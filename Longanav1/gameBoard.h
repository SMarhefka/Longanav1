#pragma once
#include <vector>
#include "dominoTile.h"
#include "gameBoardView.h"

class gameBoard
{
public:
	// this is the game board itself
	gameBoard();
	// this is the default constructor
	~gameBoard();

	// this function will print the board to the console screen
	void addToLeft(dominoTile a_tileToAdd);

	void addToRight(dominoTile a_tileToAdd);

	// this function will print the right most tile
	dominoTile getRightMostTile();

	dominoTile getLeftMostTile();

	bool isLeftEmpty();

	bool isRightEmpty();

	void printToScreen();

	void printBoardToFile(ofstream & a_inStream);

private:
	gameBoardView m_boardView;
	vector<dominoTile>::iterator insertAt;
	vector<dominoTile> leftSide;
	vector<dominoTile> rightSide;
	dominoTile m_leftMostTile;
	dominoTile m_rightMostTile;
};