#pragma once
#include <vector>
#include "dominoTile.h"
#include "gameBoardView.h"

class gameBoard
{
public:
	// this is the game board itself
	gameBoard();

	gameBoard(vector<dominoTile> a_inGameBoard);

	// this function will add a tile to the begining of the vector
	void addToLeft(dominoTile a_tileToAdd);
	// this function will add a tile to the end of the vector
	void addToRight(dominoTile a_tileToAdd);

	// this function will retrieve the right most value
	int boardRightValue();
	// this function will retrieve the left most value
	int boardLeftValue();

	// this function will check to see if the board is empty
	bool isBoardEmpty();
	// this function will print the curent board to the screen
	void printToScreen();

	void printBoardToFile(ofstream & a_inStream);

	// this is the default constructor
	~gameBoard();

private:
	gameBoardView m_boardView;
	vector<dominoTile>::iterator insertAt;
	vector<dominoTile> m_boardVector;	
	// int m_leftMostTile;
	// int m_rightMostTile;
};