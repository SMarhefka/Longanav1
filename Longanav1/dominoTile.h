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
	dominoTile(int leftSide, int rightSide);

	// this will return the left-side of the tile
	int getLeftSide();
	// this will return the right-side of the tile
	int getRightSide();
	// this will return the actual tile
	dominoTile getTile();

	// this will return the actual tile
	void setTile(int leftSide, int rightSide);

	// this will return weather or not the tile is double
	bool isDouble();

	void printTile();
	
	void reverseTile();

private:
	int leftSide;
	int rightSide;
};

