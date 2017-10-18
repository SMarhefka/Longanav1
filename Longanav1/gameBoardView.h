/************************************************************************
* Name:	Svetlana Marhefka												*
* Project : Project 1 - Longana											*
* Class : CMPS 366 Organization of Programming Languages (OPL)			*
* Date : 10/14/2017														*
*************************************************************************/

#pragma once
#include "dominoTile.h"

class gameBoardView
{
public:
	// Default constructor
	gameBoardView();

	// Retrieves all pertanant information needed to
	// display the gameBoard
	void getBoard(vector<dominoTile> &a_inBoard);
	
	// Deletes or refreshes the containers use to hold the gameboard
	void deleteLines();

	// Prints the gameBoard to the screen
	void printBrdToScreen(vector<dominoTile> &a_inBoard);

	// Prints the gameBoard to a specified file
	void printBrdToFile(ofstream & a_inStream, vector<dominoTile> &a_inBoard);

	// Default constructor
	~gameBoardView();
private:
	
	queue<string> m_firstLine;
	vector<string> m_secondLine;
	queue<string> m_thirdLine;
};