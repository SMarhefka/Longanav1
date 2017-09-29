#pragma once
#include <iostream>

using namespace std;

class dominoTile
{
public:
	// default constructor
	dominoTile();

	// default destructor
	~dominoTile();

	// create a new domino tile with specific pips
	dominoTile(int a_leftSide, int a_rightSide);

	// this will return the left-side of the tile
	int getLeftSide();
	// this will return the right-side of the tile
	int getRightSide();

	// this will return the actual tile
	dominoTile getTile();

	// this will return the actual tile
	void setTile(int a_leftSide, int a_rightSide);

	// this will return weather or not the tile is double
	bool isDouble();

	// this will reverse the tile
	void reverseTile();

	// this will count the total of the tile
	// this will be important when summing up the
	// tiles at the end of a gameRound.
	int tileSum();

	// this function will display the tile to the console
	void printTile();

private:
	int m_leftSide;
	int m_rightSide;
};

