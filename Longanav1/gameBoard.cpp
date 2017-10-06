#include "stdafx.h"
#include "gameBoard.h"

gameBoard::gameBoard()
{
	//tournament.printScore();
}

gameBoard::~gameBoard()
{
}

void gameBoard::addToLeft(dominoTile a_tileToAdd)
{
	if (leftSide.size() == 0)
	{
		leftSide.push_back(a_tileToAdd);
	}
	else
	{
		insertAt = leftSide.begin();
		insertAt = leftSide.insert(insertAt, a_tileToAdd);
	}
}

void gameBoard::addToRight(dominoTile a_tileToAdd)
{
	rightSide.push_back(a_tileToAdd);
}

// this gets the right most tile to be compared
dominoTile gameBoard::getRightMostTile()
{
	// create a new temporary dominoTile
	dominoTile tempTile;
	// set the tempTile to the last element in the 
	// rightSide array
	if (rightSide.empty())
	{
		tempTile = leftSide.at(leftSide.size() - 1);
	}
	else
	{
		tempTile = rightSide.at(rightSide.size() - 1);
	}
	// return the tile
	return tempTile;
}

dominoTile gameBoard::getLeftMostTile()
{
	// create a new temporary dominoTile
	dominoTile tempTile;
	if (leftSide.empty())
	{
		tempTile = rightSide.at(0);
	}
	else
	{
		// set the tempTile to the first element in the 
		// leftSide array
		tempTile = leftSide.at(0);
	}
	// return the tile
	return tempTile;
}

bool gameBoard::isLeftEmpty()
{
	return leftSide.size() == 0;
}

bool gameBoard::isRightEmpty()
{
	return rightSide.size() == 0;
}

void gameBoard::printToScreen()
{
	m_boardView.printBrdToScreen(leftSide, rightSide);
}

void gameBoard::printBoardToFile(ofstream & a_inStream)
{
	m_boardView.printBrdToFile(a_inStream, leftSide, rightSide);
}
