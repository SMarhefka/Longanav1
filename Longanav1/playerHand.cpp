#include "stdafx.h"
#include "playerHand.h"
#include "gameRound.h"
#include <string>

// default constructor
playerHand::playerHand()
{
	//playerTiles.clear();
}

// default destructor
playerHand::~playerHand()
{
}

//void playerHand::addTile()
void playerHand::addTileToHand(dominoTile a_tileToAdd)
{
	// pushes back that tile to the end of the vector playerTiles
	playerTiles.push_back(a_tileToAdd);
}

// this function will be used when a player places their tile on the board
void playerHand::removeTile(dominoTile a_tileToRemove)
{
	// go through the vector and find the tile that
	// is going to be deleted.  I also need to check
	// check for the reverse verson of the

	//auto item = find(playerTiles.begin(), playerTiles.end(), a_tileToRemove);
	//if (item != playerTiles.end())
	//{
	//	playerTiles.erase(item);
	//}

	for (auto item = playerTiles.begin(); item != playerTiles.end(); item++)
	{
		cout << "item: " << item->getLeftSide() << "\n";
		cout << "tile: " << a_tileToRemove.getLeftSide() << "\n";

		if ((item->getLeftSide() == a_tileToRemove.getLeftSide()) && ((item->getRightSide() == a_tileToRemove.getRightSide())))
		{
			playerTiles.erase(item);
			break;
		}
	}

	//for (auto item = playerTiles.begin(); item != playerTiles.end(); item++)
	//{
	//	cout << "item: " << item->getLeftSide() << "\n";
	//	cout << "tile: " << a_tileToRemove.getLeftSide() << "\n";

	//	if ((item->getRightSide() == a_tileToRemove.getLeftSide()) && ((item->getLeftSide() == a_tileToRemove.getRightSide())))
	//	{
	//		playerTiles.erase(item);
	//	}
	//}
}

dominoTile playerHand::getTilesAt(int a_place)
{
	return playerTiles.at(a_place);
}

// Checks to see if the players hand is empty
bool playerHand::isEmpty()
{
	return playerTiles.size() == 0;
}

bool playerHand::hasEngine(int a_inEngine)
{
	for (auto item = playerTiles.begin(); item != playerTiles.end(); item++)
	{
		if ((item->isDouble() && (item->getLeftSide() == a_inEngine)))
		{
			return true;
		}
	}
	return false;
}

// returns the handsize or the number of tiles that 
// the current user has
int playerHand::getHandSize()
{
	return int(playerTiles.size());
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
	cout << "\n";
}
