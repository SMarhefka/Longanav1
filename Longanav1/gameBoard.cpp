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

// gets the rightMostTile from the right vector
dominoTile gameBoard::getRightMostTile()
{
	// create a new temporary dominoTile
	dominoTile tempTile;
	// set the tempTile to the last element in the 
	// rightSide array
	tempTile = rightSide.at(rightSide.size());
	// return the tile
	return tempTile;
}

void gameBoard::printToScreen()
{
	cout << "gameBoard: " << "\n";
	for (auto item = leftSide.begin(); item != leftSide.end(); item++)
	{
		cout << (item)->getLeftSide() << "-" << (item)->getRightSide() << " ";
	}
}
