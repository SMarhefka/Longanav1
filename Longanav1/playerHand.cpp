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
void playerHand::addTile(dominoTile tileToAdd)
{
	// pushes back that tile to the end of the vector playerTiles
	playerTiles.push_back(tileToAdd);
}

// this function will be used when a player places their tile on the board
void playerHand::removeTile(dominoTile tileToRemove)
{
	// go through the vector and find the tile that
	// is going to be deleted.  I also need to check
	// check for the reverse verson of the 
	for (auto item = playerTiles.begin(); item != playerTiles.end(); item++)
	{
		cout << "item: " << &item << "\n";
	}

}

vector<dominoTile> playerHand::getPlayerTiles()
{
	return playerTiles;
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
	cout << "\n";
}
