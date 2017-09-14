#include "stdafx.h"
#include "dominoTile.h"



// default constructor
dominoTile::dominoTile()
{
}

// default destructor
dominoTile::~dominoTile()
{
}

//this will create a new domino tile with a set left and right
dominoTile::dominoTile(int leftSide, int rightSide)
{
	this->leftSide = leftSide;
	this->rightSide = rightSide;
}

//this will return the left-hand side of the tile
int dominoTile::getLeftSide()
{
	return this->leftSide;
}

//this will return the right-hand side of the tile
int dominoTile::getRightSide()
{
	return this->rightSide;
}

// this will retrieve the tile object
// THIS IS CURRENTLY NOT WORKING
dominoTile dominoTile::getTile()
{
	dominoTile tempDomino(leftSide, rightSide);
	return tempDomino;
}

// setter function
void dominoTile::setTile(int leftSide, int rightSide)
{
	this->leftSide = leftSide;
	this->rightSide = rightSide;
}

// will evaluate this statement and determine weather it is
// true or false
bool dominoTile::isDouble()
{
	return (leftSide == rightSide);
}

// this function will display the tile information on the console
void dominoTile::printTile()
{
	cout << this->leftSide << " - " << this->rightSide << " ";
}

// this function will reverse the tile
void dominoTile::reverseTile()
{
	// create a temporary variable and set it to the left-hand side
	int tempPip = this->leftSide;
	// then set the left-hand side = to the right-hand side
	this->leftSide = this->rightSide;
	// finally set the right-hand side to the temporary variable
	this->rightSide = tempPip;
}
