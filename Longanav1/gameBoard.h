/************************************************************************
* Name:	Svetlana Marhefka												*
* Project : Project 1 - Longana											*
* Class : CMPS 366 Organization of Programming Languages (OPL)			*
* Date : 10/14/2017														*
*************************************************************************/

#pragma once
#include "dominoTile.h"
#include "gameBoardView.h"

class gameBoard
{
public:
	// default constructor
	gameBoard();

	// overload constructor
	gameBoard(vector<dominoTile> a_inGameBoard);

	// this function will add a tile to the begining of the vector
	// in the end it will add a tile to the "left" side of the board
	void addToLeft(dominoTile a_tileToAdd);
	
	// this function will add a tile to the end of the vector
	// in the end it will add a tile to the "left" side of the board
	void addToRight(dominoTile a_tileToAdd);

	// this function will retrieve the right most value
	int boardRightValue();
	
	// this function will retrieve the left most value
	int boardLeftValue();

	// this function will check to see if the board is empty
	bool isBoardEmpty();
	
	// this function will print the curent board to the screen
	void printToScreen();

	// this function will print the current board to a spcified file
	void printBoardToFile(ofstream & a_inStream);

	// this is the default constructor
	~gameBoard();

private:
	gameBoardView m_boardView;
	vector<dominoTile>::iterator insertAt;
	vector<dominoTile> m_boardVector;
};