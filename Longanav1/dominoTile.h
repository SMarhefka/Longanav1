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
	// default constructor
	dominoTile();

	// create a new domino tile with specific pips
	dominoTile(int a_leftSide, int a_rightSide);

	// this will return the left-side of the domino tile
	int getLeftSide();

	// this will return the right-side of the domino tile
	int getRightSide();

	// checks to see if a domino tile is a double
	bool isDouble();

	// this will reverse the tile
	dominoTile reverseTile();

	// this will count the total pips of the tile
	int tileSum();

	// this function will display the tile to the console
	void printTile();

	// default destructor
	~dominoTile();

private:
	int m_leftSide;
	int m_rightSide;
};

