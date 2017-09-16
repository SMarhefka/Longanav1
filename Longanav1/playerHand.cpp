#include "stdafx.h"
#include "playerHand.h"

// default constructor
playerHand::playerHand()
{
}

// default destructor
playerHand::~playerHand()
{
}

void playerHand::addTile()
//void playerHand::addTile(dominoTile tileToAdd)
{
	dominoTile tileToAdd;
	boneYard newBoneYard;
	tileToAdd = newBoneYard.dealTile();
	playerTiles.push_back(tileToAdd);
}

void playerHand::removeTile(dominoTile tileToRemove)
{
	// go through the vector and find the tile that
	// is going to be deleted.  I also need to check
	// check for the reverse verson of the 
	//for (auto item = unusedDominos.begin(); item != unusedDominos.end(); item++)
	//{
	//}

}

bool playerHand::isEmpty()
{
	return playerTiles.size() == 0;
}

void playerHand::printHand()
{
	cout << "Player Hand:" << "\n";
	for (auto item = playerTiles.begin(); item != playerTiles.end(); item++)
	{
		cout << (item)->getLeftSide() << "-" << (item)->getRightSide() << " ";
		// Used for testing purposes
		// int index = item - unusedDominos.begin();
		/*if (index > 0 && (index + 1) % 3 == 0)
		{
		cout << "\n";
		}*/
	}
}
