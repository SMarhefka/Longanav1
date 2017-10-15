/************************************************************************
* Name:	Svetlana Marhefka												*
* Project : Project 1 - Longana											*
* Class : CMPS 366 Organization of Programming Languages (OPL)			*
* Date : 10/14/2017														*
*************************************************************************/

#pragma once

class dominoTile
{
public:
	// Default constructor
	dominoTile();

	// Create a new domino tile with specific pips on
	// each side
	dominoTile(int a_leftSide, int a_rightSide);

	// This will reverse the tile
	dominoTile reverseTile();

	// This will return the left-side of the domino tile
	int getLeftSide();

	// This will return the right-side of the domino tile
	int getRightSide();

	// this will count the total pips of the tile
	int tileSum();

	// Checks to see if a domino tile is a double
	bool isDouble();

	// This function will display the tile to the console
	void printTile();

	// Default destructor
	~dominoTile();

private:
	int m_leftSide;
	int m_rightSide;
};

